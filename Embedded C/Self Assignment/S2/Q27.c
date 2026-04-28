
#include<stdio.h>

int main()
{
int a = 4, b = 3, c = 2;
int d = a++ * b++ + ++c;//The expression calculates d using the current values of a and b (4 * 3) before they increment, then adds the 				pre-incremented value of c (3), resulting in 15.
printf("%d %d %d %d", a, b, c, d);

}
