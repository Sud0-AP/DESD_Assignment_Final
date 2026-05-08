//PRN: 260240130005 260240130032
/*Using exec()

   * Child executes "ls -l" using exec()
   * Parent waits for completion
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
		printf("Child: Executing 'ls -l'\n");
		execl("/bin/ls", "ls", "-l", NULL);
		// If execl fails
		perror("execl");
		exit(EXIT_FAILURE);
		
	} else if(pid > 0) {
		// This is parent process
		printf("Parent: Waiting for child...\n");
		wait(&stat_loc);
		printf("Parent: Child completed\n");
		
	} else {
		// Fork failed
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}