// Create 2 pthreads both file writing to single file. thread1 writes "AAAA" and thread2 writes "BBBBB" in loop (for loop) 10 times. after writing both threads exit and main reads the file and prints the contents on STDOUT / terminal. Expected output should show pattern "AAAAA" 10 times then "BBBBB" 10 times.

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
	sem_wait(&sem_b);
	for (int i = 0; i < 10; i++) {
		write(fd, "AAAAA", 5);
	}
	sem_post(&sem_a);
	pthread_exit(NULL);
}

void *thread_B(void *arg) {
	sem_wait(&sem_a);
	for(int i = 0; i < 10; i++) {
		write(fd, "BBBBB", 5);
	}
	sem_post(&sem_b);
	pthread_exit(NULL);
}

int main(){

	char buffer;
	int ret, ret_1 = 1;
	pthread_t thread1, thread2;

	ret = sem_init(&sem_a, 0, 0);
	if(ret != 0) {
		perror("semaphore A create error");
	}
	
	ret = sem_init(&sem_b, 0, 1);
	if(ret != 0) {
		perror("semaphore B create error");
	}

	fd = open("AABBx10_blah.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
       
	if(fd == -1) {
		perror("open failed");
		return 0;
	}
	
	ret = pthread_create(&thread1, NULL, thread_A, NULL);
	if(ret != 0) {
		perror("thread A create error: ");
		return 0; 
	} 
 
	ret = pthread_create(&thread2, NULL, thread_B, NULL);
	if(ret != 0) {  
		perror("thread B create error: ");
		return 0;  
	}  
  
  
	ret = pthread_join(thread1, NULL);  
	if(ret != 0) {  
		perror("thread A join error: ");  
		return 0; 
	}
	printf("thread A exited, main continues\n");

	ret = pthread_join(thread2, NULL);
	if(ret != 0) {
		printf("thread B join error\n");
		return 0;
	}
	printf("thread B exited, main continues\n");

	lseek(fd, 0, SEEK_SET);

	while(ret_1 != 0){
		ret_1 = read(fd, &buffer, 1);
		ret = write(1, &buffer, 1);
		if(ret_1 < 0) {
			perror("Error printing: ");
			return 0;
		}
	}

	printf("\n");

	close(fd);

	return 0;
}
