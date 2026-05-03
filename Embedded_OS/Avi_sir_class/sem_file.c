#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

int fd;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
sem_t sig_a2b, sig_b2a;


void *thread_A(void *arg) {
	
	for (int i = 0; i < 100; i++) {

		sem_wait(&sig_b2a);
		//pthread_mutex_lock(&lock);
		write(fd, "AAAAA", 5);
		//pthread_mutex_unlock(&lock);
		sem_post(&sig_a2b);

	}
	pthread_exit(NULL);
}

void *thread_B(void *arg) {
	
	for(int i = 0; i < 100; i++) {

		sem_wait(&sig_a2b);
		//pthread_mutex_lock(&lock);
		write(fd, "BBBBB", 5);
		//pthread_mutex_unlock(&lock);
		sem_post(&sig_b2a);

	}
	pthread_exit(NULL);
}

void main()
{
	int main_st = 10;
	int ret, arg[2];
	pthread_t thread1, thread2;
	ret = sem_init(&sig_a2b, 0, 0);
	if(ret != 0) {
		perror("sig_a2b create error");
	}
	ret = sem_init(&sig_b2a, 0, 1);
	if(ret != 0) {
		perror("sig_b2a create error");
	}


	fd = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
       	if(fd == -1) {
		perror("open failed");
		return;
	}
	
	arg[0] = 1;
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

	pthread_mutex_destroy(&lock);

}
