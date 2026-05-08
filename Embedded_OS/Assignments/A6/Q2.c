//PRN: 260240130005 260240130032
//Chain of Processes (Pipeline Simulation)
//Simulate a shell-like pipeline. Process1 → Process2 → Process3
//Use multiple fork() and pipe() calls. Pass an integer from Process1 to Process2, which squares the number and sends it to Process3, which adds 10 to it and prints it on the screen. Avoid using temporary files.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void main() {
    int pipe1[2], pipe2[2]; // pipe1: P1->P2, pipe2: P2->P3
    pid_t pid1, pid2, pid3;

    // Create pipes
    if (pipe(pipe1) == -1) {
        perror("pipe1 creation failed");
        return;
    }
    if (pipe(pipe2) == -1) {
        perror("pipe2 creation failed");
        return;
    }

    // Create Process 1
    pid1 = fork();
    if (pid1 == 0) {
        // PROCESS 1 - Generate number and send to P2
        close(pipe1[0]); // Close read end
        close(pipe2[0]);
        close(pipe2[1]);

        int num = 5;
        printf("[Process 1] Generated number: %d\n", num);
        write(pipe1[1], &num, sizeof(int));
        close(pipe1[1]);
        exit(0);
    }

    // Create Process 2
    pid2 = fork();
    if (pid2 == 0) {
        // PROCESS 2 - Square the number and send to P3
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        int num;
        read(pipe1[0], &num, sizeof(int));
        close(pipe1[0]);

        int squared = num * num;
        printf("[Process 2] Received: %d, Squared: %d\n", num, squared);
        write(pipe2[1], &squared, sizeof(int));
        close(pipe2[1]);
        exit(0);
    }

    // Create Process 3
    pid3 = fork();
    if (pid3 == 0) {
        // PROCESS 3 - Add 10 to number and print
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]); // Close write end of pipe2

        int num;
        read(pipe2[0], &num, sizeof(int));
        close(pipe2[0]);

        int result = num + 10;
        printf("[Process 3] Received: %d, Added 10: %d\n", num, result);
        printf("[Final Result] %d\n", result);
        exit(0);
    }

    // PARENT PROCESS - Close all pipes and wait
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("[Parent] All processes completed. Parent exiting.\n");
}