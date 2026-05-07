//PRN: 260240130005 260240130032
//Passing Arguments to Threads : Pass a number to each thread. Each thread prints square of the number.

#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

void *tN_routine(void *);

int main(){
	pthread_t t[2];
	int ret, num1, num2;

	printf("Enter two numbers you want to square:\n");
	scanf("%d %d", &num1, &num2);

	ret = pthread_create(&t[0], NULL, tN_routine, (void *) &num1);
	if(ret != 0){
		errno = ret;
		perror("pthread_create");
		return 0;
	}
	
	ret = pthread_create(&t[1], NULL, tN_routine, (void *) &num2);
	if(ret != 0){
		errno = ret;
		perror("pthread_create");
		return 0;
	}

	for(int i = 0; i<2; i++){
		ret = pthread_join(t[i], NULL);
		if(ret != 0){
			errno = ret;
			perror("pthread_join");
			return 0;
		}
	}

	printf("Main Exiting after thread execution!!\n");

	return 0;
}
void *tN_routine(void *arg){
	int num = *((int *) arg);
	int square = num * num ;
	printf("Square of the given number %d = %d\n"
		"By PID: %d "
		"and TID: %ld\n", num, square, getpid(), pthread_self());
	pthread_exit(NULL);
}
