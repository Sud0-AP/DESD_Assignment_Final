
#include<stdio.h>

int main()
{
int a = 6;
int b = a > 5 ? a++ : ++a;	//if a>5(as a=6 the condition is true)the a++ i.e b=6 a=7
printf("%d %d", a, b);//a=7 , b=6

}
