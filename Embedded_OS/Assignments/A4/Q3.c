//PRN: 260240130005 260240130032
//Using pthread_join()
//Create 3 threads. Each thread sleeps for different durations. Ensure main thread waits for all threads to complete

#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

void *tN_routine(void *);

int main(){
	pthread_t t[3];
	int ret;
	int num[3] = {1,2,3};

	printf("Hello from Main before thread calls!!\n");
	for(int i = 0; i<3; i++){
		ret = pthread_create(&t[i], NULL, tN_routine, (void *) (num+i));
		if(ret != 0){
			errno = ret;
			perror("pthread_create");
			return 0;
		}
	}

	for(int i = 0; i<3; i++){
		ret = pthread_join(t[i], NULL);
		if(ret != 0){
			errno = ret;
			perror("pthread_join");
			return 0;
		}
	}
	printf("Hello from Main after thread execution!!\n");
}
void *tN_routine(void *arg){
	int num = *((int *) arg);
	switch(num){
		case 1:
			sleep(2);
			printf("Thread number = %d\n"
					"PID: %d\n"
					"TID: %ld\n", num, getpid(), pthread_self());
			break;
		case 2:
			sleep(10);
			printf("Thread number = %d\n"
					"PID: %d\n"
					"TID: %ld\n", num, getpid(), pthread_self());
			break;
		case 3:
			sleep(6);
			printf("Thread number = %d\n"
					"PID: %d\n"
					"TID: %ld\n", num, getpid(), pthread_self());
			break;
	}

	pthread_exit(NULL);
}
