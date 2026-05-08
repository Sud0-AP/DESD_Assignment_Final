//PRN: 260240130005 260240130032
/*Using exit() Status

   * Child exits with status 5 using exit(5)
   * Parent retrieves exit status using wait()
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
		printf("Child: Exiting with status 5\n");
		exit(5);
		
	} else if(pid > 0) {
		// This is parent process
		printf("Parent: Waiting for child...\n");
		wait(&stat_loc);
		if(WIFEXITED(stat_loc)) {
			printf("Parent: Child exit status = %d\n", WEXITSTATUS(stat_loc));
		}
		
	} else {
		// Fork failed
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}