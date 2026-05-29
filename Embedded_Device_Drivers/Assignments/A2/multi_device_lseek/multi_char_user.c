#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_FILE "/dev/multi_char0" 

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
	char tx_buff[] = "Hello, this is a test to see if the lseek functionality works!!\n";
	memset(buffer, 0 , sizeof(buffer));

	ret = write(fd, tx_buff, sizeof(tx_buff));
	if(ret < 0){
		perror("Failed to write: ");
		close(fd);
		return 0;
	}
	pos = lseek(fd, 0, SEEK_SET);
	if(pos < 0){
		perror("lseek SEEK_SET: ");
		close(fd);
		return 1;
	}
	printf("After SEEK_SET, position = %ld \n", pos);

	memset(buffer, 0 , sizeof(buffer));

	//reading the first 20 bytes then going back to the 10th position
	
	ret = read(fd, buffer, 20);
	if(ret < 0){
		perror("Failed to read: ");
		close(fd);
		return 0;
	}
	buffer[ret] = '\0';
	printf("Data 1 from driver: %s\n", buffer);

	pos = lseek(fd, 10, SEEK_SET);
	if(pos < 0){
		perror("lseek SEEK_SET: ");
		close(fd);
		return 1;
	}
	printf("After SEEK_SET, position = %ld \n", pos);

	memset(buffer, 0 , sizeof(buffer));

	ret = read(fd, buffer, 20);
	if(ret < 0){
		perror("Failed to read: ");
		close(fd);
		return 0;
	}
	buffer[ret] = '\0';
	printf("Data 2 from driver: %s\n", buffer);

/*	pos = lseek(fd, 7, SEEK_SET);
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
*/
	close(fd);
	return 0;
}
