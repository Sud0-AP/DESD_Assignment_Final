// To find if the given number is Prime or not 
#include <stdio.h>

int main()
{
	int input_num, i; // initializing input and loop variables

	printf("Enter the number to check if prime or not: ");
	scanf("%d", &input_num); // taking input

	if (input_num == 0 || input_num == 1){
		printf("Entered number %d is not a prime number\n", input_num); // directly checking if entred number is 0 or 1 i.e. not a prime number
	}else {
		for(i = 2; (i*i)<=input_num; i++){ // checking if the square of the divisor is smaller than the input number then only check the divisibility
			if(input_num % i == 0){ // checking if divisible 
				printf("Entered number %d is not a prime number it is divisible by %d\n", input_num, i);
				return 0;
			}
		}
	
	}

	printf("Entred number %d is a prime number\n", input_num); // if not divisible by anything then the number is prime
	return 0;

}



