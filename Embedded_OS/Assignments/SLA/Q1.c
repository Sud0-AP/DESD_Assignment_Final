#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define V1 1

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Invalid arguments!!\n"
			"Usage: ./Q1.out <file_name>\n");
		return 0;
	}

#ifdef V1
	char buffer;
#else
	char buffer[256] = {0};
#endif

	int fd = open(argv[1], O_RDONLY | S_IRUSR), ret_r = 1, ret_w = 1;

	if(fd<0){
		printf("Error in opening file\n");
		return 0;
	}

	while(ret_r != 0){
#ifdef V1
		ret_r = read(fd, &buffer, 1);
		ret_w = write(1, &buffer, ret_r);
		if(ret_w < 0){
			printf("Error in printing file contents!\n");
			return 0;
		}
#else
		ret_r = read(fd, buffer, 256);
		ret_w = write(1, buffer, ret_r);
		if(ret_w < 0){
			printf("Error in printing file contents!\n");
			return 0;
		}
#endif
	}

	close(fd);
}
