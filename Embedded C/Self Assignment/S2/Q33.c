
#include<stdio.h>

int main()
{
int a = 7;
int b = a << 2 + 1;//the addition 2 + 1 is evaluated first, resulting in a left shift of a by 3 positions (7×23), which equals 56.
printf("%d", b);
}
