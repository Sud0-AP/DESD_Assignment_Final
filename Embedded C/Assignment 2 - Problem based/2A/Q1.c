// Calculator using functions

#include <stdio.h>

//defining all the operation's functions

int add(int a, int b){
	return a+b;
}

int subtract(int a, int b){
	return a-b;
}

float divide(int a, int b){
	return a/b;
}

int multiply(int a, int b){
	return a*b;
}

int main ()
{
	int a,b,choice; // input variables

	printf("Enter your choice of operation: [(1)-Addition, (2)-Subtraction, (3)-Multiplication, (4)-Division] : ");
	scanf("%d",&choice); // taking input for operation choice

	
	printf("\nEnter the operands: ");
	scanf("%d %d", &a, &b); // taking input for the oprands

	//if else ladder for different operations
	if (choice == 1)
		printf("The addition of the numbers %d + %d = %d\n", a, b, add(a,b));
	else if (choice == 2)
		printf("The subraction of the numbers %d - %d = %d\n", a,b, subtract(a,b));
	else if (choice == 3)
		printf("The multiplication of the numbers %d * %d = %d\n", a, b, multiply(a,b));
	else if (choice == 4)
		printf("The division of the numbers %d / %d = %f\n", a, b, divide(a,b));
	else
		printf("Enter the choice properly again!!\n"); //edge case where choice input is wrong

	return 0;
}




		
