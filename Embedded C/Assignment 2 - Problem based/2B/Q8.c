// To check if the given number is perfect or not (i.e. sum of all positive divisors / 2 is equal to the number itself)

#include <stdio.h>

//function declatarion to check if the given number is perfect or not
int isPerfect(int n){
	int sum = 0, i;
	for(i=1; i<=n; i++){ // iterating through all the +ve numbers smaller than the input number
		if(n%i == 0) // if the number is a divisor of the input number
			sum += i; // then add it to the sum of all divisors 
	}

	return ((sum/2) == n) ? 1 : 0; // check if sum/2 is equal to the input number if yes then return 1 otherwise 0 
}


int main ()
{
	int num;

	printf("Enter a number: ");
	scanf("%d",&num); // taking input

	if (isPerfect(num)) // using the function defined earlier to check if the number is perfect or not
		printf("\nThe entered number %d is perfect!!\n", num);
	else
		printf("\nThe entered number %d is not perfect...\n", num);

	return 0;
}
