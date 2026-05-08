//PRN: 260240130005 260240130032
//Parallel Sum Using Multiple Children
//Parent creates N child processes. Each child computes the sum of a portion of an array. Use pipes for each child to send results back. Parent computes the final total.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_CHILDREN 4
#define ARRAY_SIZE 16

// Forward declaration of the helper function
void close_all_pipes(int pipefd[][2], int num, int close_write);

int main() {
    int pipefd[NUM_CHILDREN][2];
    pid_t children[NUM_CHILDREN];
    int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int portion_size = ARRAY_SIZE / NUM_CHILDREN;

    // Print initial array
    printf("[Parent] Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Create pipes and child processes
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("pipe creation failed");
            exit(1);
        }

        children[i] = fork();

        if (children[i] == 0) {
            // CHILD PROCESS
            
            // Close all read ends and other children's write ends
            for (int j = 0; j <= i; j++) {
                close(pipefd[j][0]); 
                if (j != i) close(pipefd[j][1]);
            }

            // Calculate portion for this child
            int start = i * portion_size;
            int end = start + portion_size;
            int partial_sum = 0;

            for (int j = start; j < end; j++) {
                partial_sum += array[j];
            }

            printf("[Child %d] Computing sum from index %d to %d: %d\n", 
                   i, start, end - 1, partial_sum);

            write(pipefd[i][1], &partial_sum, sizeof(int));
            close(pipefd[i][1]); // Finish writing
            exit(0);

        } else if (children[i] < 0) {
            perror("fork failed");
            exit(1);
        }
    }

    // PARENT PROCESS - Collect results from all children
    
    // Parent must close ALL write ends so it doesn't block itself
    close_all_pipes(pipefd, NUM_CHILDREN, 1); 

    int total_sum = 0;
    for (int i = 0; i < NUM_CHILDREN; i++) {
        int partial_sum = 0;
        
        // Read from child
        if (read(pipefd[i][0], &partial_sum, sizeof(int)) > 0) {
            printf("[Parent] Received from Child %d: %d\n", i, partial_sum);
            total_sum += partial_sum;
        }
        
        close(pipefd[i][0]); // Finished reading from this pipe
    }

    // Wait for all children to prevent zombies
    for (int i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    printf("[Parent] Total Sum: %d\n", total_sum);
    printf("[Parent] All children completed. Parent exiting.\n");
    
    return 0;
}

// Helper function to close either all read or all write ends
void close_all_pipes(int pipefd[][2], int num, int close_write) {
    for (int i = 0; i < num; i++) {
        if (close_write) {
            close(pipefd[i][1]);
        } else {
            close(pipefd[i][0]);
        }
    }
}