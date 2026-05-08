//PRN: 260240130005 260240130032
//Implement producer-consumer using threads. Use mutex and condition variables. (Hint:Use pthread_cond_wait()`and pthread_cond_signal()`)

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PATH_D "producer_consumer.txt"
#define PATH_S "file_with_words.txt"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int flag = 0;

void *t_consumer(void *);
void *t_producer(void *);

int main(){
	pthread_t consumer, producer;

	int ret;

	ret = pthread_create(&producer, NULL, t_producer, NULL);
	if(ret != 0){
		perror("Error creating thread: ");
		return 0;
	}

	ret = pthread_create(&consumer, NULL, t_consumer, NULL);
	if(ret != 0){
		perror("Error creating thread: ");
		return 0;
	}

	ret = pthread_join(producer, NULL);
	if(ret != 0){
		perror("Error creating thread: ");
		return 0;
	}

	ret = pthread_join(consumer, NULL);
	if(ret != 0){
		perror("Error creating thread: ");
		return 0;
	}

	pthread_mutex_destroy(&lock);

	return 0;
}

void *t_consumer(void *arg){
	int fd = open(PATH_D, O_RDONLY | O_CREAT, S_IRWXU);
	char buffer;
	int ret;

	while(1){
		pthread_mutex_lock(&lock);

		while(flag == 0){
			pthread_cond_wait(&condition, &lock);
		}

		if (flag == -1) {
        		pthread_mutex_unlock(&lock);
       		 	break;
    		}

		printf("Data Transfered from source: \n");
		ret = 1;
		while(ret != 0){
			ret = read(fd, &buffer, 1);
			write(1, &buffer, 1);
		}
		printf("\n");

		flag = 0;
		pthread_cond_signal(&condition);
		pthread_mutex_unlock(&lock);
	}
	close(fd);
	pthread_exit(NULL);
}

void *t_producer(void *arg){
	int fd1 = open(PATH_D, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, S_IRWXU);
	int fd2 = open(PATH_S, O_RDONLY);
	if(fd2 < 0){
		perror("Error opening destination file: ");
		pthread_exit(NULL);
	}

	char buffer = ' ';
	int ret = 1;

	while(ret != 0){
		pthread_mutex_lock(&lock);
		
		while(flag == 1){
			pthread_cond_wait(&condition, &lock);
		}

		while(buffer != '.'){
			ret = read(fd2, &buffer, 1);
			if (ret <= 0) break;
			write(fd1, &buffer, 1);
		}
		buffer = ' ';
		printf("1 sentance taken from the source file and pasted in destination file...\n");

		flag = 1;
		pthread_cond_signal(&condition);
		pthread_mutex_unlock(&lock);
	}
	pthread_mutex_lock(&lock);
	flag = -1;
	close(fd1);
	close(fd2);
	pthread_cond_signal(&condition);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
