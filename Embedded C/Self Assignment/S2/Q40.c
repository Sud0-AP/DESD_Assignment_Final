
#include<stdio.h>

int main()
{
int a = 3, b = 4;
int c = a++ * ++b + ++a * b++;//++b makes b=5, and ++a makes a=4.++b makes b=5, and ++a makes a=4.(4×5+4×5=40).
printf("%d %d %d", a, b, c);//The a++ and b++ trigger after the result is determined, ending with a=5 and b=6.

}
