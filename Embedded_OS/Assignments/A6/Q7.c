//PRN: 260240130005 260240130032
//Implement a Simple input and output redirection using dup2 system call.
//Create two child processes. First runs 'ls' command and Second runs 'grep txt'. Run the command ls | grep txt on terminal and see the output. Your program should generate same output. Use pipe(), fork(), and dup2(). No use of system shell (`system()` not allowed)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    int pipefd[2];
    pid_t pid1, pid2;

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe creation failed");
        return;
    }

    // Create first child process - runs 'ls'
    pid1 = fork();

    if (pid1 == 0) {
        // CHILD 1 - Execute 'ls' command
        close(pipefd[0]); // Close read end

        // Redirect stdout to pipe write end
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute ls command
        execlp("ls", "ls", NULL);
        
        // If execlp fails
        perror("execlp ls failed");
        exit(1);

    } else if (pid1 < 0) {
        perror("fork for ls failed");
        return;
    }

    // Create second child process - runs 'grep txt'
    pid2 = fork();

    if (pid2 == 0) {
        // CHILD 2 - Execute 'grep txt' command
        close(pipefd[1]); // Close write end

        // Redirect stdin to pipe read end
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        // Execute grep command
        execlp("grep", "grep", "txt", NULL);
        
        // If execlp fails
        perror("execlp grep failed");
        exit(1);

    } else if (pid2 < 0) {
        perror("fork for grep failed");
        return;
    }

    // PARENT PROCESS - Close both ends of pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both children
    printf("[Parent] Waiting for both children to complete...\n");
    wait(NULL);
    wait(NULL);

    printf("[Parent] Both processes completed. Parent exiting.\n");
}
