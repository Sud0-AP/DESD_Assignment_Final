#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "ioctl_cmd.h"

#define DEVICE_FILE "/dev/read_write_ioctl"

int main(){
	int fd;
	ssize_t ret;

	fd = open(DEVICE_FILE, O_RDWR);
	if(fd < 0){
		perror("Open: ");
		return -1;
	}

	int get_val;
	ret = ioctl(fd, MY_IOCTL_GET_VALUE, &get_val);
	if(ret != 0){
		perror("IOCTL GET: ");
		close(fd);
		return -1;
	}

	printf("Got value %d from kernel\n", get_val);
	
	if(get_val){
		printf("Resetting the value\n");
		ret = ioctl(fd,MY_IOCTL_RESET);
		if(ret != 0){
			perror("IOCTL RESET: ");
			close(fd);
			return -1;
		}
	}
	else{
		printf("Setting the value to 1\n");
		int set_val = 1;
		ret = ioctl(fd, MY_IOCTL_SET_VALUE, &set_val);
		if(ret != 0){
			perror("IOCTL SET: ");
			close(fd);
			return -1;
		}
	}

	printf("toggling for vibes:\n");

	ret = ioctl(fd, MY_IOCTL_TOGGLE_VALUE);
	if(ret != 0){
		perror("IOCTL TOGGLE: ");
		close(fd);
		return -1;
	}

	ret = ioctl(fd, MY_IOCTL_GET_VALUE, &get_val);
	if(ret != 0){
		perror("IOCTL GET: ");
		close(fd);
		return -1;
	}

	printf("Got value %d from kernel\n", get_val);

	close(fd);
	return 0;
}
