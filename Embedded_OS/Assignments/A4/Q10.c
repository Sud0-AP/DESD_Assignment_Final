//PRN: 260240130005 260240130032
//Create a fixed number of worker threads. Assign tasks dynamically (e.g., simple computations). Understand Task scheduling and Thread reuse.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

typedef struct two_num{
	int a;
	int b;
	int op;
}threadArgs;

threadArgs shared_task;
int task_ready = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *t_worker(void *);

int main(){
	threadArgs arg;
	pthread_t workers[3];
	int ret, choice, i;

	printf("Enter two numbers: ");
	scanf("%d %d", &arg.a, &arg.b);

	printf("Creating 3 worker threads...\n");
	for(i = 0; i < 3; i++){
		ret = pthread_create(&workers[i], NULL, t_worker, NULL);
		if(ret != 0){
			errno = ret;
			perror("pthread_create");
			return 0;
		}
	}

	while(1){
		printf("\nWhat operation do you wish to perform\n"
				"(Enter 1) Addition\n"
				"(Enter 2) Multiplication\n"
				"(Enter 3) Division\n"
				"(Enter 4) Subtraction\n"
				"(Enter 5) Exit\n");
		scanf("%d", &choice);

		if(choice == 5){
			break;
		}

		if(choice >= 1 && choice <= 4){
			shared_task.a = arg.a;
			shared_task.b = arg.b;
			shared_task.op = choice;
			task_ready = 1;
			sleep(1);
		}
		else{
			printf("Invalid choice!\n");
		}
	}

	return 0;
}

void *t_worker(void *arg){
	int result;
	int worker_id = pthread_self();

	printf("Worker thread started (TID: %d)\n", worker_id);

	while(1){
		pthread_mutex_lock(&lock);
		if(task_ready){
			int op = shared_task.op;
			int a = shared_task.a;
			int b = shared_task.b;
			task_ready = 0;
			pthread_mutex_unlock(&lock);

			switch(op){
				case 1:
					result = a + b;
					printf("Worker: %d + %d = %d\n", a, b, result);
					break;
				case 2:
					result = a * b;
					printf("Worker: %d * %d = %d\n", a, b, result);
					break;
				case 3:
					if(b != 0){
						result = a / b;
						printf("Worker: %d / %d = %d\n", a, b, result);
					}
					else{
						printf("Worker: Cannot divide by zero!\n");
					}
					break;
				case 4:
					result = a - b;
					printf("Worker: %d - %d = %d\n", a, b, result);
					break;
			}
		}
		else{
			pthread_mutex_unlock(&lock);
		}
		sleep(1);
	}

	pthread_exit(NULL);
}
