//Swap two numbers with functions made using pass by value and pass by reference
//PRN: 260240130005 and 260240130032

#include <stdio.h>

void swap_reference(int *x, int *y){
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void swap_value(int x, int y){
	x = x + y;
	y = x - y;
	x = x - y;
	printf("After swapping using value: num 1 = %d, num 2 = %d\n", x, y);
}

int main(){
	int num1 = 10, num2 = 20;

	printf("Before any function calls: num 1 = %d, num 2 = %d\n", num1, num2);

	swap_reference(&num1, &num2);
	printf("After swapping using reference: num 1 = %d, num 2 = %d\n", num1, num2);
	
	swap_value(num1, num2);
	
	return 0;
}
