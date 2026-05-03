#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

int fd;

sem_t sem;

void *thread_A(void *arg) {
	
	for(int i = 0; i < 10; i++) {
		sleep(1);
		printf("thread A running \n");
	}

	sem_post(&sem);
	printf("thread A exiting and posting sem\n");
	
	pthread_exit(NULL);
}

void *thread_B(void *arg) {
	
	printf("thread B created\n");
	
	sem_wait(&sem);
	printf("thread B unblocked\n");
	
	pthread_exit(NULL);
}

void main()
{
	int main_st = 10;
	int ret, arg[2];
	pthread_t thread1, thread2;
	ret = sem_init(&sem, 0, 0);
	if(ret != 0) {
		perror("sem create error");
	}

	
	ret = pthread_create(&thread1, NULL, thread_A, NULL);
	if(ret != 0) {
		printf("thread A create error: %d\n", ret);
		return;
	}
	arg[1] = 2;
	ret = pthread_create(&thread2, NULL, thread_B, NULL);
	if(ret != 0) {
		printf("thread B create error: %d\n", ret);
		return;
	}


	ret = pthread_join(thread1, NULL);
	if(ret != 0) {
		printf("thread A join error\n");
		return;
	}
	printf("thread A exited, main continues\n");

	ret = pthread_join(thread2, NULL);
	if(ret != 0) {
		printf("thread B join error\n");
		return;
	}
	printf("thread B exited, main continues\n");
}
