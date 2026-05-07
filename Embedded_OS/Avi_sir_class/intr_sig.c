#include <stdio.h>
#include <signal.h>
#include <unistd.h>


int count = 0;

void handle_sigint(int sig) {
    printf("Caught signal %d! I'm not closing yet.\n", sig);
    
    ++count;
    if(count > 3) {
	   printf("Caught signal 3+ times now, assign default handler\n");
	   signal(SIGINT, SIG_DFL);
    } 
}

int main() {
    // Tell the OS:If you see SIGINT, run handle_sigint instead of killing the process run interrupt handler
    signal(SIGINT, handle_sigint);

    while (1) {
        printf("Sleeping... try pressing Ctrl+C\n");
        sleep(2);
    }
    return 0;
}
