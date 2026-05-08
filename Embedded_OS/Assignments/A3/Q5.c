//PRN: 260240130005 260240130032
/*Multiple Children with waitpid()

   * Create 3 child processes
   * Each exits at different times
   * Parent handles them using waitpid()
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
	pid_t pid;
	pid_t child_pids[3];
	int stat_loc;
	
	// Create 3 children
	for(int i = 0; i < 3; i++) {
		pid = fork();
		
		if(pid == 0) {
			// Child process
			printf("Child %d: Started (PID: %d)\n", i+1, getpid());
			sleep((i + 1) * 2);
			printf("Child %d: Exiting\n", i+1);
			exit(i+1);
			
		} else if(pid > 0) {
			child_pids[i] = pid;
			
		} else {
			perror("fork");
			exit(EXIT_FAILURE);
		}
	}
	
	// Parent waits for all children using waitpid
	for(int i = 0; i < 3; i++) {
		pid_t wpid = waitpid(child_pids[i], &stat_loc, 0);
		if(wpid > 0 && WIFEXITED(stat_loc)) {
			printf("Parent: Child %d (PID: %d) exited with status %d\n", i+1, wpid, WEXITSTATUS(stat_loc));
		}
	}
	
	printf("Parent: All children completed\n");
	return 0;
} 