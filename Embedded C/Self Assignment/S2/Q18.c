
#include<stdio.h>

int main()
{
int a = 5;
int b = (a++, a++, a);//post increment of a is done 2 times so a =7
printf("%d %d", a, b);//a=7,b=7
}
