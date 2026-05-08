//PRN: 260240130005 260240130032
/*Parent Waiting for Child

   * Child prints numbers from 1 to 5 with delay
   * Parent waits using wait()
   * Observe execution order
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
	pid_t pid;
	int stat_loc;
	
	pid = fork();
	
	if(pid == 0) {
		// This is child process
		for(int i = 1; i <= 5; i++) {
			printf("Child: Number %d\n", i);
			sleep(1);
		}
		printf("Child: Done!\n");
		exit(EXIT_SUCCESS);
		
	} else if(pid > 0) {
		// This is parent process
		printf("Parent: Waiting for child...\n");
		wait(&stat_loc);
		printf("Parent: Child exited with status %d\n", WEXITSTATUS(stat_loc));
		
	} else {
		// Fork failed
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}