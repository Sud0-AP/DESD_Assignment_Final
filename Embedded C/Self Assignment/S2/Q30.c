
#include<stdio.h>

int main()
{
int a = 2, b = 3;
int c = (a++, b++, a*b);//a becomes 3 and b becomes 4, so c is assigned their product, 12.
printf("%d %d %d", a, b, c);

}
