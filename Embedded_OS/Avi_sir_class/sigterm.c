#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


void handle_sigterm(int sig) {
	printf("SIG TERM received to process : %d\n",  getpid());
	exit(EXIT_SUCCESS);	

}
void main() {
	pid_t child_pid = fork();
	
	signal(SIGTERM, handle_sigterm);

	if (child_pid == 0) {
    		
		// Child Process
    		while(1) {
        		printf("Child: Working...%d\n", getpid());
        		sleep(1);
    		}

	} else {

    		// Parent Process
    		sleep(3);
    		printf("Parent: Time's up, Child terminate now\n");
    		kill(child_pid, SIGTERM); // Sending signal to child
		wait(NULL);

	}
}
