//single function to return sum and product of two numbers
//PRN: 260240130005 and 260240130032

#include <stdio.h>

int sum_and_product(int x, int y, int *result){
	*result = x*y;
	return x+y;
}

int main(){
	int num1 = 10, num2 = 20, sum, prod;
	
	sum = sum_and_product(num1,num2,&prod);

	printf("Sum and Product of %d and %d -> Sum = %d, Product = %d\n", num1, num2, sum, prod);

	return 0;
}
