#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int counter = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_routine(void *arg) {
	//10 lakh
	for(int i = 0; i < 1000000; i++) {
		pthread_mutex_lock(&lock);
		++counter;
		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);
}

void main()
{
	int main_st = 10;
	int ret, arg[2];
	pthread_t thread1, thread2;
	
	arg[0] = 1;
	ret = pthread_create(&thread1, NULL, thread_routine, (arg + 0));
	if(ret != 0) {
		printf("thread1 create error: %d\n", ret);
		return;
	}
	arg[1] = 2;
	ret = pthread_create(&thread2, NULL, thread_routine, (void *)(arg + 1));
	if(ret != 0) {
		printf("thread1 create error: %d\n", ret);
		return;
	}


	ret = pthread_join(thread1, NULL);
	if(ret != 0) {
		printf("thread1 join error\n");
		return;
	}
	printf("thread1 exited, main continues\n");

	ret = pthread_join(thread2, NULL);
	if(ret != 0) {
		printf("thread2 join error\n");
		return;
	}
	printf("thread2 exited, main continues\n");

	pthread_mutex_destroy(&lock);
	printf("MAIN: Counter: %d\n", counter);

}
