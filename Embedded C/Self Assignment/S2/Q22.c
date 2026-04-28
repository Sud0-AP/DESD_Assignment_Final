
#include<stdio.h>

int main()
{
int a = 2, b = 3;
int c = a++ * ++b + ++a;	//first * operation is done , a++ * ++b ==> 2*4=8 ==> a++=3 ==> 8+4 = 12   
printf("%d %d %d", a, b, c);	// a=4 , b=4 , c=12
}
