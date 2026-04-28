
#include<stdio.h>

int main()
{
int a = 0, b = 5;		
int c = a++ && ++b || ++b;	//a++ && ++b: a++ returns 0, so the && condition fails immediately; ++b is skipped.
printf("%d %d %d", a, b, c);	// || ++b: Because the left side of the || was false, the right side must execute; b increments from 5 to 6.

}
