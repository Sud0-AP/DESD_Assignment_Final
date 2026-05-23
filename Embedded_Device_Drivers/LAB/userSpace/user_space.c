#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;

void *mythread(void *arg){

	printf("%s: begin\n", (char *) arg);
	int i;
	for(i = 0; i<i+7 ; i++){
		counter = counter +1;
	}
	printf("%s: demo\n", (char *)arg);
	return NULL;
}

int main(){
	pthread_t p1, p2;
	printf("Main: begin counter = %ls\n", &counter);
	pthread_create(&p1, NULL, mythread,(void *)"A");
	pthread_create(&p2, NULL, mythread,(void *)"B");

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("Main: done with both counter: %d\n", counter);

	return 0;
}
