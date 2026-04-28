
#include<stdio.h>

int main()
{
int a = 5, b = 4;
int c = a > b ? a++ : ++b;//since the condition a > b is true, the ternary operator executes a++ and assigns the original value of a to c, while 					completely skipping the ++b expression.
printf("%d %d %d", a, b, c);

}
