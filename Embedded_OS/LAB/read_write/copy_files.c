#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int arg_count, char *argv[]){

	if(arg_count != 3){
		printf("Invalid arguments!!\n");
		return 0;
	}
 
	char *source = argv[1];
	char *destination = argv[2];
	

	int fd1 = open(destination, O_WRONLY | O_APPEND | O_CREAT);
	if(fd1<0){ 
		printf("Error in opening file %s!!\n",source);
		return 0;
	}
 
	int fd2 = open(source, O_RDONLY);
	if(fd2<0){
		printf("Error in opening file %s!!\n", destination);
		return 0;
	}

	char buff;
	int ret_1 = 1, ret_2;
	while(ret_1 != 0){
		ret_1 = read(fd2, &buff, 1);
		if(ret_1 < 0){ 
			printf("Error reading file %s\n",source);
			return 0;
		}

		ret_2 = write(fd1, &buff, 1);
		if(ret_2<0){
			printf("Error in writing to file %s\n", destination);
			return 0;
		}
	}

	printf("File: %s contents succesfully copied to File: %s\n", source, destination);
	
	close(fd1);
	close(fd2);
	
	return 0;
}
