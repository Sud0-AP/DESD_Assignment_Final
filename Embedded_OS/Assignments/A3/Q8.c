//PRN: 260240130005 260240130032
/*Orphan Process

   * Parent exits before child
   * Observe new parent of child
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
		// Child process
		printf("Child: PID=%d, PPID=%d (parent still alive)\n", getpid(), getppid());
		
		// Sleep to let parent exit first
		sleep(3);
		
		// Now parent should have exited, child becomes orphan
		printf("Child: PID=%d, PPID=%d (parent exited, new parent is init/systemd)\n", getpid(), getppid());
		
		exit(EXIT_SUCCESS);
		
	} else if(pid > 0) {
		// Parent process
		printf("Parent: PID=%d, Child PID=%d\n", getpid(), pid);
		printf("Parent: Exiting immediately (child becomes orphan)\n");
		
		exit(EXIT_SUCCESS);
		
	} else {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}