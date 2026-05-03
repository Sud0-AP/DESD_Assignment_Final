#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
	char buffer[1024] = {0};
	int fd = open("file.txt", O_RDWR), ret = 1;

	if(fd<0){
		printf("Error in opening file\n");
		return 0;
	}

	ret = read(fd, buffer, 1024);

//	while(ret>0){
//		ret = read(fd, buffer, 1);
//	}

	if(ret<0){
		printf("Error in reading file contents!\n");
		return 0;
	}

	ret = write(1, buffer, strlen(buffer));
	if(ret<0){
		printf("Error in printing file contents!\n");
		return 0;
	}

	close(fd);
}
