
#include<stdio.h>

int main()
{
int a = 3;
int b = ++a + a++ + a;		// b = 4 + 5 = 9 (a=4 then a++ a=5 ) , b=9+5 = 14
printf("%d %d", a, b);		//a=5 and b=14

}
