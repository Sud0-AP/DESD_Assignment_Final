//Find the biggest of the three numbers.

#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Enter three numbers: \n");
	scanf("%d %d %d",&a,&b,&c); //taking input

	if(a>b && a>c){

		printf("First number is the greatest of the three: %d \n", a); // Checking if the first number is the greatest

	} else if(b>a && b>c){

		printf("Second number is the greatest of the three: %d \n", b); // Checking if the second number is the greatest

	} else if(c>a && c>b){

		printf("Third number is the greatest of the three: %d \n", c); // Checking if the Third number is the greatest

	} else {

		printf("All numbers are the same!! \n"); // Edge case where all numbers are the same
	}

	return 0;
}
