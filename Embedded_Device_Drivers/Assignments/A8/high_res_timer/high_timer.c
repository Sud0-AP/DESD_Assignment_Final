#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>

#define DEVICE_NAME "high_timer_dev"
#define CLASS_NAME "high_timer_class"
#define DEVICE_COUNT 1

static dev_t dev_number;
static struct cdev char_dev;
static struct class *high_timer_class;
static struct hrtimer my_hrtimer;

// Global counter incremented by hrtimer callback
static unsigned int hrtimer_count = 0;

// High-resolution timer callback function
static enum hrtimer_restart hrtimer_callback(struct hrtimer *timer){
	hrtimer_count++;
	pr_info("high_timer: HRTimer expired! Count = %u\n", hrtimer_count);
	
	// Forward timer and restart
	hrtimer_forward_now(&my_hrtimer, ms_to_ktime(500));
	
	return HRTIMER_RESTART;
}

//---------------------------------Open---------------------------------
static int my_open(struct inode *inode, struct file *file){
	pr_info("high_timer: open called\n");
	pr_info("high_timer: Major = %d, Minor = %d\n", imajor(inode), iminor(inode));
	return 0;
}

//---------------------------------Release---------------------------------
static int my_release(struct inode *inode, struct file *file){
	pr_info("high_timer: release called\n");
	return 0;
}

//---------------------------------Read---------------------------------
static ssize_t my_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset){
	char kernel_buffer[50];
	ssize_t bytes_to_read, ret;
	
	// Format the counter value as a string
	snprintf(kernel_buffer, sizeof(kernel_buffer), "hrtimer_count = %u\n", hrtimer_count);
	
	pr_info("high_timer: read called, current count = %u\n", hrtimer_count);
	
	// Only read once per open
	if(*offset >= strlen(kernel_buffer)){
		pr_info("high_timer: End of file reached\n");
		return 0;
	}
	
	bytes_to_read = min(count, (size_t)strlen(kernel_buffer) - *offset);
	
	ret = copy_to_user(user_buffer, kernel_buffer + *offset, bytes_to_read);
	
	if(ret != 0){
		pr_err("high_timer: Failed to copy data to user\n");
		return -EFAULT;
	}
	
	*offset += bytes_to_read;
	pr_info("high_timer: Sent %zu bytes to user\n", bytes_to_read);
	
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
	ktime_t interval;
	
	pr_info("high_timer: Module Loading\n");
	
	// Allocate device number dynamically
	ret = alloc_chrdev_region(&dev_number, 0, DEVICE_COUNT, DEVICE_NAME);
	if(ret < 0){
		pr_err("high_timer: failed to allocate device number\n");
		return ret;
	}
	
	pr_info("high_timer: allocated Major = %d, Minor = %d\n", MAJOR(dev_number), MINOR(dev_number));
	
	// Initialize and add character device
	cdev_init(&char_dev, &fops);
	char_dev.owner = THIS_MODULE;
	
	ret = cdev_add(&char_dev, dev_number, DEVICE_COUNT);
	if(ret < 0){
		pr_err("high_timer: failed to add cdev\n");
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return ret;
	}
	
	// Create device class
	high_timer_class = class_create(THIS_MODULE, CLASS_NAME);
	if(IS_ERR(high_timer_class)){
		pr_err("high_timer: failed to create class\n");
		cdev_del(&char_dev);
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return PTR_ERR(high_timer_class);
	}
	
	// Create device node
	if(IS_ERR(device_create(high_timer_class, NULL, dev_number, NULL, DEVICE_NAME))){
		pr_err("high_timer: failed to create device\n");
		class_destroy(high_timer_class);
		cdev_del(&char_dev);
		unregister_chrdev_region(dev_number, DEVICE_COUNT);
		return -1;
	}
	
	// Setup and start the high-resolution timer
	// Initialize the hrtimer with CLOCK_MONOTONIC in relative mode
	hrtimer_init(&my_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	my_hrtimer.function = hrtimer_callback;
	
	// Set interval to 500 milliseconds
	interval = ms_to_ktime(500);
	
	// Start the hrtimer
	hrtimer_start(&my_hrtimer, interval, HRTIMER_MODE_REL);
	
	pr_info("high_timer: High-resolution timer started! (500 ms interval)\n");
	pr_info("high_timer: Module loaded successfully\n");
	
	return 0;
}

//---------------------------------Module Exit---------------------------------
static void __exit my_exit(void){
	pr_info("high_timer: Module unloading\n");
	
	// Cancel and cleanup hrtimer
	hrtimer_cancel(&my_hrtimer);
	pr_info("high_timer: HRTimer stopped\n");
	
	// Cleanup device
	device_destroy(high_timer_class, dev_number);
	class_destroy(high_timer_class);
	cdev_del(&char_dev);
	unregister_chrdev_region(dev_number, DEVICE_COUNT);
	
	pr_info("high_timer: Module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayan Rahul");
MODULE_DESCRIPTION("High-resolution kernel timer demonstration");
MODULE_VERSION("1.0");
