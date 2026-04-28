//Access 2D array using pointers
//PRN 260240130005 and 260240130032

#include <stdio.h>
int main(){
	int arr[3][4] = {{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12}};

	int (*p)[4];
	p = arr;

	printf("Size of p %ld\n", sizeof(p));
	printf("Size of *p %ld\n", sizeof(*p));
	printf("Size of **p %ld\n\n", sizeof(**p));
	printf("Value of p: %p\n", p);
	printf("Value of p+1: %p\n\n", p+1);

	printf("Printing the array using index: \n");
	for(int i = 0; i<3; i++){
		for(int j = 0; j<4; j++){
			printf("%d ", arr[i][j]);
		}
	}

	printf("\n\nPrinting the array using (*(p+i))[j]: \n");
	for(int i = 0; i<3; i++){
		for(int j = 0; j<4; j++){
			printf("%d ", (*(p+i))[j]);
		}
	}

	printf("\n\nPrinting the array using *(*(p+i)+j): \n");
	for(int i = 0; i<3; i++){
		for(int j = 0; j<4; j++){
			printf("%d ", *(*(p+i)+j));
		}
	}

	printf("\n");

}
