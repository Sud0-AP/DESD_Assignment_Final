
#include<stdio.h>

int main()
{
int a = 4;
int b = ~a;//bitwise NOT operator ~ flips all bits of the integer, which in two's complement representation results in the value −(a+1), transforming 4 into -5.
printf("%d", b);
}
