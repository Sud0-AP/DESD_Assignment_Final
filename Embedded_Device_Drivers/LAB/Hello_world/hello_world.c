#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int __init my_init(void){

	printk(KERN_ALERT"HELLO KERNEL\n");
	return 0;
}

static void __exit my_exit(void){

	printk(KERN_ALERT"GOODBYE, Cruel World\n");
}


module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rahul Ayan");
MODULE_DESCRIPTION("First Kernel Code");
MODULE_VERSION("1.0");

