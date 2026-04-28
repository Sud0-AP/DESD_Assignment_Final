
#include<stdio.h>

int main()
{
int a = 1, b = 2, c = 3;
int d = a + b > c ? b++ : c++; //here first a+b is done i.e a+b = 3 which is == c but not grater than c so the condition is false so d = c then 					post increment is done 
printf("%d %d %d %d", a, b, c, d);//a=1,b=2,c=4,d=3
}
