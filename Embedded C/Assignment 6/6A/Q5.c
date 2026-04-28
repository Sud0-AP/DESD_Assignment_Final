//convert one type of pointer ot address to other using void*
//PRN: 260240130005 and 260240130032

#include <stdio.h>

int main(){
	int n = 10;
	char c = 'A';
	int *number = &n ;
	char *character = &c;
	void *nullptr;

	nullptr = number;
	printf("Printing number using void pointer: %d\n", *(int *)nullptr);

	nullptr = character;
	printf("Printing character using void pointer: %c\n", *(char *)nullptr);

	return 0;
}

