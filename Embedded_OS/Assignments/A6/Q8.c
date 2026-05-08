//PRN: 260240130005 260240130032
//Multiple Writers to a Single Pipe
//Create multiple child processes. All write messages to the same pipe. Parent reads and prints messages. Handle interleaving (messages from different children getting into the pipe with no particular sequence but ensure atomic writes i.e. the messages themselves do not get jumbled up. (hint: use message size).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>

#define NUM_CHILDREN 3
#define MSG_SIZE 64

typedef struct {
    int child_id;
    int sequence_num;
    char message[MSG_SIZE - sizeof(int) - sizeof(int)];
} Message;

void main() {
    int pipefd[2];
    pid_t children[NUM_CHILDREN];

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe creation failed");
        return;
    }

    printf("[Parent] Creating %d child processes...\n", NUM_CHILDREN);

    // Create child processes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        children[i] = fork();

        if (children[i] == 0) {
            // CHILD PROCESS
            close(pipefd[0]); // Close read end

            Message msg;
            memset(&msg, 0, sizeof(Message));
            msg.child_id = i;

            // Each child sends 3 messages
            for (int j = 0; j < 3; j++) {
                msg.sequence_num = j;
                snprintf(msg.message, sizeof(msg.message) - 1, 
                         "Message %d from Child %d", j, i);

                printf("[Child %d] Sending message %d: %s\n", i, j, msg.message);

                // Atomic write - write entire structure at once
                // PIPE_BUF guarantees atomicity for writes <= 4096 bytes
                ssize_t written = write(pipefd[1], &msg, sizeof(Message));
                if (written == -1) {
                    perror("write failed");
                    exit(1);
                }

                sleep(1); // Small delay to demonstrate interleaving
            }

            close(pipefd[1]);
            printf("[Child %d] All messages sent. Exiting.\n", i);
            exit(0);

        } else if (children[i] < 0) {
            perror("fork failed");
            return;
        }
    }

    // PARENT PROCESS - Read from pipe
    close(pipefd[1]); // Close write end

    printf("[Parent] Reading messages from children...\n");

    Message msg;
    int messages_received = 0;

    // Read all messages
    while (read(pipefd[0], &msg, sizeof(Message)) > 0) {
        printf("[Parent] Received: Child %d, Sequence %d, Message: %s\n",
               msg.child_id, msg.sequence_num, msg.message);
        messages_received++;
    }

    close(pipefd[0]);

    // Wait for all children
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    printf("[Parent] Total messages received: %d\n", messages_received);
    printf("[Parent] All children completed. Parent exiting.\n");
}
