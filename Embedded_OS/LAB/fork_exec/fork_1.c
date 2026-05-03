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
		printf("child pid: %d\n",getpid());
	       	printf("child ppid: %d\n",getppid());	
		exit(EXIT_SUCCESS); // telling the parent the exit was successful
	
	} else if (pid == -1) {
		perror("fork err\n");

	} else {
		int stat_loc;
		printf("parent pid: %d\n",getpid());
		printf("parent ppid: %d\n",getppid());
		wait(&stat_loc); // reading the value returned by the child on exit 
		printf("child exit stat: %d\n",stat_loc);
		exit(EXIT_SUCCESS); // telling the shell(parent for this file) the execution was successful

	}
	return 0;
}
