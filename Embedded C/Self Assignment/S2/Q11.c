
#include<stdio.h>

int main()
{
int a = 3, b = 4, c;
c = (a++, b = a + b, b++);	//a is post incremented , b=a+b = 4+4=8,b is post incremented,operation occurs from left to right
printf("%d %d %d", a, b, c);//a=4,b=9,c=8
}
