//PRN: 260240130005 260240130032
//Create 4 threads. Each increments a global variable 1000 times. Display final value. USING MUTEX

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *t_routine(void *);
int counter = 0;

int main(){
	pthread_t t[4];
	int ret;
	int num[4] = {1,2,3,4};

	printf("From main: Current counter value = %d\n", counter);

	for(int i=0; i<4; i++){
		ret = pthread_create(&t[i], NULL, t_routine, (void *) &num[i]);
		if(ret != 0){
			errno = ret;
			perror("Error: ");
			return 0;
		}
	}

	for(int i=0; i<4; i++){
		ret = pthread_join(t[i], NULL);
		if(ret != 0){
			errno = ret;
			perror("Error: ");
			return 0;
		}
	}

	printf("From main: Counter value after all threads executed = %d\n", counter);

	pthread_mutex_destroy(&lock);

	return 0;
}


void *t_routine(void *arg){
	int num = *((int *) arg);
	
	pthread_mutex_lock(&lock);
	for(int i=1; i<=1000000; i++){
		counter++;
	}
	
	printf("Thread %d execution complete, Current counter value = %d\n", num, counter);
	pthread_mutex_unlock(&lock);
	
	pthread_exit(NULL);
}
