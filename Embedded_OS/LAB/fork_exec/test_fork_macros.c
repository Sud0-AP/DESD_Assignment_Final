#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t p1;
	p1 = fork();
	//printf("after fork P1: %d\n", p1);
	if (p1 == 0){
		printf("child pid %d\n", getpid());
		printf("child pid %d\n", getpid());
		printf("child pid %d\n", getpid());
		printf("child pid %d\n", getpid());
		printf("child pid %d\n", getpid());
		printf("child ppid %d\n", getppid());
	}else{
		printf("parent %d\n", getpid());
		sleep(2);
	}

}
