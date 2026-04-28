
#include<stdio.h>

int main()
{
int a = 5;
int b = a++ > 5 ? ++a : a++;//The condition a++ > 5 evaluates as false (5>5), so the ternary operator skips the ++a branch and only executes the 						final a++, assigning the current value of 6 to b and incrementing a twice in total.
printf("%d %d", a, b);


}
