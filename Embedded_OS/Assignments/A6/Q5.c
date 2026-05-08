//PRN: 260240130005 260240130032
//Word Count Using Pipe (wc Simulation)
//Parent reads a file and sends content through a pipe to child. Child counts Lines, Words, Characters and prints output on screen.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

void main() {
    int pipefd[2];
    pid_t pid;
    char buffer[4096];
    int ret;

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe creation failed");
        return;
    }

    pid = fork();

    if (pid > 0) {
        // PARENT PROCESS - Read file and send to pipe
        close(pipefd[0]); // Close read end

        // Open file to read
        FILE *fp = fopen("test_file.txt", "r");
        if (fp == NULL) {
            perror("file open failed");
            close(pipefd[1]);
            return;
        }

        printf("[Parent] Reading file and sending to child...\n");

        // Read file and send content through pipe
        while ((ret = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
            write(pipefd[1], buffer, ret);
        }

        fclose(fp);
        close(pipefd[1]); // Close write end to signal EOF to child

        printf("[Parent] File sent to child. Waiting for child...\n");
        wait(NULL);
        printf("[Parent] Child completed. Parent exiting.\n");

    } else if (pid == 0) {
        // CHILD PROCESS - Count lines, words, characters
        close(pipefd[1]); // Close write end

        int lines = 0, words = 0, chars = 0;
        int in_word = 0;
        int total_read = 0;

        printf("[Child] Receiving content and counting...\n");

        // Read from pipe and count
        while ((ret = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            total_read += ret;

            for (int i = 0; i < ret; i++) {
                chars++;

                if (buffer[i] == '\n') {
                    lines++;
                    in_word = 0;
                } else if (isspace(buffer[i])) {
                    in_word = 0;
                } else {
                    if (!in_word) {
                        words++;
                        in_word = 1;
                    }
                }
            }
        }

        close(pipefd[0]);

        // If last character was not newline, we still need to count the last line
        if (chars > 0 && buffer[ret - 1] != '\n') {
            lines++;
        }

        printf("[Child] Statistics:\n");
        printf("  Lines: %d\n", lines);
        printf("  Words: %d\n", words);
        printf("  Characters: %d\n", chars);
        printf("[Child] Exiting.\n");

        exit(0);

    } else {
        perror("fork failed");
    }
}
