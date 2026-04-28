
#include<stdio.h>

int main()
{
int a = 6, b = 3;
int c = a & b | a ^ b;//he expression evaluates the bitwise operations in order of precedence—AND (&) first, then XOR (^), and finally OR (|)—to 				compute a final result of 6.
printf("%d", c);
}
