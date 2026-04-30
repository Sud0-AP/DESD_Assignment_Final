//Implement bubble sort, selection sort, insertion sort
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int);
void selectionSort(int *, int);
void insertionSort(int *, int);

void printArray(int *, int);
void insertArray(int *, int);

void swap(int *, int *);

int main(){
	int size, choice;

	printf("Enter size of array: ");
	scanf("%d", &size);

	int arr[size];

	insertArray(arr, size);

	printf("Current State of Array:\n");

	printArray(arr, size);

	printf("Enter method of sorting:\n(Enter 1) Bubble Sort\n(Enter 2) Selection Sort\n(Enter 3) Insertion Sort\n");
	scanf("%d", &choice);

	switch(choice){

		case 1:
			printf("Using Bubble sort: \n");
			bubbleSort(arr, size);
			break;
		case 2:
			printf("Using Selection sort: \n");
			selectionSort(arr, size);
			break;
		case 3:
			printf("Using Insertion sort: \n");
			insertionSort(arr, size);
			break;

	}
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

void selectionSort(int *arr, int size){
	if(size < 2){
		return;
	}
	int *min = arr;
	for(int i=0; i<size; i++){
		if(*(arr+i) < *min){
			min = (arr+i);
		}
	}
	if(*arr != *min) 
		swap(arr, min);
	selectionSort((arr+1), size-1);
}

void insertionSort(int *arr, int size){
	if(size < 2){
		return;
	}
	for(int i=0; i<size; i++){
		if(*(arr+i) > *(arr+i+1)){
			swap(arr+i, arr+i+1);
		}
	}
	insertionSort(arr, size-1);
}

void swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
