// calculate GCD of given numbers

#include <stdio.h>

int cal_GCD(int num1, int num2){
	//initiallizing temporary variables for calculation
	int a = num1;
	int b = num2;
	int temp;

	while(b!=0) //calculating the GCD
	{
	temp = b;
	b = a % b;
	a = temp;
	}

	return a;
}

int main(){
	int num1, num2; //declaring variables

	//taking the two numbers as input

	printf("Enter the 1st number: ");
	scanf("%d", &num1);

	printf("\nEnter the 2nd number: ");
	scanf("%d", &num2);

	printf("\nThe GCD %d and %d is: %d\n", num1, num2, cal_GCD(num1, num2));

	return 0;

}
