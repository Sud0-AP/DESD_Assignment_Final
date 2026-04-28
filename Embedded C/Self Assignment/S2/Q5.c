
#include<stdio.h>

int main()
{
int a = 3, b = 5;	//declare and initialize a&b
int c = a++ && ++b;	//c=a++ && ++b means logical and gate 
printf("%d %d %d", a, b, c);//a=4,b=6,c=1(true)
}
