// calculate GCD and LCM of two numbers

#include <stdio.h>

int main(){
	int num1, num2, GCD, LCM, temp, a,b; //declaring variables

	//taking the two numbers as input

	printf("Enter the 1st number: ");
	scanf("%d", &num1);

	printf("\nEnter the 2nd number: ");
	scanf("%d", &num2);

	printf("\nThe GCD and LCM for %d and %d is:", num1, num2);

	//initiallizing temporary variables for calculation
	a = num1;
	b = num2;

	while(b!=0) //calculating the 
	{
	temp = b;
	b = a % b;
	a = temp;	
	}

	GCD = a;

	printf("\nGCD = %d", GCD);

	LCM = (num1*num2)/GCD;

	printf("\nLCM = %d \n", LCM);

	return 0;	

}
