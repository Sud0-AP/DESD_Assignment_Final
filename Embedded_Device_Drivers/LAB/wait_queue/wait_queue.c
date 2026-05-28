#include <linux/init.h> 
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h> //task states and scheduling
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/fs.h> 
#include <linux/cdev.h> 
#include <linux/wait.h> // wait queue APIs

#define DEVICE_NAME "wq_demo"
#define CLASS_NAME "wq_class"
#define DEVICE_COUNT 1
#define BUFF_SIZE 100

static dev_t dev_number;
static struct cdev wq_cdev;
static struct class *wq_class;
static char device_buffer[BUFF_SIZE];
static int data_available = 0; 

static DECLARE_WAIT_QUEUE_HEAD(wq);


static int wq_open(struct inode *inode, struct file *file){

	pr_info("wq_demo: open() called\n");
	return 0;
}

static int wq_release(struct inode *inode, struct file *file){

	pr_info("wq_demo: release() called.\n");
	return 0;
}



static ssize_t wq_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset){
	int bytes_to_read, ret;

	pr_info("wq_demo: read function called\n");

	// if data_available == 0, the process sleeps here.
	// The process wakes up when:
	// 	1. wake_up_interruptible(&wq) is called
	// 	2. data available becomes non-zero
	// 	3. signal interrups the sleep

	if(wait_event_interruptible(wq, data_available) != 0){
		pr_info("wq_demo: read interrupted by signal\n");
		return -1;
	}

	//when data is available, the process will wake up

	if(*offset >= strlen(device_buffer)){
		pr_info("End of file reached\n");
		return 0;
	}

	bytes_to_read = min(count, strlen(device_buffer) - (size_t) *offset);

	ret = copy_to_user(user_buffer, device_buffer + (*offset), bytes_to_read); 

	if(ret != 0){
		pr_err("Failed to copy data to user");
		return -EFAULT;
	}

	data_available = 0;

	*offset = *offset + bytes_to_read;
	
	pr_info("wq_demo: sent %d bytes to user\n", bytes_to_read);
	
	return bytes_to_read;
}

static ssize_t wq_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset){
	int bytes_to_write, ret;

	pr_info("wq_demo: write function called\n");

	if(*offset >= BUFF_SIZE-1){
		pr_info("End of file reached\n");
		return -ENOSPC;
	}

	bytes_to_write = min(count, (BUFF_SIZE-1) - (size_t) *offset);

	memset(device_buffer, 0 , BUFF_SIZE);

	ret = copy_from_user(device_buffer+(*offset), user_buffer, bytes_to_write); 
	if(ret != 0){
		pr_err("wq_demo: Failed to copy data from user");
		return -EFAULT;
	}

	*offset = *offset + bytes_to_write;
	device_buffer[*offset] = '\0';
	
	pr_info("Recived %d bytes from user\n", bytes_to_write);
	pr_info("String recived from user: %s\n", device_buffer);
	
	data_available = 1;
	wake_up_interruptible(&wq);
	
	return bytes_to_write;
}

static const struct file_operations wq_fops = {
	.owner = THIS_MODULE,
	.open = wq_open,
	.release = wq_release,
	.read = wq_read,
	.write = wq_write
};

static int __init wq_driver_init(void){
	int ret;

	pr_info("wq_demo: module loaded\n");
	ret = alloc_chrdev_region(&dev_number, 0 ,1, DEVICE_NAME);
	if(ret<0){
		pr_err("wq_demo: failed to allocate device number\n");
		return ret;
	}
	pr_info("wq_demo: major = %d, minor = %d\n", MAJOR(dev_number), MINOR(dev_number));

	cdev_init(&wq_cdev, &wq_fops);

	ret = cdev_add(&wq_cdev, dev_number, 1);
	if(ret < 0){
		pr_err("wq_demo: failed to add cdev\n");
		unregister_chrdev_region(dev_number, 1);
		return ret;
	}

	wq_class = class_create(THIS_MODULE, CLASS_NAME);

	if(IS_ERR(wq_class)){
		pr_err("wq_demo: failed to create class\n");
		cdev_del(&wq_cdev);
		unregister_chrdev_region(dev_number, 1);
		return PTR_ERR(wq_class);
	}

	if(IS_ERR(device_create(wq_class, NULL, dev_number, NULL, DEVICE_NAME))){
		pr_err("wq_demo: failed to create device\n");
		class_destroy(wq_class);
		cdev_del(&wq_cdev);
		unregister_chrdev_region(dev_number, 1);
		return -1;
	}

	pr_info("wq_demo: device created at /dev/%s\n", DEVICE_NAME);
	return 0;
}

static void __exit wq_driver_exit(void){
	device_destroy(wq_class, dev_number);
	class_destroy(wq_class);
	cdev_del(&wq_cdev);
	unregister_chrdev_region(dev_number, 1);
	pr_info("wq_demo: module unloaded\n");
}


module_init(wq_driver_init);
module_exit(wq_driver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayan Rahul");
MODULE_DESCRIPTION("Write Queue demo using read and write\n");
MODULE_VERSION("1.0");
