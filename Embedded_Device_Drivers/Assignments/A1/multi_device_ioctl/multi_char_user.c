#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "ioctl_cmd.h"

#define DEVICE_FILE "/dev/multi_char0" 

int main(){
	int fd;
	char buffer[100];
	ssize_t ret;
	off_t pos;

	to_be_shared user_struct = {0};

	user_struct.int_value = 20;
	strcat(user_struct.char_value , "Hello this string is sent via IOCTL Inside a struct defined in User space");
	user_struct.float_value = 99.99;

	fd = open(DEVICE_FILE, O_RDWR);
	if(fd < 0){
		perror("Open: ");
		return -1;
	}

	printf("Writing \"Hello from user!!!!!\" to the kernel buffer\n");

	ret = write(fd, "Hello from user!!!!!", 20);
	if(ret < 0){
		perror("Read: ");
		close(fd);
		return 0;
	}

	printf("Trying to read before setting read enable\n");
	ret = read(fd, buffer, 20);
	if(ret < 0){
		perror("Read: ");
		close(fd);
		return 0;
	}

	printf("\n----------------DMESG LOGS---------------\n");
	system("dmesg|tail");
	printf("\n-----------------------------------------\n");



	ret = ioctl(fd, MY_IOCTL_ENABLE_READ);
	if(ret != 0){
		perror("IOCTL ENABLE READ: ");
		close(fd);
		return -1;
	}

	lseek(fd, 0, SEEK_SET);


	printf("Reading after setting read enable\n");
	ret = read(fd, buffer, 20);
	if(ret < 0){
		perror("Read: ");
		close(fd);
		return 0;
	}

	printf("\n----------------DMESG LOGS---------------\n");
	system("dmesg|tail");
	printf("\n-----------------------------------------\n");

	printf("Recived : %s\n\n", buffer);



	printf("User_struct at init: \nint_val = %d\nchar_val = %s\nfloat_val = %0.2f\n", user_struct.int_value, user_struct.char_value, user_struct.float_value);

	printf("Getting kernel_struct and copying to user_struct!!\n\n");

	ret = ioctl(fd, MY_IOCTL_GET_VALUE, &user_struct);
	if(ret != 0){
		perror("IOCTL GET: ");
		close(fd);
		return -1;
	}

	printf("User_struct after using Get value: \nint_val = %d\nchar_val = %s\nfloat_val = %0.2f\n", user_struct.int_value, user_struct.char_value, user_struct.float_value);
	
	printf("Changing kernel struct values to 55, \"This is the last change\", 99.66\n");

	user_struct.int_value = 55;
	memset(user_struct.char_value, 0 , sizeof(user_struct.char_value));
	strcpy(user_struct.char_value , "This is the last change");
	user_struct.float_value = 99.66;
	
	ret = ioctl(fd, MY_IOCTL_SET_VALUE, &user_struct);
	if(ret != 0){
		perror("IOCTL SET: ");
		close(fd);
		return -1;
	}

	printf("\n----------------DMESG LOGS---------------\n");
	system("dmesg|tail");
	printf("\n-----------------------------------------\n");

	printf("Getting kernel_struct to see the changes!!\n\n");

	ret = ioctl(fd, MY_IOCTL_GET_VALUE, &user_struct);
	if(ret != 0){
		perror("IOCTL GET: ");
		close(fd);
		return -1;
	}

	printf("Kernel_struct after using Set value: \nint_val = %d\nchar_val = %s\nfloat_val = %0.2f\n", user_struct.int_value, user_struct.char_value, user_struct.float_value);

	
	close(fd);
	return 0;
}
