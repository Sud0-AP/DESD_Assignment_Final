#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define V1

int main(int arg_count, char *argv[]){

	if(arg_count != 3){
		printf("invalid arguments!!\n"
			"usage: ./q2.out <source_file_name> <destination_file_name>\n");
		return 0;
	}
 
	char *source = argv[1];
	char *destination = argv[2];
	

	int fd1 = open(destination, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd1<0){
		printf("error in opening file %s!!\n", source);
		errno = fd1;
		perror("Error: ");
		return 0;
	}
 
	int fd2 = open(source, O_RDONLY);
	if(fd2<0){
		printf("Error in opening file %s!!\n", destination);
		errno = fd2;
		perror("Error: ");
		return 0;
	}
#ifdef V1
	char buffer;
#else
	char *buffer[256] = {0};
#endif
	int ret_1 = 1, ret_2;

	while(ret_1 != 0){
#ifdef V1
		ret_1 = read(fd2, &buffer, 1);
		if(ret_1 < 0){ 
			printf("Error reading file %s\n",source);
			errno = ret_1;
			perror("Error: ");
			return 0;
		}

		ret_2 = write(fd1, &buffer, 1);
		if(ret_2<0){
			printf("Error in writing to file %s\n", destination);
			errno = ret_2;
			perror("Error: ");
			return 0;
		}
#else
		ret_1 = read(fd2, buffer, 256);
		if(ret_1 < 0){ 
			printf("Error reading file %s\n",source);
			errno = ret_1;
			perror("Error: ");
			return 0;
		}

		ret_2 = write(fd1, buffer, 256);
		if(ret_2<0){
			printf("Error in writing to file %s\n", destination);
			errno = ret_2;
			perror("Error: ");
			return 0;
		}
#endif
	}

	printf("File: %s contents succesfully copied to File: %s\n", source, destination);
	
	close(fd1);
	close(fd2);
	
	return 0;
}
