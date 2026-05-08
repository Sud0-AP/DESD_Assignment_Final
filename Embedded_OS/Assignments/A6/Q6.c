//PRN: 260240130005 260240130032
//Error Propagation via Pipe
//Child executes a task (e.g., divide numbers). If an error occurs (e.g., divide by zero), it sends error code/message to parent via pipe. Parent prints appropriate message.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define ERROR_SUCCESS 0
#define ERROR_DIVIDE_BY_ZERO 1
#define ERROR_INVALID_INPUT 2

typedef struct {
    int error_code;
    char error_msg[256];
    int result;
} ErrorResponse;

void main() {
    int pipefd[2];
    pid_t pid;

    // Create pipe
    if (pipe(pipefd) == -1) {
        perror("pipe creation failed");
        return;
    }

    pid = fork();

    if (pid > 0) {
        // PARENT PROCESS
        close(pipefd[1]); // Close write end

        ErrorResponse response;
        printf("[Parent] Waiting for child to perform division task...\n");

        // Read response from child
        read(pipefd[0], &response, sizeof(ErrorResponse));
        close(pipefd[0]);

        // Check for errors
        if (response.error_code == ERROR_SUCCESS) {
            printf("[Parent] Operation successful!\n");
            printf("[Parent] Result: %d\n", response.result);
        } else if (response.error_code == ERROR_DIVIDE_BY_ZERO) {
            printf("[Parent] ERROR: %s\n", response.error_msg);
        } else if (response.error_code == ERROR_INVALID_INPUT) {
            printf("[Parent] ERROR: %s\n", response.error_msg);
        } else {
            printf("[Parent] Unknown error code: %d\n", response.error_code);
        }

        wait(NULL);
        printf("[Parent] Child completed. Parent exiting.\n");

    } else if (pid == 0) {
        // CHILD PROCESS
        close(pipefd[0]); // Close read end

        ErrorResponse response;
        memset(&response, 0, sizeof(ErrorResponse));

        // Perform division task
        int dividend = 20;
        int divisor = 0; // Change to non-zero for success case

        printf("[Child] Attempting division: %d / %d\n", dividend, divisor);

        if (divisor == 0) {
            // Error case: divide by zero
            response.error_code = ERROR_DIVIDE_BY_ZERO;
            strcpy(response.error_msg, "Division by zero is not allowed!");
            printf("[Child] Error detected: divide by zero\n");
        } else if (divisor < 0) {
            // Error case: invalid input
            response.error_code = ERROR_INVALID_INPUT;
            strcpy(response.error_msg, "Divisor cannot be negative!");
            printf("[Child] Error detected: invalid input\n");
        } else {
            // Success case
            response.error_code = ERROR_SUCCESS;
            response.result = dividend / divisor;
            printf("[Child] Division successful: %d / %d = %d\n", 
                   dividend, divisor, response.result);
        }

        // Send response back to parent
        write(pipefd[1], &response, sizeof(ErrorResponse));
        close(pipefd[1]);

        printf("[Child] Response sent to parent. Exiting.\n");
        exit(0);

    } else {
        perror("fork failed");
    }
}
