//Conversions between int* and const int* while passing them as parameters
//PRN: 260240130005 and 260240130032

#include <stdio.h>

void normal_value(int p){
	printf("Before adding 10 %d\n", p);

	p = p + 10;

	printf("After adding 10 %d\n", p);
}

void pointer_value(int *p){
	printf("Pointer value without before adding 10 %d\n", *p);

	*p = *p + 10;
}

void constant_value(const int *p){
	printf("Constant value inputted %ls\n", *p);
}


int main(){
	int num1 = 56;

	const int num2 = 10;

	printf("Normal value in normal input adding 10 and printing it: \n");
	normal_value(num1);
	printf("Constant in normal input adding 10 and giving error: \n");
	normal_value(num2);
	
	printf("Normal value in pointer input adding 10 and printing it: \n");
	pointer_value(&num1);
	printf("constant value in pointer input adding 10 and giving error\n");
	pointer_value(&num2);
	printf("Value after adding 10 = %d\n", num1);

	printf("Normal value in constant input adding 10 and printing it: \n");
	constant_value(num1);
	printf("constant value in constant input adding 10 and printing it: \n");
	constant_value(num2);

	return 0;
}
