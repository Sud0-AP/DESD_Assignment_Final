#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/timer.h>
#include <linux/jiffies.h>

#define DEVICE_NAME "low_timer_dev"
#define CLASS_NAME "low_timer_class"
#define DEVICE_COUNT 1

static dev_t dev_number;
static struct cdev char_dev;
static struct class *low_timer_class;
static struct timer_list my_timer;

// Global counter incremented by timer callback
static unsigned int timer_count = 0;

// Timer callback function - runs in interrupt context
static void timer_callback(struct timer_list *timer){
	timer_count++;
	pr_info("low_timer: Timer expired! Count = %u\n", timer_count);
	
	// Re-arm the timer for the next 1 second
	mod_timer(&my_timer, jiffies + msecs_to_jiffies(1000));
}

//---------------------------------Open---------------------------------
static int my_open(struct inode *inode, struct file *file){
	pr_info("low_timer: open called\n");
	pr_info("low_timer: Major = %d, Minor = %d\n", imajor(inode), iminor(inode));
	return 0;
}

//---------------------------------Release---------------------------------
static int my_release(struct inode *inode, struct file *file){
	pr_info("low_timer: release called\n");
	return 0;
}

//---------------------------------Read---------------------------------
static ssize_t my_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset){
	char kernel_buffer[50];
	ssize_t bytes_to_read, ret;
	
	// Format the counter value as a string
	snprintf(kernel_buffer, sizeof(kernel_buffer), "timer_count = %u\n", timer_count);
	
	pr_info("low_timer: read called, current count = %u\n", timer_count);
	
	// Only read once per open
	if(*offset >= strlen(kernel_buffer)){
		pr_info("low_timer: End of file reached\n");
		return 0;
	}
	
	bytes_to_read = min(count, (size_t)strlen(kernel_buffer) - *offset);
	
	ret = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	
	if(ret != 0){
		pr_err("low_timer: Failed to copy data to user\n");
		return -EFAULT;
	}
	
	*offset += bytes_to_read;
	pr_info("low_timer: Sent %zu bytes to user\n", bytes_to_read);
	
	return bytes_to_read;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_release,
	.read = my_read
};

//---------------------------------Module Init---------------------------------
static int __init my_init(void){
	int ret;
	
	pr_info("low_timer: Module Loading\n");
	
	// Allocate device number dynamically
	ret = alloc_chrdev_region(&dev_number, 0, DEVICE_COUNT, DEVICE_NAME);
	if(ret < 0){
		pr_err("low_timer: failed to allocate device number\n");
		return ret;
	}
	
	pr_info("low_timer: allocated Major = %d, Minor = %d\n", MAJOR(dev_number), MINOR(dev_number));
	
	// Initialize and add character device
	cdev_init(&char_dev, &fops);
	char_dev.owner = THIS_MODULE;
	
	ret = cdev_add(&char_dev, dev_number, DEVICE_COUNT);
	if(ret < 0){
		pr_err("low_timer: failed to add cdev\n");
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return ret;
	}
	
	// Create device class
	low_timer_class = class_create(THIS_MODULE, CLASS_NAME);
	if(IS_ERR(low_timer_class)){
		pr_err("low_timer: failed to create class\n");
		cdev_del(&char_dev);
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return PTR_ERR(low_timer_class);
	}
	
	// Create device node
	if(IS_ERR(device_create(low_timer_class, NULL, dev_number, NULL, DEVICE_NAME))){
		pr_err("low_timer: failed to create device\n");
		class_destroy(low_timer_class);
		cdev_del(&char_dev);
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return -1;
	}
	
	// Setup and start the timer
	timer_setup(&my_timer, timer_callback, 0);
	mod_timer(&my_timer, jiffies + msecs_to_jiffies(1000));
	
	pr_info("low_timer: Low-resolution timer started! (1 second interval)\n");
	pr_info("low_timer: Module loaded successfully\n");
	
	return 0;
}

//---------------------------------Module Exit---------------------------------
static void __exit my_exit(void){
	pr_info("low_timer: Module unloading\n");
	
	// Stop and cleanup timer
	del_timer_sync(&my_timer);
	pr_info("low_timer: Timer stopped\n");
	
	// Cleanup device
	device_destroy(low_timer_class, dev_number);
	class_destroy(low_timer_class);
	cdev_del(&char_dev);
	unregister_chrdev_region(dev_number, DEVICE_COUNT);
	
	pr_info("low_timer: Module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayan Rahul");
MODULE_DESCRIPTION("Low-resolution kernel timer demonstration");
MODULE_VERSION("1.0");
