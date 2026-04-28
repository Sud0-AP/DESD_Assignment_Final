
#include<stdio.h>

int main()
{
int a = 2, b = 3, c = 4;
int d = a++ + ++b * c;	//we have post increment for a , then pre increment for b the multipy with c then addition happens , i.e 					d=4(b)*4(c)=16+2(a)=18
printf("%d %d %d %d", a, b, c, d);//a=3,b=4,c=4,d=18
}
