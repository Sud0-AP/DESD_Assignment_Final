
#include<stdio.h>

int main()
{
int a = 2, b = 3, c;//we declare int variable a=2 , b=3 and c 
c = (a++, b++, a + b);//we do the operation now , a++ which means a is increased by a after operation , b++ which means it is increased by b 							after operation
printf("%d %d %d", a, b, c);//a=3(we increase then performs operation),b=4(we increase then perform operation),c=7(c=3+4)
}

