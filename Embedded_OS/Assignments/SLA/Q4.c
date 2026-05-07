//Create 2 child processes from a single parent. Child sleep 5 seconds and exits. Child2 sleeps 10 seconds and exits. Handle parent child communication using wait system call so parent doesn't exit before childs terminates (orphan process).

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main() 
{
	pid_t pid_1, pid_2;
	
	pid_1 = fork();
	
	if(pid_1 == 0) {
		printf("Child 1 PID: %d\n", getpid());
		printf("Child 1 PPID: %d\n", getppid());
		sleep(5);
		printf("Child 1 now exiting!!\n");
		exit(EXIT_SUCCESS); // telling the parent the exit was successful
	} else if (pid_1 == -1) {
		perror("fork err\n");

	} else {
		pid_2 = fork();
		if(pid_2 == 0){
			printf("Child 2 PID: %d\n", getpid());
			printf("Child 2 PPID: %d\n", getppid());
			sleep(10);
			printf("Child 2 now exiting!!\n");
			exit(EXIT_SUCCESS); // telling the parent the exit was successful
		}else if(pid_2 > 0 || pid_1 > 0){
			printf("Inside Parent wating for children processes to execute...\n");

			int  child1_exit, child2_exit;
			wait(&child1_exit);
			wait(&child2_exit);
			 
			printf("parent pid: %d\n",getpid());
			printf("Parent now exiting!!\n");
			exit(EXIT_SUCCESS); // telling the shell (parent for this file) the execution was successful
		}	
	}
	return 0;
}
