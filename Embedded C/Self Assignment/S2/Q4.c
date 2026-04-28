
#include<stdio.h>

int main()
{
int a = 5, b = 6;	//declare and initialize a & b 
int c = (a > b) ? a++ : b++;	//c=(a>b)?a++:b++ which means if a>b then c=a++ then ++ operation happens else c=b++ 
printf("%d %d %d", a, b, c);	//a=5,b=7,c=6 as a>b is not true
}
