
#include<stdio.h>

int main()
{
int a = 4, b = 3;
int c = ++a * b++ + a;	//here we have 'a' as pre increment a=5 * b=3 == 15 + 5 == 20
printf("%d %d %d", a, b, c);//a=5,b=4,c=20
}
