
#include<stdio.h>

int main()
{
int a = 5;
int b = (a += 2, a *= 3, a);//a is first incremented to 7, then multiplied to 21, which is the final value assigned to both a and b.
printf("%d %d", a, b);

}
