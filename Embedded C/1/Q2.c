// Reversing a three digit number

#include <stdio.h>

int main()
{
	int n, d1, d2, d3, rev; // initializing variables
	printf("Enter a three digit number\n");
	scanf("%d", &n); // taking input
	
	if(n<100 || n>999){
	printf("Input is not a three digit number!! \n");
	return 0;
	}

	// Seperating the digits
	d1 = n % 10;
	d2 = (n / 10) % 10;
	d3 = n / 100;

	//rebuilding the number
	rev = (d1 * 100) + (d2 * 10) + (d3);
	
	printf("Reverse Number: %d \n", rev);

	return 0;
}


