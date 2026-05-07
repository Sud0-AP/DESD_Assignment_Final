#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void segfault_handler(int sig) {
    printf("Error: Segmentation Fault (Signal %d) detected!\n", sig);
    printf("Cleaning up and exiting safely...\n");
    exit(1); //exit here because memory is corrupted
}

int main() {
    signal(SIGSEGV, segfault_handler);

    int *p = NULL;
    *p = 10; // This triggers the SIGSEGV

    return 0;
}
