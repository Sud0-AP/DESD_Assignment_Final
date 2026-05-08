//PRN: 260240130005 260240130032
/*Mini Shell
* Accept user commands
* Execute using fork() + exec()
* Support background execution using &
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() 
{
	char command[BUFFER_SIZE];
	char *args[64];
	pid_t pid;
	int stat_loc;
	int background = 0;
	int arg_count;
	
	while(1) {
		printf("shell> ");
		fflush(stdout);
		
		if(fgets(command, BUFFER_SIZE, stdin) == NULL) {
			break;
		}
		
		// Remove newline
		command[strcspn(command, "\n")] = 0;
		
		// Skip empty commands
		if(strlen(command) == 0) {
			continue;
		}
		
		// Check for exit command
		if(strcmp(command, "exit") == 0) {
			printf("Exiting shell...\n");
			break;
		}
		
		// Parse command and arguments
		arg_count = 0;
		background = 0;
		char *token = strtok(command, " ");
		
		while(token != NULL && arg_count < 63) {
			if(strcmp(token, "&") == 0) {
				background = 1;
			} else {
				args[arg_count++] = token;
			}
			token = strtok(NULL, " ");
		}
		
		args[arg_count] = NULL;
		
		// Fork and execute
		pid = fork();
		
		if(pid == 0) {
			// Child process
			execvp(args[0], args);
			// If execvp fails
			perror("execvp");
			exit(EXIT_FAILURE);
			
		} else if(pid > 0) {
			// Parent process
			if(background == 0) {
				// Foreground: wait for child
				waitpid(pid, &stat_loc, 0);
			} else {
				// Background: don't wait
				printf("[Background] Process PID: %d\n", pid);
			}
			
		} else {
			perror("fork");
		}
	}
	
	return 0;
}