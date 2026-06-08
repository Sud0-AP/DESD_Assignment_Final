#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/version.h>

#define PROC_NAME "hello_proc"
#define BUFFER_SIZE 128

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AI Collaborator");
MODULE_DESCRIPTION("A basic Linux kernel module demonstrating procfs APIs");
MODULE_VERSION("1.0");

static char kernel_buffer[BUFFER_SIZE] = "Hello from the Kernel!\n";
//static unsigned long buffer_pointer = 0;

/* * This function is called when the /proc file is read.
 * It copies data from the kernel buffer to the user buffer.
 */
static ssize_t proc_read(struct file *file, char __user *user_buffer, size_t count, loff_t *pos) {
    size_t len = strlen(kernel_buffer);

    // If the user has already read all the data, return 0 (EOF)
    if (*pos >= len) {
        return 0;
    }

    // Adjust count if the user requests more bytes than available
    if (count > len - *pos) {
        count = len - *pos;
    }

    // copy_to_user transfers data from kernel space to user space safely
    if (copy_to_user(user_buffer, kernel_buffer + *pos, count)) {
        return -EFAULT;
    }

    // Update the file position pointer
    *pos += count;

    pr_info("proc_read: Read %zu bytes\n", count);
    return count;
}

/* * This function is called when data is written to the /proc file.
 * It copies data from the user buffer into the kernel buffer.
 */
static ssize_t proc_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *pos) {
    // Prevent buffer overflow
    if (count >= BUFFER_SIZE) {
        count = BUFFER_SIZE - 1;
    }

    // copy_from_user transfers data from user space to kernel space safely
    if (copy_from_user(kernel_buffer, user_buffer, count)) {
        return -EFAULT;
    }

    // Null-terminate the string received from user space
    kernel_buffer[count] = '\0';
    
    pr_info("proc_write: Written %zu bytes\n", count);
    return count;
}

/* * Map the read and write functions to the proc_ops structure.
 * Note: Prior to Linux Kernel 5.6, 'file_operations' was used instead of 'proc_ops'.
 */
static const struct proc_ops proc_fops = {
    .proc_read = proc_read,
    .proc_write = proc_write,
};

/* * Module Initialization Function
 */
static int __init proc_init(void) {
    // Create the proc entry under /proc/
    // Arguments: Name, Permissions (0666 allows read/write for all), Parent dir (NULL for /proc), proc_ops
    if (!proc_create(PROC_NAME, 0666, NULL, &proc_fops)) {
        pr_err("Error creating proc entry /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }
    
    pr_info("/proc/%s created successfully\n", PROC_NAME);
    return 0;
}

/* * Module Exit Function
 */
static void __exit proc_cleanup(void) {
    // Remove the proc entry to prevent memory leaks and dangling pointers
    remove_proc_entry(PROC_NAME, NULL);
    pr_info("/proc/%s removed successfully\n", PROC_NAME);
}

module_init(proc_init);
module_exit(proc_cleanup);
