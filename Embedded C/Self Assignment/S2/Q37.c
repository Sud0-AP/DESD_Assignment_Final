
#include<stdio.h>

int main()
{
int a = 2, b = 3;
int c = a++ || b++;//a++ returns 2 (which is true), the logical OR (||) short-circuits and skips the b++ expression entirely, leaving b unchanged 				while a increments to 3.
printf("%d %d %d", a, b, c);

}
