
#include<stdio.h>

int main()
{
int a = 5, b = 10;
b = a++ + ++a;		//we have 'a' as post increment then + to pre increment , i.e b = 5+7 =12
printf("%d %d", a, b);//a=7,b=12
}
