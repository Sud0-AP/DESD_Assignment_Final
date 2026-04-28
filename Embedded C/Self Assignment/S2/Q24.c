
#include<stdio.h>

int main()
{
int a = 1, b = 2, c = 3;
int d = a++ && b++ || ++c;	//b++ executes since a++ is non-zero, but ++c is skipped entirely because the OR condition is already satisfied by 					the first half of the expression.
printf("%d %d %d %d", a, b, c, d);
}
