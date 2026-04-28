
#include<stdio.h>

int main()
{
int a = 5;
int b = a++ + a++ + ++a;//a++ is done first then added to a , 6+5=11 then ++ is done 12+ ++a , then 12+7=19
printf("%d %d", a, b);//a=8,b=19

}
