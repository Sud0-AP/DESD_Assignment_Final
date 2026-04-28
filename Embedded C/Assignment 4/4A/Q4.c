//Find the biggest of the three numbers.
// PRN: 260240130005 and 260240130032

#include <stdio.h>

int biggest(int a,int b, int c){
	return a>b ? (a>c ? a:c) : (b>c ? b:c) ; //using turnery nested operator to determine which number is the biggest
}

int main()
{
	int a,b,c;
	printf("Enter three numbers: \n");
	scanf("%d %d %d",&a,&b,&c); //taking input

	printf("Biggest number out of %d, %d and %d is %d\n", a, b, c, biggest(a,b,c)); //calling the function 

	return 0;
}
