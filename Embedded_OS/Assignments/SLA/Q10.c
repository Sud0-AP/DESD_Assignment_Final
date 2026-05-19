#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <semaphore.h>
#include <unistd.h>

void * t_cook(void *);

sem_t stoves;

int main(){
	int ret;
	int nums[10] = {1,2,3,4,5,6,7,8,9,10};
	pthread_t cooks[10];

	ret = sem_init(&stoves, 0, 3);
	if(ret !=0){
		perror("Error initializing semaphore: ");
		return 0;
	}

	printf("All Cooks Hired and Stoves Turned ON!!\n");
	
	for(int i=0; i<10; i++){
		ret = pthread_create(&cooks[i], NULL, t_cook, (void *)(nums+i));
		if(ret != 0){
			perror("Error creating Thread: ");
			return 0;
		}
	}


	for(int i=0; i<10; i++){
		ret = pthread_join(cooks[i], NULL);
		if(ret != 0){
			perror("Error wating for Thread: ");
			return 0;
		}
	}

	printf("All Cooks Done Cooking!!\n");

	ret = sem_destroy(&stoves);
	if(ret != 0){
		perror("Error destroying semaphore: ");
		return 0;
	}

	printf("All Stoves Turned OFF... Closing Restraunt!!\n");

	return 0;
}


void * t_cook(void *arg){
	int num = *((int *)arg);

	printf("Cook number %d has arrived to cook!!\n", num);

	sem_wait(&stoves);

	printf("Cook number %d has started cooking...\n", num);

	sleep(1);

	printf("Cook number %d has finished cooking!!\n", num);

	sem_post(&stoves);
	
	printf("Cook number %d is leaving...\n", num);

	pthread_exit(NULL);
}

