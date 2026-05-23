#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_FILE "/dev/read_write_lseek"

int main(){
	int fd;
	char buffer[100];
	ssize_t ret;
	off_t pos;

	fd = open(DEVICE_FILE, O_RDWR);
	if(fd < 0){
		perror("Open: ");
		return -1;
	}

	memset(buffer, 0 , sizeof(buffer));
	//SEEK_CUR demonstration
	ret = read(fd, buffer, 20);
	if(ret < 0){
		perror("Failed to read: ");
		close(fd);
		return 0;
	}

	buffer[ret] = '\0';
	printf("Data 1 from driver: %s\n", buffer);

	pos = lseek(fd, 10, SEEK_CUR);
	if(pos < 0){
		perror("lseek SEEK_CUR: ");
		close(fd);
		return 1;
	}
	printf("After SEEK_CUR, position = %ld \n", pos);

	memset(buffer, 0 , sizeof(buffer));

	//SEEK_SET demonstration
	ret = read(fd, buffer, 20);
	if(ret < 0){
		perror("Failed to read: ");
		close(fd);
		return 0;
	}
	buffer[ret] = '\0';
	printf("Data 2 from driver: %s\n", buffer);

	pos = lseek(fd, 7, SEEK_SET);
	if(pos < 0){
		perror("lseek SEEK_SET: ");
		close(fd);
		return 1;
	}
	printf("After SEEK_SET, position = %ld \n", pos);
	
	memset(buffer, 0 , sizeof(buffer));

	//SEEK_END demonstration
	ret = read(fd, buffer, 20);
	if(ret < 0){
		perror("Failed to read: ");
		close(fd);
		return 0;
	}
	buffer[ret] = '\0';
	printf("Data 3 from driver: %s\n", buffer);

	pos = lseek(fd, -10, SEEK_END);
	if(pos < 0){
		perror("lseek SEEK_END: ");
		close(fd);
		return 1;
	}
	printf("After SEEK_END, position = %ld \n", pos);
	memset(buffer, 0 , sizeof(buffer));
	
	ret = read(fd, buffer, 10);
	if(ret < 0){
		perror("Failed to read: ");
		close(fd);
		return 0;
	}
	buffer[ret] = '\0';
	printf("Data 4 from driver: %s\n", buffer);

//	printf("Enter string to put in kernel: ");
//	scanf("%99[^\n]", buffer);
//	
//	ret = write(fd, buffer, strlen(buffer));
//	if(ret < 0){
//		perror("Failed to write: ");
//		close(fd);
//		return 0;
//	}
//	
//	memset(buffer, 0 , sizeof(buffer));

//	ret = read(fd, buffer, sizeof(buffer));
//	if(ret < 0){
//		perror("Failed to read: ");
//		close(fd);
//		return 0;
//	}

//	printf("Data from driver: %s\n", buffer);

	close(fd);
	return 0;
}
