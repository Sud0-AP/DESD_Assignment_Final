//Accessing array with suitable dereferencing of a pointer
//PRN: 260240130005 and 260240130032

#include <stdio.h>

int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	int (*parr)[5];

	parr = &arr;

	printf("Size of parr %ld\n", sizeof(parr));
	printf("Size of *parr %ld\n", sizeof(*parr));
	printf("Size of **parr %ld\n", sizeof(**parr));

	printf("Printing the array using parr: \n");
	for(int i = 0; i<(sizeof(arr)/sizeof(int)); i++){
		printf("%d ", (*parr)[i]);
	}

	printf("\n");

	return 0;
}

