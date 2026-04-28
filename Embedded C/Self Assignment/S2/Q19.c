
#include<stdio.h>

int main()
{
int a = 4, b = 3;
int c = a > b ? a++ + b++ : a-- + b--;	//here it is asking if a>b which is true as 4>3 now we take c=a+++b++,c=4+3=7,a=4+1=5,b=3+1=4
printf("%d %d %d", a, b, c);	//a=3,b=2,c=7
}
