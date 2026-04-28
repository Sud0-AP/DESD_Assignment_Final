

#include<stdio.h>

int main()
{
int a = 5, b = 10;		//declaring and initialising the int variables a=5 and b=10
int c;				//declaring a int variable as 'c'
c = ++a + b++;			//doing a operation and saving in c , in which we are increasing the value of a and adding it with be and then 						after operation occurs 'b' value is increased by 1
printf("%d %d %d", a, b, c);	// in the output the a=6 b=11 c=16 so , as we observed a is increased before operation so a=6 and then b is 					increased after operation so it prints 11 and as it was 10 while operation c=10+6=16
}
