// Program to convert a number into Decimal, Binary, Octal, Hexadecimal
// PRN: 260240130005 and 260240130032

#include <stdio.h>

void dec_Binary(int x){
	
	if (x>0) { //if the last digit is not reached
		dec_Binary(x/2); //recursive call with dividing by 2 and putting quotient as input
		printf("%d", x%2); // printing the remainder
	}
}

int main()
{
	int a;

	printf("Enter a decimal number :");
	scanf("%d", &a); // taking input from the user

	printf("Binary conversion = ");
	dec_Binary(a); // binary convesion
	printf("\n");

	printf("Octal conversion = %o\n", a); // using the %o format specifier for octal numbers
	printf("Hexadecimal conversion = %x\n", a); // using the %x format specifier for hexadecimal numbers 

	return 0;
}

