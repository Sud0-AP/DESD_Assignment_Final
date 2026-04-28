// calculate GCD of given numbers

#include <stdio.h>

int cal_GCD(int num1, int num2) {
	
	if (num2 == 0){ //when a divisor is found i.e. both divided properly 
		return num1; //return the divisor
	}

	return cal_GCD(num1,num1%num2);
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
