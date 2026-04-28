//Calculate the factorial of given number (Iterative)

#include <stdio.h>

int factorial_I(int x){
	int result = 1;
	for (int i=1 ; i<=x ; i++){
		result *= i;
	}
	return result;
}

int main(){
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("Factorial = %d\n",factorial_I(num));
	return 0;
}
