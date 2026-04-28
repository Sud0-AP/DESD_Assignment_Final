
#include<stdio.h>

int main()
{
int a = 3, b = 4, c; //we declare int variable a=3 , b=4 and c 
c = a++ + ++b + a;	//using operation , a has ++ on right side , so it will increase by 1 after operation , b has ++ on left side and then 					after the a(increased by 1) is increased and it is now added 
printf("%d %d %d", a, b, c);//a=4(a is increased after adding is done ,b=5(b is increased before the operation),c=12(c=3+5+4)
}
