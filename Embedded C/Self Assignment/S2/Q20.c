
#include<stdio.h>

int main()
{
int a = 2, b = 3;
int c = (a + b) * a++ + ++b;	//first we solve bracket (a+b) = 2+3 = 5 , then 5*2=10+4=13 the operation happen from left to right
printf("%d %d %d", a, b, c);	//a=3,b=4,c=13

}
