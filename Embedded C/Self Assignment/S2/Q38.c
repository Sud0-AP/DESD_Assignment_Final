
#include<stdio.h>

int main()
{
int a = 0, b = 3;
int c = a++ && b++;//a++ evaluates to 0 (which is false), the logical AND (&&) operator short-circuits, skipping the b++ expression entirely and 				resulting in c being 0.
printf("%d %d %d", a, b, c);

}
