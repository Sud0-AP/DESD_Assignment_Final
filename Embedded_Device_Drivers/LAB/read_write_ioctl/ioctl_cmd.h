#ifndef IOCTL_CMD_H
#define IOCTL_CMD_H

#ifdef __KERNEL__
#include <linux/ioctl.h>
#else
#include <sys/ioctl.h>
#endif

#define MY_IOCTL_MAGIC 'A'
#define MY_IOCTL_RESET _IO(MY_IOCTL_MAGIC, 0) //_IO : command doesn't need any data transfer (magic num, sequence num)
#define MY_IOCTL_SET_VALUE _IOW(MY_IOCTL_MAGIC, 1, int) //_IOW : (kernel pov) move data from user space to kernel space
#define MY_IOCTL_GET_VALUE _IOR(MY_IOCTL_MAGIC, 2, int) //_IOR : (kernel pov) passing information from kernel space to user space
#define MY_IOCTL_TOGGLE_VALUE _IO(MY_IOCTL_MAGIC, 3) //_IOWR : read and write both

#endif
