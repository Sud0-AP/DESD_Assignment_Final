//PRN: 260240130005 260240130032
//Bidirectional Communication Using Two Pipes
//Create a parent and child process using fork(). Use two pipes to enable full-duplex communication. The parent sends a string to the child. The child converts it to uppercase and sends it back to the parent. Ensure no deadlock occurs.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

void main() {
    int pipe1[2], pipe2[2]; // pipe1: parent->child, pipe2: child->parent
    pid_t pid;
    char buffer[256];
    int ret;

    // Create first pipe (parent to child)
    if (pipe(pipe1) == -1) {
        perror("pipe1 creation failed");
        return;
    }

    // Create second pipe (child to parent)
    if (pipe(pipe2) == -1) {
        perror("pipe2 creation failed");
        return;
    }

    pid = fork();

    if (pid > 0) {
        // PARENT PROCESS
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        char *message = "hello world";
        printf("[Parent] Sending: %s\n", message);
        
        // Send message to child
        ret = write(pipe1[1], message, strlen(message));
        if (ret == -1) {
            perror("write to pipe1 failed");
        }
        close(pipe1[1]); // Close write end to signal EOF
        
        // Wait for child response
        memset(buffer, 0, sizeof(buffer));
        ret = read(pipe2[0], buffer, sizeof(buffer) - 1);
        if (ret > 0) {
            buffer[ret] = '\0';
            printf("[Parent] Received: %s\n", buffer);
        }
        close(pipe2[0]); // Close read end
        
        wait(NULL); // Wait for child to terminate
        printf("[Parent] Child terminated. Parent exiting.\n");
        
    } else if (pid == 0) {
        // CHILD PROCESS
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        // Read message from parent
        memset(buffer, 0, sizeof(buffer));
        ret = read(pipe1[0], buffer, sizeof(buffer) - 1);
        if (ret > 0) {
            buffer[ret] = '\0';
            printf("[Child] Received: %s\n", buffer);
            
            // Convert to uppercase
            for (int i = 0; buffer[i] != '\0'; i++) {
                buffer[i] = toupper(buffer[i]);
            }
            
            printf("[Child] Converted to: %s\n", buffer);
            
            // Send converted string back to parent
            ret = write(pipe2[1], buffer, strlen(buffer));
            if (ret == -1) {
                perror("write to pipe2 failed");
            }
        }
        close(pipe1[0]); // Close read end
        close(pipe2[1]); // Close write end
        
        printf("[Child] Exiting.\n");
        exit(0);
        
    } else {
        perror("fork failed");
    }
}
