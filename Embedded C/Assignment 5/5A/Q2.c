// to sum two arrays
//PRN: 260240130005 and 260240130032
#include <stdio.h>
//function to print the array
void printArray(int arr[], int size){
	for(int i=0 ; i<size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//fucntion to add two arrays
void addArray(int arr1[], int arr2[],int size,int result[]){
	for(int i=0; i<size ; i++){
		result[i] = arr1[i] + arr2[i];
	}

}

int main ()
{
	int size;
	printf("Enter the size of arrays: ");
	scanf("%d", &size);
// initializing arrays with the size input from user
	int arr1[size], arr2[size], result[size];

//taking input in the arrays
	for(int i=0; i<size; i++){
		printf("Enter element at index %d for Array 1: ", i);
		scanf("%d", &arr1[i]);
	}

	for(int i=0; i<size; i++){
		printf("Enter element at index %d for Array 2: ", i);
		scanf("%d", &arr2[i]);
	}
//function call
	addArray(arr1, arr2, size, result);

	printf("\nResult after addition: ");
	printArray(result, size);

	return 0;

}

