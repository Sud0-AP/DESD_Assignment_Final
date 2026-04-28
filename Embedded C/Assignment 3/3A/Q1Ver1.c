// Print an array in reverse and forward

#include <stdio.h>
//--------------Iterative version--------------


void printReverse (int x[], int size){
        printf("Reverse:\n");
        for (int i = size-1; i>=0 ; i--)
                printf("%d\n", x[i]);
}

void printForward (int x[], int size){
        printf("Forward:\n");
        for (int i = 0; i<size ; i++)
                printf("%d\n", x[i]);
}

int main(){

	int size;
	printf("Enter the size of array: ");
	scanf("%d",&size);

	int arr[size];

	for(int i = 0; i<size ; i++){
		printf("Enter element at index %d: ", i);
		scanf("%d",&arr[i]);
	}

	printForward(arr,size);
	printReverse(arr,size);

	return 0;

}
