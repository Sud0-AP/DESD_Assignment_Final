//PRN: 260240130005 260240130032
//Parent-Child Synchronization Without wait(). 
//Use pipes instead of wait() to ensure that Parent prints first and then child prints. Demonstrate how pipe communication enforces ordering.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void main() {
    int pipefd[2];
    pid_t pid;
    char buffer[256];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe creation failed");
        return;
    }

    pid = fork();

    if (pid > 0) {
        // PARENT PROCESS
        close(pipefd[0]); // Close read end

        printf("[Parent] Parent is printing first\n");
        printf("[Parent] Parent execution\n");
        printf("[Parent] Parent about to send signal to child\n");

        // Signal to child that parent is done
        char *signal = "DONE";
        write(pipefd[1], signal, strlen(signal));
        close(pipefd[1]);

        printf("[Parent] Parent finished execution and sent signal\n");

        // Parent continues without waiting explicitly
        printf("[Parent] Parent exiting without explicit wait()\n");

    } else if (pid == 0) {
        // CHILD PROCESS
        close(pipefd[1]); // Close write end

        // Wait for parent signal by blocking on read
        printf("[Child] Child waiting for parent signal...\n");
        memset(buffer, 0, sizeof(buffer));
        int ret = read(pipefd[0], buffer, sizeof(buffer));

        if (ret > 0) {
            printf("[Child] Received signal from parent: %s\n", buffer);
        }
        close(pipefd[0]);

        // Now child can proceed
        printf("[Child] Child is printing now (after parent)\n");
        printf("[Child] Child execution\n");
        printf("[Child] Child exiting\n");

        exit(0);

    } else {
        perror("fork failed");
    }
}
