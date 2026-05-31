#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
//Include device model APIs such as class_creat() and device_creat()
#include <linux/device.h>
//Include User kernel copy functions copy_to_user() and copy_from_user()
#include <linux/uaccess.h>
//Include kernel memory allocation functions such as kcalloc() and kfree()
#include <linux/slab.h>
#include <linux/mutex.h>
//Include kernel version macros such as LINUX_VERSION_CODE and KERNEL_VERSION()
#include <linux/version.h>
#include <linux/semaphore.h>

//define the base class while allocating character device number
#define DEVICE_NAME "count_sem"
#define CLASS_NAME "count_sem_class"
#define DEVICE_COUNT 4
#define BUFFER_SIZE 1024
#define NUM_DEVICE_ALLOWED 3

//Define a structure that represents once character device instance
struct multi_char_dev{
	struct cdev cdev; //character device registered with VFS layer
	char buffer[BUFFER_SIZE]; //private kernel buffer for this particular device
	size_t data_size; //Number of valid bytes currently stored in this device buffer
	struct mutex lock; // mutex lock
	int minor; // minor number of this device
};

static dev_t base_dev; //stores first allocated device number. This also contains both major and minor number
static struct class *count_sem_class; //pointer to device class used for automatic /dev node creation.
static struct multi_char_dev *devices;//pointer to dynamically allocated array of device structure

struct semaphore sem;

//---------------------------------Open---------------------------------
static int multi_char_open(struct inode *inode, struct file *file){
	struct multi_char_dev *dev; //declae a pointer to our device specific structure

	//Get the address of the parent structure from cdev pointer.
	//inode->i_cdev points to the cdev of the opened device.
	//container_of() gives the full struct multi_char_dev containing the cdev
	
	dev = container_of(inode->i_cdev, struct multi_char_dev, cdev);

	//store the device pointer inside files->private_dev
	//later read(), write(), release(), lseek() can use this pointer
	
	file->private_data = dev;
	pr_info("count_sem: open called for minor %d\n", dev->minor); //iminor(inode) will give the same minor number
	
	if (down_interruptible(&sem)){
    		return -ERESTARTSYS;
	}

	pr_info("count_sem: Minor %d now active...\n", dev->minor);

	return 0;
}
//---------------------------------Release---------------------------------
static int multi_char_release(struct inode *inode, struct file *file){
	struct multi_char_dev *dev = file->private_data; //get device pointer that was stored during open()
	
	pr_info("count_sem: release called for minor %d\n", dev->minor);

	up(&sem);

	return 0;
}

//---------------------------------Read---------------------------------
static ssize_t multi_char_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset){
	struct multi_char_dev *dev = file->private_data; //get device pointer from file->private_data 
							 //this tells us which minor device is being used
	ssize_t bytes_to_read, ret;
	size_t available;
	mutex_lock(&dev->lock);

	if(*offset >= dev->data_size){
		pr_info("count_sem: inside err 1 offset: %lld, data_size %ld\n",*offset, dev->data_size);
		ret = 0;
		mutex_unlock(&dev->lock);
		return ret;
	}

	available = dev->data_size - (size_t)(*offset);

	bytes_to_read = min(count, available);

	if(copy_to_user(user_buffer, dev->buffer + *offset, bytes_to_read)){
		pr_info("inside err 2\n");
		ret = -EFAULT;
		mutex_unlock(&dev->lock);
		return ret;
	}

	*offset += bytes_to_read;
	ret = bytes_to_read;
	pr_info("count_sem: Sent %zu bytes to user, using minor %d\n", bytes_to_read, dev->minor);

	mutex_unlock(&dev->lock);
	return ret;
}
//---------------------------------Write---------------------------------
static ssize_t multi_char_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset){
	struct multi_char_dev *dev = file->private_data;
	size_t space_left, bytes_to_write;
	ssize_t ret;

	mutex_lock(&dev->lock);

	if(*offset >= BUFFER_SIZE){
		ret = -ENOSPC;
		mutex_unlock(&dev->lock);
		return ret;
	}

	space_left = BUFFER_SIZE - (size_t)(*offset);
	bytes_to_write = min(count, space_left);

	if(copy_from_user(dev->buffer + *offset, user_buffer, bytes_to_write)){
		ret = -EFAULT;
		mutex_unlock(&dev->lock);
		return ret;
	}

	ret = bytes_to_write;
	*offset += bytes_to_write;
	
	dev->data_size = max(dev->data_size, (size_t)(*offset));
	
	if(*offset < BUFFER_SIZE){
		dev->buffer[*offset] = '\0';
	}
	pr_info("count_sem: written %zu bytes to minor %d\n", bytes_to_write, dev->minor);
	
	mutex_unlock(&dev->lock);
	return ret;
}

