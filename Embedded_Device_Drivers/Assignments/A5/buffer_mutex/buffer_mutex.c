#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>


#define DEVICE_NAME "buffer_mutex"
#define CLASS_NAME "buffer_mutex_class"
#define DEVICE_COUNT 1
#define MAX_BUFF_SIZE 100

static char kernel_buffer[MAX_BUFF_SIZE] = {0};
static dev_t dev_number;
static struct cdev char_dev;
struct mutex buffer_lock;
static struct class *mutex_buff_class;

static int my_open(struct inode *inode, struct file *file){

	pr_info("Character device demo:\n");
	pr_info("Major = %d, Minor = %d\n", imajor(inode), iminor(inode));
	return 0;
}

static int my_release(struct inode *inode, struct file *file){

	pr_info("Released Called.\n");
	return 0;
}

static ssize_t my_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset){
	int bytes_to_read, ret;

	mutex_lock(&buffer_lock);
	pr_info("Read function called\n");
	if(*offset >= strlen(kernel_buffer)){
		pr_info("End of file reached\n");
		mutex_unlock(&buffer_lock);
		return 0;
	}

	bytes_to_read = min(count, strlen(kernel_buffer) - (size_t) *offset);

	ret = copy_to_user(user_buffer, kernel_buffer+(*offset), bytes_to_read);

	if(ret != 0){
		pr_err("Failed to copy data to user");
		mutex_unlock(&buffer_lock);
		return -EFAULT;
	}

	*offset = *offset + bytes_to_read;
	pr_info("Sent %d bytes to user\n", bytes_to_read);
	
	mutex_unlock(&buffer_lock);
	
	return bytes_to_read;
}

static ssize_t my_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset){
	int bytes_to_write, ret;

	mutex_lock(&buffer_lock);
	pr_info("write function called\n");
	if(*offset >= MAX_BUFF_SIZE-1){
		pr_info("End of file reached\n");
		mutex_unlock(&buffer_lock);
		return -ENOSPC;
	}

	bytes_to_write = min(count, (MAX_BUFF_SIZE-1) - (size_t) *offset);

	ret = copy_from_user(kernel_buffer+(*offset), user_buffer, bytes_to_write);
	if(ret != 0){
		pr_err("Failed to copy data from user");
		mutex_unlock(&buffer_lock);
		return -EFAULT;
	}

	*offset = *offset + bytes_to_write;
	kernel_buffer[*offset] = '\0';
	
	pr_info("Recived %d bytes from user\n", bytes_to_write);
	pr_info("String recived from user: %s\n", kernel_buffer);
	
	mutex_unlock(&buffer_lock);
	
	return bytes_to_write;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_release,
	.read = my_read,
	.write = my_write
};


static int __init my_init(void){
	int ret;
	pr_info("Character Module Loading\n");
	
	ret = alloc_chrdev_region(&dev_number, 0, DEVICE_COUNT, DEVICE_NAME);

	if(ret < 0){
		pr_err("buffer_mutex: failed to allocate device number\n");
		return ret;
	}

	pr_info("buffer_mutex: allocated Major = %d: Minor = %d\n", MAJOR(dev_number), MINOR(dev_number));

	cdev_init(&char_dev, &fops);
	char_dev.owner = THIS_MODULE;

	mutex_init(&buffer_lock);

	ret = cdev_add(&char_dev, dev_number, DEVICE_COUNT);
	if(ret < 0){
		pr_err("buffer_mutex: failed to add cdev\n");
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return ret;
	}
	
	mutex_buff_class = class_create(THIS_MODULE, CLASS_NAME);

	if(IS_ERR(mutex_buff_class)){
		pr_err("buffer_mutex: failed to create class\n");
		cdev_del(&char_dev);
		unregister_chrdev_region(dev_number, 1);
		return PTR_ERR(mutex_buff_class);
	}

	if(IS_ERR(device_create(mutex_buff_class, NULL, dev_number, NULL, DEVICE_NAME))){
		pr_err("buffer_mutex: failed to create device\n");
		class_destroy(mutex_buff_class);
		cdev_del(&char_dev);
		unregister_chrdev_region(dev_number, 1);
		return -1;
	}
	
	pr_info("buffer_mutex: cdev added succesfully\n");
	return 0;
}

static void __exit my_exit(void){

	pr_info("buffer_mutex: module unloading\n");

	cdev_del(&char_dev);
	unregister_chrdev_region(dev_number, DEVICE_COUNT);
	pr_info("buffer_mutex: module unloaded.\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayan, Rahul");
MODULE_DESCRIPTION("Buffer read write protection using mutex");
MODULE_VERSION("1.0");

