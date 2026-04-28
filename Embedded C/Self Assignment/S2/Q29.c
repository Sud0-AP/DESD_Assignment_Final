
#include<stdio.h>

int main()
{
int a = 3;
int b = a++ + ++a + a++;//Typically 6 13 (on GCC), but results vary by compiler.
printf("%d %d", a, b);

}
