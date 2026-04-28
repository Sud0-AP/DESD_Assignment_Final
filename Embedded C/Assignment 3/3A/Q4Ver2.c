//Calculate the factorial of given number (Recursive)

#include <stdio.h>

int factorial_R(int x){
	if(x<= 0)
		return 1;
	else
		return x * factorial_R(x-1);
}

int main(){
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("Factorial = %d\n",factorial_R(num));
	return 0;
}
