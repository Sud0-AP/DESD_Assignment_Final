#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
	pid_t pid;
	
	pid = fork();
	
	if(pid == 0) {
		sleep(1);
		for(int i=0; i<30; i++){ // 30 second life for child
			printf("child pid: %d\n",getpid());
	       		printf("child ppid: %d\n",getppid());	
			sleep(1);
		}

		printf("Child now exiting!!\n");
	
		exit(EXIT_SUCCESS); // telling the parent the exit was successful
	
	} else if (pid == -1) {
		perror("fork err\n");

	} else {
		printf("parent pid: %d\n",getpid());
		printf("parent ppid: %d\n",getppid());
	
		sleep(10); //10 sec life for parent
		
		printf("Parent now exiting!!\n");
		exit(EXIT_SUCCESS); // telling the shell(parent for this file) the execution was successful

	}
	return 0;
}
