// Calculate the factorial of a given number
//
#include <stdio.h>

int main() 
{
	int factorial, n, i; // initializing variables
	factorial = 1; // initializing factorial result variable
	printf("\nEnter the number to calculate it's Factorial: ");
	scanf("%d", &n); // taking input

	if(n == 0 || n == 1){
		factorial = 1; // edge case: factorial of 1 or 0 results to 1
	}else{
		for(i=1; i<=n; i++){
			factorial = factorial * i ; //calculating the factorial
		}
	}

	printf("\nFactorial of %d = %d \n", n, factorial); 

	return 0;

}
