#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "char_demo"
#define DEVICE_COUNT 1
#define DEVICE_SIZE (sizeof(kernel_buffer) - 1)
#define MAX_BUFF_SIZE 100

static char kernel_buffer[] = "Hello everyone, My name is Ayan Panchariya. Welcome to Linux device driver class\n";
static char kernel_buffer1[MAX_BUFF_SIZE] = {0};
static dev_t dev_number;
static struct cdev char_dev;

static loff_t my_lseek(struct file *flip, loff_t offset, int whence){

	loff_t new_pos;

	switch(whence){
		case SEEK_SET:
			new_pos = offset;
			break;
		case SEEK_CUR:
			new_pos = (flip->f_pos)+offset;
			break;
		case SEEK_END:
			new_pos = DEVICE_SIZE + offset;
			break;
		default:
			return -EINVAL;
	}

	if(new_pos < 0 || new_pos > DEVICE_SIZE){
		return -EINVAL;
	}

	flip->f_pos = new_pos;

	pr_info("lseek_char : new file position %lld\n", new_pos);
	return new_pos;
}

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

	pr_info("Read function called\n");
	if(*offset >= strlen(kernel_buffer)){
		pr_info("End of file reached\n");
		return 0;
	}

	bytes_to_read = min(count, (size_t)DEVICE_SIZE - *offset);

	ret = copy_to_user(user_buffer, kernel_buffer+(*offset), bytes_to_read); 

	if(ret != 0){
		pr_err("Failed to copy data to user");
		return -EFAULT;
	}

	*offset = *offset + bytes_to_read;
	pr_info("Sent %d bytes to user\n", bytes_to_read);
	return bytes_to_read;
}

static ssize_t my_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset){
	int bytes_to_write, ret;

	pr_info("write function called\n");
	if(*offset >= MAX_BUFF_SIZE-1){
		pr_info("End of file reached\n");
		return -ENOSPC;
	}

	bytes_to_write = min(count, (MAX_BUFF_SIZE-1) - (size_t) *offset);

	ret = copy_from_user(kernel_buffer1+(*offset), user_buffer, bytes_to_write); 
	if(ret != 0){
		pr_err("Failed to copy data from user");
		return -EFAULT;
	}

	*offset = *offset + bytes_to_write;
	kernel_buffer1[*offset] = '\0';
	
	pr_info("Recived %d bytes from user\n", bytes_to_write);
	pr_info("String recived from user: %s\n", kernel_buffer1);
	
	return bytes_to_write;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_release,
	.read = my_read,
	.write = my_write,
	.llseek = my_lseek
};


static int __init my_init(void){
	int ret;
	pr_info("Character Module Loading\n");
	
	ret = alloc_chrdev_region(&dev_number, 0, DEVICE_COUNT, DEVICE_NAME);

	if(ret < 0){
		pr_err("char_demo: failed to allocate device number\n");
		return ret;
	}

	pr_info("char_demo: allocated Major = %d: Minor = %d\n", MAJOR(dev_number), MINOR(dev_number));

	cdev_init(&char_dev, &fops);
	char_dev.owner = THIS_MODULE;
	ret = cdev_add(&char_dev, dev_number, DEVICE_COUNT);
	if(ret < 0){
		pr_err("char_demo: failed to add cdev\n");
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return ret;
	}
	pr_info("char_demo: cdev added succesfully\n");
	return 0;
}

static void __exit my_exit(void){

	pr_info("char_demo: module unloading\n");

	cdev_del(&char_dev);
	unregister_chrdev_region(dev_number, DEVICE_COUNT);
	pr_info("char_demo: module unloaded.\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayan, Rahul");
MODULE_DESCRIPTION("Character device demo");
MODULE_VERSION("1.0");
