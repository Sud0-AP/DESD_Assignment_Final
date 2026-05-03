#include <stdio.h>
#include <pthread.h>
#include <errno.h>

void *routine(void *);

int main(){
	pthread_t t1, t1;

	int ret;



}

void *routine(void *arg){
	printf("This is thread number %d\n", *((int *)arg));
}