//---------------------------------lseek---------------------------------
static loff_t multi_char_lseek(struct file *file, loff_t offset, int whence){
	struct multi_char_dev *dev = file->private_data;
	
	loff_t new_pos;
	
	mutex_lock(&dev->lock);

	switch(whence){
		case SEEK_SET:
			new_pos = offset;
			break;
		case SEEK_CUR:
			new_pos = file->f_pos + offset;
			break;
		case SEEK_END:
			new_pos = dev->data_size + offset;
			break;
		default:
			mutex_unlock(&dev->lock);
			return -EINVAL;
	}

	if(new_pos < 0 || new_pos > BUFFER_SIZE){
		mutex_unlock(&dev->lock);
		return -EINVAL;
	}

	file->f_pos = new_pos;
	mutex_unlock(&dev->lock);
	return new_pos;
}

static const struct file_operations multi_char_fops = {
	.owner = THIS_MODULE,
	.open = multi_char_open,
	.release = multi_char_release,
	.read = multi_char_read,
	.write = multi_char_write,
	.llseek = multi_char_lseek
};

static int __init multi_char_init(void){
	int ret, i;
	dev_t dev_num;
	pr_info("count_sem: module init\n");

	ret = alloc_chrdev_region(&base_dev, 0, DEVICE_COUNT, DEVICE_NAME);
	if(ret < 0){
		pr_err("count_sem: failed to allocate number\n");
		return ret;
	}
	pr_info("count_sem: Major number = %d\n", MAJOR(base_dev));

	//check if kernel version is 6.4.0 or newer
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,4,0)
	count_sem_class = class_create(CLASS_NAME);
#else
	count_sem_class = class_create(THIS_MODULE, CLASS_NAME);
#endif
	if(IS_ERR(count_sem_class)){ //check wether class creation failed
		pr_err("count_sem: failed to create class\n");
		ret = PTR_ERR(count_sem_class);

		goto unregister_region;
	}

	devices = kcalloc(DEVICE_COUNT, sizeof(struct multi_char_dev), GFP_KERNEL); //allocate zero-initialized memory for DEVICE_COUNT structure
	if(!devices){
		ret = -ENOMEM;
		goto destroy_class;
	}

	for(i = 0; i<DEVICE_COUNT; i++){//loop throught all minor devices
		dev_num = MKDEV(MAJOR(base_dev), MINOR(base_dev)+i); // create device number using allocated major and minor number i
		
		devices[i].minor = i;				     //store minor number inside device structure
		devices[i].data_size = 0;			     //Initially no valid data present in the buffer
		mutex_init(&devices[i].lock);			     //Initialize mutex lock for this device
		
		cdev_init(&devices[i].cdev, &multi_char_fops);
		devices[i].cdev.owner = THIS_MODULE;

		ret = cdev_add(&devices[i].cdev, dev_num, 1);
		if(ret < 0){
			pr_err("count_sem: cdev_add failed for minor %d\n", i);
			goto cleanup_devices;
		}

		//create /dev/multi_charX device node
		if(IS_ERR(device_create(count_sem_class, NULL, dev_num, NULL, "count_sem%d", i))){
			pr_err("count_sem: device create failed for minor %d\n", i);
			cdev_del(&devices[i].cdev);
			ret = -EINVAL;
			goto cleanup_devices;
		}
		pr_info("count_sem: created /dev/count_sem%d\n", i);
	}

	sema_init(&sem, NUM_DEVICE_ALLOWED);

	return 0;

cleanup_devices:
	while(i-- >= 0){
		dev_num = MKDEV(MAJOR(base_dev), MINOR(base_dev)+i);
		device_destroy(count_sem_class, dev_num);
		cdev_del(&devices[i].cdev);
	}
	kfree(devices);
destroy_class:
	class_destroy(count_sem_class);
unregister_region:
	unregister_chrdev_region(base_dev, DEVICE_COUNT);
	return ret;
}
static void __exit multi_char_exit(void){
	int i;
	dev_t dev_num;
	pr_info("count_sem: module exit\n");

	for(i = 0; i<DEVICE_COUNT; ++i){
		dev_num = MKDEV(MAJOR(base_dev), MINOR(base_dev)+i);
		device_destroy(count_sem_class, dev_num);
		cdev_del(&devices[i].cdev);
		pr_info("count_sem: removed /dev/count_sem%d\n", i);
	}

	kfree(devices);
	class_destroy(count_sem_class);
	unregister_chrdev_region(base_dev, DEVICE_COUNT);
}

module_init(multi_char_init);
module_exit(multi_char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayan Rahul");
MODULE_DESCRIPTION("Limiting number of character device accessing the read function using semaphores\n");
MODULE_VERSION("1.0");
