//Create 2 pthreads both file writing to single file. thread1 writes "AAAA" and thread2 writes "BBBBB" in loop (for loop) 10 times. after writing both threads exit and main reads the file and prints the contents on STDOUT / terminal. Expected output should show pattern "AAAAABBBBBAAAAAABBBBB..."

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

int fd;

sem_t sem_a, sem_b;

void *thread_A(void *arg) {

	for (int i = 0; i < 10; i++) {
		sem_wait(&sem_b);
		write(fd, "AAAA", 4);
		sem_post(&sem_a);
	}
	pthread_exit(NULL);
}

void *thread_B(void *arg) {
	for(int i = 0; i < 10; i++) {
		sem_wait(&sem_a);
		write(fd, "BBBBB", 5);
		sem_post(&sem_b);
	}
	pthread_exit(NULL);
}

int main(){

	char buffer;
	int ret, arg[2], ret_1 = 1;
	pthread_t thread1, thread2;

	ret = sem_init(&sem_a, 0, 0);
	if(ret != 0) {
		perror("sem_a create error");
	}
	
	ret = sem_init(&sem_b, 0, 1);
	if(ret != 0) {
		perror("sem_b create error");
	}

	fd = open("AABB_blah.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
       	if(fd == -1) {
		perror("open failed");
		return 0;
	}
	
	arg[0] = 1;
	ret = pthread_create(&thread1, NULL, thread_A, NULL);
	if(ret != 0) {
		printf("thread A create error: %d\n", ret);
		return 0;
	}
	arg[1] = 2;
	ret = pthread_create(&thread2, NULL, thread_B, NULL);
	if(ret != 0) {
		printf("thread B create error: %d\n", ret);
		return 0;
	}


	ret = pthread_join(thread1, NULL);
	if(ret != 0) {
		printf("thread A join error\n");
		return 0;
	}
	printf("thread A exited, main continues\n");

	ret = pthread_join(thread2, NULL);
	if(ret != 0) {
		printf("thread B join error\n");
		return 0;
	}
	printf("thread B exited, main continues\n");

	while(ret_1 != 0){
		ret_1 = read(fd, &buffer, 1);
		write(1, &buffer, 1);
	}

	close(fd);

	return 0;
}
