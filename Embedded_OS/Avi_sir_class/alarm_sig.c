#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timer_handler(int sig) {
    printf("alarm signal received !!!\n");
}

int main() {
    signal(SIGALRM, timer_handler);

    printf("5 seconds to do something... \n");
    alarm(5); // Schedule the alarm
	
    printf("main now waiting for any signal\n");
    pause(); // Wait specifically for any signal to arrive
    
    printf("alarm signal received now main exiting\n");
    return 0;
}
