//Create a parent and child process. Child sleeps 10 seconds printing ppid every 1 seconds and exit.
//   1. print pid in parent and exit rightaway. parent exits right away. check ps -eaf ppid of child changing after parent exits but child still running.
//   2. Add wait in parent and monitor ppid of child and pid of parent.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define V1 1  // Comment this line to get the 2nd part of the question

int main() 
{
	pid_t pid;
	
	pid = fork();
	
	if(pid == 0) {
		for(int i=0; i<10; i++){ // 10 second sleep and printing pid every 1 second
			printf("child pid: %d\n",getpid());
#ifndef V1
			printf("child ppid: %d\n",getppid());
#endif
			sleep(1);
		}

		printf("Child now exiting!!\n");
#ifndef V1
		exit(EXIT_SUCCESS); // telling the parent the exit was successful
#endif
	} else if (pid == -1) {
		perror("fork err\n");

	} else {
#ifndef V1
		printf("Inside Parent wating ofr child to execute...\n");
		printf("parent pid: %d\n",getpid());
	
		int child_exit;
		wait(&child_exit);
		
		printf("parent pid: %d\n",getpid());
#endif
		printf("Parent now exiting!!\n");
		exit(EXIT_SUCCESS); // telling the shell (parent for this file) the execution was successful
	}
	return 0;
}
