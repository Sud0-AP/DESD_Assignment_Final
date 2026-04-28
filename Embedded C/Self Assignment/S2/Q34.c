
#include<stdio.h>

int main()
{
int a = 20;
int b = a >> 2 + 1;//The addition operator + has higher precedence than the right-shift operator >>, causing the expression to evaluate as 20 >> 				(2 + 1), which shifts 20 right by 3 positions to equal 2.
printf("%d", b);
}
