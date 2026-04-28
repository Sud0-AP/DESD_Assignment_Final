
#include<stdio.h>

int main()
{
int a = 0, b = 5;
int c = a++ || ++b; //here we have logical or gate 
printf("%d %d %d", a, b, c);//a=1(post increment),b=6(pre increment),c=1(true)
}
