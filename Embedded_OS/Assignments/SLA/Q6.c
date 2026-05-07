//Create 5 threads from a process. All threads run in infinite superloop printing some string every 1 second. handle process threads communication using pthread_join().

#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

void *tN_routine(void *);

int main(){
	pthread_t t[5];
	int ret;
	int num[5] = {1,2,3,4,5};

	printf("Hello from Main before thread calls!!\n");
	for(int i = 0; i<5; i++){
		ret = pthread_create(&t[i], NULL, tN_routine, (void *) (num+i));
			if(ret != 0){
			errno = ret;
			perror("pthread_create");
			return 0;
		}
	}
	
	for(int i = 0; i<5; i++){
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
	while(1){
		printf("Thread number = %d\n"
			"PID: %d\n"
			"TID: %ld\n", num, getpid(), pthread_self());
		sleep(1);
	}
}
