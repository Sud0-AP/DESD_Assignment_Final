//PRN: 260240130005 260240130032
/*Creating a Child Process
   Write a C program using fork():

   * Parent prints its PID and child PID
   * Child prints its PID and parent PID
   * Verify both processes using ps
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
	pid_t pid;
	
	pid = fork();
	
	if(pid == 0) {
		// This is child process
		printf("Child PID: %d\n", getpid());
		printf("Child Parent PID: %d\n", getppid());
		exit(EXIT_SUCCESS);
		
	} else if(pid > 0) {
		// This is parent process
		printf("Parent PID: %d\n", getpid());
		printf("Parent Child PID: %d\n", pid);
		sleep(1);
		
	} else {
		// Fork failed
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}