// swapping two numbers without a third variable using XOR variable
// PRN: 260240130005 and 260240130032

#include <stdio.h>

void swap_xor(int a, int b){
	printf("Before swap A = %d , B = %d", a,b); // 
	a ^= b ^=a ^=b; 
	printf("\nAfter swap A = %d , B = %d\n", a,b);
}

int main(){
	int num1,num2;

	printf("Enter two numbers: "); // Input by the user
	scanf("%d %d", &num1, &num2);

	swap_xor(num1, num2); // Swaping the numbers 

	return 0;
}
