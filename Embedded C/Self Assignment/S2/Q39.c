
#include<stdio.h>

int main()
{
int a = 4;
int b = (a++, ++a, a++);//The comma operator evaluates each expression from left to right, incrementing a three times in total, while assigning 					the value of the final a++ (6) to b.
printf("%d %d", a, b);

}
