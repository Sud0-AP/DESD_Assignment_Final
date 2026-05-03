//PRN: 260240130005 260240130032
//Basic thread creation: say hello from inside and outside threads

#include <stdio.h>
#include <pthread.h>
#include <errno.h>

void *t1_routine(void *);

int main(){
	pthread_t t1;
	int ret;

	ret = pthread_create(&t1, NULL, t1_routine, NULL);
	if(ret != 0){
		errno = ret;
		perror("pthread_create");
		return 0;
	}

	ret = pthread_join(t1, NULL);
	if(ret != 0){
		errno = ret;
		perror("pthread_join");
		return 0;
	}

	printf("Hello from Main!!\n");
}
void *t1_routine(void *arg){
	printf("Hello from Thread!!\n");

	pthread_exit(NULL);
}
