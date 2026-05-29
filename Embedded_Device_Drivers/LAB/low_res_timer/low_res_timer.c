#include <linux/init.h> 
#include <linux/module.h>
#include <linux/fs.h> 
#include <linux/cdev.h> 
#include <linux/kernel.h>
#include <linux/jiffies.h> // provides jiffies, HZ, msecs_to_jiffies, usec_to_jiffies
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/timer.h> // struct timer_list and kernel timer APIs
#include <linux/atomic.h> //provides atomic operation
#include <linux/string.h>
#include <linux/minmax.h> // provides MIN and MAX macros
#include <linux/compiler.h> //provides READ_ONCE and WRITE_ONCE

#define DRIVER_NAME "timer_lab"
#define DEVICE_NAME "timer_lab"
#define CLASS_NAME "timer_lab_class"
#define CMD_BUF 64 //maximum command size accepted from user

#define TIMER_STOPPED 0
#define TIMER_PERIODIC 1
#define TIMER_ONESHOT 2

static dev_t dev_num;
static struct cdev timer_cdev;
static struct class *timer_class;
static struct device *timer_device;
static struct timer_list lab_timer; // low res timer object

static atomic_t tick_count = ATOMIC_INIT(0); // counts how many times the timer callback is executed
static atomic_t timer_mode = ATOMIC_INIT(TIMER_STOPPED); // store current timer node stopped, periodic or one-shot

static unsigned int period_ms = 1000; //timer period in mili seconds

static unsigned long last_tick_jiffies; //stores jiffies value when timer callback is executed
static unsigned long next_expiry_jiffies; //stores next programmed expiry time in jiffies

static const char * mode_to_string(int mode){ //converts timer mode integer to readable string
	switch(mode){
		case TIMER_STOPPED:
			return "stopped";
		case TIMER_PERIODIC:
			return "periodic";
		case TIMER_ONESHOT:
			return "one_shot";
		default:
			return "unknown";
	}
}

static unsigned long make_entry_from_ms(unsigned int ms){ //convert mili seconds into absolute future jiffies expiry value
	unsigned long delay_jiffies;
	delay_jiffies = msec_to_jiffies(ms);

	if(delay_jiffies == 0){ //saftey check for very small value, this forces atleast 1 jiffies dealy
		delay_jiffies = 1;
	}

	return (jiffies + delay_jiffies);
}

static int my_open(struct inode *inode, struct file* file){
	pr_info("%s: open called\n", DRIVER_NAME);
	return 0;
}
static int my_release(struct inode *inode, struct file* file){
	pr_info("%s: release called\n", DRIVER_NAME);
	return 0;
}

static ssize_t my_read(struct file *file, char __user *buf, size_t len, loff_t *offset){
	char out[256];
	int n, mode, pending; //pending -> stores wheather timer is pending
	unsigned long now, next, last; //now -> stores current jiffies, next-> stores last expiry jiffies, last-> stores last callback jiffies
	unsigned long remaining_ms = 0;

	mode = atomic_read(&timer_mode); // reading timer mode
	pending = timer_pending(&lab_timer);
	now = jiffies; 
	next = READ_ONCE(next_expiry_jiffies);
	last = READ_ONCE(last_expiry_jiffies);

	//check if timer is pending and expiry is in near future
	if(pending && timer_after(next, now)){
		remaining_ms = jiffies_to_ms(next-now);
	}

	n = scnprintf(out, sizeof(out), "mode = %s\n"
					"period %s\n"
					"tick_count = %d\n"
					"timer_pending = %d\n"
					"HZ = %d\n"
					"now_jiffies = %lu\n"
					"remaining_ms = %lu\n"
					"last_tick_jiffies = %lu\n", mode_to_string(mode),
					READ_ONCE(period_ms), atomic_read(&tick_count),
					pending, HZ, now, next, remaining_ms, last);

	return simple_read_from_buffer(buf, len, offset, out, n); //copy formatted kernel buffer to user save and handle file offset carefully
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.release = my_release,
	.read = my_read,
	.write = my_write
}

static int __init my_init(void){
	int ret;
	ret = alloc_chrdev_region(&dev_number, 0, 1, DRIVER_NAME);

	if(ret < 0){
		return ret;
	}

	cdev_init(&timer_cdev, &fops);
	timer_cdev.owner = THIS_MODULE;

	ret = cdev_add(&timer_cdev, dev_number, 1);
	if(ret < 0){
		pr_err("failed to add cdev\n");
		unregister_chrdev_region(dev_number, 1);
		return ret;
	}

	timer_class = class_create(THIS_MODULE, CLASS_NAME);
	if(IS_ERR(timer_class)){
		pr_err("failed to create class\n");
		cdev_del(&timer_cdev);
		unregister_chrdev_region(dev_number, 1);
		return PTR_ERR(timer_class);
	}
	
	timer_setup(&lab_timer, timer_callback, 0);
	timer_device = device_create(timer_class, NULL, dev_number, NULL, DEVICE_NAME);
	if(IS_ERR(timer_device)){
		pr_err("failed to create device\n");
		class_destroy(timer_class);
		cdev_del(&timer_cdev);
		unregister_chrdev_region(dev_number, 1);
		return PTR_ERR(timer_device);
	}

	pr_info("Device created at /dev/%s\n", DEVICE_NAME);
	pr_info("major: %d, minor %d\n", MAJOR(dev_number), MINOR(dev_number));
	pr_info("%s: commands start <ms> oneshot <ms> period <ms> stop reset\n", DRIVER_NAME);

	return 0;
}

static int __exit my_exit(void){
	atomic_set(&timer_mode, TIMER_STOPPED);
	timer_shutdown_sync(&lab_timer);
	device_destroy(timer_class, dev_number);
	class_destroy(timer_class);
	cdev_del(&timer_cdev);
	unregister_chrdev_region(dev_number, 1);
	pr_info("module unloaded\n");
}

module_init(my_init);
module_init(my_exit);
