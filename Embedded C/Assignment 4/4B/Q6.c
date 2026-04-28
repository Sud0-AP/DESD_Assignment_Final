// To print int and float using different format specifiers
// PRN: 260240130005 and 260240130032
#include <stdio.h>
int main ()
{
	int a = 69;
	float b = 3.141590;

	printf("----------Integer formatting--------\n");
	printf("Standard = %d\n", a); //standard format specifier for decimal Integer
	printf("Padding (Width 5) = %5d\n", a); // %d format specifier with 5 widht blank padding 
	printf("Padding with zeros = %05d\n", a); // %d format specifier with padding
	printf("Left Aligned Padding = %-5d\n", a); // % format specifier with left aligned padding with width 5

	printf("---------Float Formatting-----------\n");
	printf("Standard = %f\n", b); //standard format specifier for decimal float
	printf("Padding of 8 Characters and 4 decimals = %8.4f\n", b); // %f format specifier with with 8 and turnacting with 4 decimal points
	printf("Upto 2 decimal point = %0.2f\n", b); // %f format specifier with turncation till 2 secimal points

	return 0;	
}	
