#include <stdio.h>
void fun(int);

int main(){
	int a = 3;
	fun(a);
}

void fun(int n){
	if(n>0){
		fun(n-1);
		printf("%d", n);
		fun(n-1);
	}
}
