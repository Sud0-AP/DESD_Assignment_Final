// PRN: 260240130005 260240130032
// Thread Return Values
// Each thread computes factorial of a number. Return result using `pthread_exit(). Main thread collects results using `pthread_join().

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

int result = 1, num;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *t_routine(void *);

int main(){
	printf("Enter the number you wish to calculate the factorial of: \n");
	scanf("%d", &num);

	pthread_t t[2];
	int ret_1, ret_2, exit_flag = 0;

	result = num;

	printf("The factorial of %d is ", num);

	ret_1 = pthread_create(&t[0], NULL, t_routine, (void *) &num);
	if(ret_1 != 0){
		errno = ret_1;
		perror("pthread_create");
		return 0;
	}

	ret_1 = pthread_create(&t[1], NULL, t_routine, (void *) &num);
	if(ret_1 != 0){
		errno = ret_1;
		perror("pthread_create");
		return 0;
	}

	ret_2 = pthread_join(t[0], (void *) &exit_flag);
	if(ret_2 != 0){
		errno = ret_2;
		perror("pthread_join");
		return 0;
	}
	
	ret_2 = pthread_join(t[1],(void *) &exit_flag);
	if(ret_2 != 0){
		errno = ret_2;
		perror("pthread_join");
		return 0;
	}

	printf("%d\n", result);

	pthread_mutex_destroy(&lock);

	return 0;
}
void *t_routine(void *arg){

	while(1){
		pthread_mutex_lock(&lock);
	
		if(num == 1){
			pthread_mutex_unlock(&lock);
			pthread_exit((void *)&result);
		}

		num = num - 1;
		result *= num;
	
		pthread_mutex_unlock(&lock);
	}
}
