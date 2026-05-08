//PRN: 260240130005 260240130032
//Create a thread running an infinite loop. Cancel it from main thread using `pthread_cancel().

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

void *t_routine(void *);

int main(){
	pthread_t t1;

	int ret;

	printf("Hello from main:\n");

	ret = pthread_create(&t1, NULL, t_routine, NULL);

	if(ret != 0){
		errno = ret;
		perror("Error:");
		return 0;
	}

	sleep(1);

	printf("Cancelling the thread!!\n");
	pthread_cancel(t1);

	return 0;
}


void *t_routine(void *arg){
	printf("inside thread!!\n");
	while(1){
		printf("In the infinite loop!!\n");
		sleep(2);
	}
	pthread_exit(NULL);
}

