//To test arithmetic operations on void pointers
//PRN: 260240130005 and 260240130032

#include <stdio.h>

int main(){
	int n = 10;
	int *number = &n ;

	void *nullptr;

	nullptr = number;

	printf("Printing number using void pointer before any operation: %d\n", *(int *)nullptr);

	*(int *)nullptr = *(int *)nullptr + 1;

	printf("Printing number using void pointer after incrementing: %d\n", *(int *)nullptr);

	return 0;
}
