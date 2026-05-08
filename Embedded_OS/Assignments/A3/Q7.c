//PRN: 260240130005 260240130032
/*Zombie Process

   * Child exits immediately
   * Parent delays wait()
   * Observe zombie state using ps
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
		// Child process exits immediately
		printf("Child: PID=%d, Exiting immediately\n", getpid());
		exit(EXIT_SUCCESS);
		
	} else if(pid > 0) {
		// Parent process delays before waiting
		printf("Parent: Child PID=%d created\n", pid);
		printf("Parent: Child is now a zombie, check with: ps aux | grep Z\n");
		printf("Parent: Sleeping for 5 seconds...\n");
		
		sleep(5);
		
		printf("Parent: Now waiting for child...\n");
		wait(&stat_loc);
		printf("Parent: Child cleaned up with status %d\n", WEXITSTATUS(stat_loc));
		
	} else {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}