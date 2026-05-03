#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

int main() 
{
	char *file_name = "child_parent_comms.txt";
	
	pid_t pid;
	
	pid = fork();

	if(pid == 0) {

		char buffer[100]= {0};

		int fd = open(file_name, O_RDWR);

		if(fd<0){
			printf("Error in opening file\n");
			return 0;
		}

		int ret_r = read(0, buffer, sizeof(buffer)-1 );
		if (ret_r<0){
			printf("Read failed!!\n");
			return 0;
		}

		int ret_w = write(fd, buffer, ret_r);

		close(fd);

		exit(EXIT_SUCCESS); // telling the parent the exit was successful
	
	} else if (pid == -1) {
		perror("fork err\n");

	} else {
		int child_exit;

		wait(&child_exit);
		
		char buffer[100]= {0};

		int fd = open(file_name, O_RDWR);

		if(fd<0){
			printf("Error in opening file\n");
			return 0;
		}

		int ret_r = read(fd, buffer, sizeof(buffer)-1 );
		if (ret_r<0){
			printf("Read failed!!\n");
			return 0;
		}

		int ret_w = write(1, buffer, ret_r);

		close(fd);

		exit(EXIT_SUCCESS); // telling the shell(parent for this file) the execution was successful

	}
	return 0;
}
