//PRN: 260240130005 260240130032
/*Process Tree Creation

   * Create hierarchy: Parent → Child1 → Grandchild, Parent → Child2
   * Display PIDs and PPIDs
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
	
	printf("Parent: PID=%d, PPID=%d\n", getpid(), getppid());
	
	// Create first child
	pid = fork();
	
	if(pid == 0) {
		// Child 1
		printf("Child1: PID=%d, PPID=%d\n", getpid(), getppid());
		
		// Child1 creates grandchild
		pid_t pid2 = fork();
		
		if(pid2 == 0) {
			// Grandchild
			printf("Grandchild: PID=%d, PPID=%d\n", getpid(), getppid());
			sleep(2);
			exit(EXIT_SUCCESS);
			
		} else if(pid2 > 0) {
			wait(&stat_loc);
			printf("Child1: Grandchild completed\n");
			sleep(1);
			exit(EXIT_SUCCESS);
		}
		
	} else if(pid > 0) {
		// Parent creates second child
		pid_t pid3 = fork();
		
		if(pid3 == 0) {
			// Child 2
			printf("Child2: PID=%d, PPID=%d\n", getpid(), getppid());
			sleep(1);
			exit(EXIT_SUCCESS);
			
		} else if(pid3 > 0) {
			waitpid(pid, &stat_loc, 0);
			waitpid(pid3, &stat_loc, 0);
			printf("Parent: All children completed\n");
		}
	}
	
	return 0;
}