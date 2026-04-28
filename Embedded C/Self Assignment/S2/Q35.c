
#include<stdio.h>

int main()
{
int a = 3, b = 5;
int c = ++a * ++b + a++ * b++;//++a * ++b + a++ * b++ tries to read and write to a and b multiple times before the final ;, the "correct" value 						of a and b at any given moment is essentially a guess.
printf("%d %d %d", a, b, c);

}
