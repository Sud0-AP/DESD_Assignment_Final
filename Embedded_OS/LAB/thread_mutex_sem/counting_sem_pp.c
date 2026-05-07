#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>       
#include <sys/stat.h>  
#include <semaphore.h>
#include <pthread.h>

void *t_routine(void *);

sem_t pump;

int main(){
	pthread_t car[10];

	int ret_s, ret_t;

	int car_num[10] = {1,2,3,4,5,6,7,8,9,10};

	printf("Welcome to CDAC petrol Pump!!\n");

	ret_s = sem_init(&pump, 0, 4);
	if(ret_s != 0){
		printf("Error: while initializing semaphore\n");
		return 0;
	}

	printf("4 Petrol Pumps are ready for business!!\n");

	for(int i=0; i<10; i++){
		ret_t = pthread_create(&car[i], NULL, t_routine, (void *)(car_num+i));
		if(ret_t != 0){
			printf("Error: while creating thread!!\n");
			return 0;
		}
	}

	for(int i=0; i<10; i++){
		ret_t = pthread_join(car[i], NULL);
		if(ret_t != 0){
			printf("Error: while waiting for thread!!\n");
			return 0;
		}
	}

	printf("All cars have left!!\n");
	sem_destroy(&pump);

	return 0;
}

void *t_routine(void *arg){
	int num = *((int *) arg);

	printf("Car number %d Arrived at the gas station\n", num);

	sem_wait(&pump);
	printf("Car number %d Has started Filling up!!\n", num);
	
	sleep(1);

	printf("Car number %d has left!!\n", num);
	sem_post(&pump);
}
