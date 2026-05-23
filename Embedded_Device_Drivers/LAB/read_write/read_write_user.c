#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd, ret;
	char buffer[100];

	fd = open("/dev/read_write", O_RDWR);

	if(fd < 0){
		perror("Open: ");
		return -1;
	}

	ret = read(fd, buffer, sizeof(buffer));
	if(ret < 0){
		perror("Failed to read: ");
		close(fd);
		return 0;
	}

	printf("Data from driver:\n%s\n", buffer);

	memset(buffer, 0 , sizeof(buffer));

	printf("Enter string to put in kernel: ");
	scanf("%99[^\n]", buffer);
	
	ret = write(fd, buffer, strlen(buffer));
	if(ret < 0){
		perror("Failed to write: ");
		close(fd);
		return 0;
	}
	
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
