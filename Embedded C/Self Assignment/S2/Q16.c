
#include<stdio.h>

int main()
{
int a = 3, b = 4;
int c = ++a + b++ + a++;//pre increment of a is added to b and the post increment is done the added to a and then post increment is done once 					again 
printf("%d %d %d", a, b, c);//a=5,b=5,c=12

}
