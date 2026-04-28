#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int);
void printArray(int *, int);
void insertArray(int *, int);
void swap(int *, int *);

int main(){
	int size;

	printf("Enter size of array: ");
	scanf("%d", &size);

	int arr[size];

	insertArray(arr, size);

	printf("Current State of Array:\n");

	printArray(arr, size);

	bubbleSort(arr, size);

	printf("After sorting: \n");

	printArray(arr, size);
}


void printArray(int *arr, int size){
	for(int i=0 ; i<size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertArray(int *arr, int size){
	for(int i=0 ; i<size ; i++){
		printf("Enter element at index [%d] : ", i);
		scanf("%d", &arr[i]);
	}
}

void bubbleSort(int *arr, int size){
	if(size<2){
		return;
	}

	for(int i=0 ; i<size-1; i++){
		if(*(arr+i) > *(arr+i+1)){
			swap(arr+i, arr+i+1);
		}
	}

	bubbleSort(arr, size-1);
}

void swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
