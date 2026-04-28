// print prime numbers till n

#include <stdio.h>

void printPrime(int n){

	int isPrime = 1; //flag variable to check if prime

	if(n <= 1)
		printf("---No Primes---"); 
	else
		for (int j = 2; j <= n ; j++){ //iterating through each number up to N
			for (int i = 2 ; (i*i)<=j ; i++){ // loop to check if the number J is a prime or not
				if (j%i == 0){
					isPrime = 0; //if divisible by i then set flag to 0 and stop the inner for loop
					break;
				}
			}
			if (isPrime == 1) // if flag was not changed then the number J is prime and we need to print it
				printf("%d\n", j);
			else
				isPrime = 1; // if the flag was set to 0 in the inner for loop i.e. J was not prime then dont print anything and reset the flag for checking J+1 
		}
}

int main(){
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	printPrime(num);

	return 0;
}
