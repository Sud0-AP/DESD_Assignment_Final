#ifndef IOCTL_CMD_H
#define IOCTL_CMD_H

#ifdef __KERNEL__
#include <linux/ioctl.h>
#else
#include <sys/ioctl.h>
#endif

#define STRUCT_CHAR_SIZE 512

typedef struct {
	int int_value;
	char char_value[STRUCT_CHAR_SIZE];
	float float_value;
}to_be_shared;

#define MY_IOCTL_MAGIC 'A'
#define MY_IOCTL_ENABLE_READ _IO(MY_IOCTL_MAGIC, 0) //_IOW : (kernel pov) move data from user space to kernel space

#define MY_IOCTL_DISABLE_READ _IO(MY_IOCTL_MAGIC, 1) //_IOW : (kernel pov) move data from user space to kernel space

#define MY_IOCTL_GET_VALUE _IOR(MY_IOCTL_MAGIC, 2, to_be_shared)

#define MY_IOCTL_SET_VALUE _IOW(MY_IOCTL_MAGIC, 3, to_be_shared)

#endif
