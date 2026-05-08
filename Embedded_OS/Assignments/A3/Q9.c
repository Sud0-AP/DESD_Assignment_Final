//PRN: 260240130005 260240130032
/*Parallel exec() Tasks

   * Multiple children execute commands like date, who, pwd
   * Parent waits for all
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
	pid_t pid1, pid2, pid3;
	int stat_loc;
	
	// First child - execute date
	pid1 = fork();
	if(pid1 == 0) {
		printf("Child1: Executing 'date'\n");
		execl("/bin/date", "date", NULL);
		perror("execl date");
		exit(EXIT_FAILURE);
	}
	
	// Second child - execute who
	pid2 = fork();
	if(pid2 == 0) {
		printf("Child2: Executing 'who'\n");
		execl("/usr/bin/who", "who", NULL);
		perror("execl who");
		exit(EXIT_FAILURE);
	}
	
	// Third child - execute pwd
	pid3 = fork();
	if(pid3 == 0) {
		printf("Child3: Executing 'pwd'\n");
		execl("/bin/pwd", "pwd", NULL);
		perror("execl pwd");
		exit(EXIT_FAILURE);
	}
	
	// Parent waits for all children
	printf("Parent: Waiting for all children...\n");
	waitpid(pid1, &stat_loc, 0);
	waitpid(pid2, &stat_loc, 0);
	waitpid(pid3, &stat_loc, 0);
	printf("Parent: All children completed\n");
	
	return 0;
}