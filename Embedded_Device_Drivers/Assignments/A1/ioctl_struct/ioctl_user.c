#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "ioctl_cmd.h"

#define DEVICE_FILE "/dev/read_write_ioctl"

typedef struct{
	int value;
}to_be_sent;

int main(){
	int fd;
	ssize_t ret;
	to_be_sent get_struct;

	fd = open(DEVICE_FILE, O_RDWR);
	if(fd < 0){
		perror("Open: ");
		return -1;
	}

	int get_val;
	ret = ioctl(fd, MY_IOCTL_GET_VALUE, &get_struct);
	if(ret != 0){
		perror("IOCTL GET: ");
		close(fd);
		return -1;
	}

	printf("Got value %d from kernel\n", get_struct.value);
	
	close(fd);
	return 0;
}
