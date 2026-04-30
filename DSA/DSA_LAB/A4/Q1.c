//Merge sort, quick sort, heap sort
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int, int);
void quickSort(int *, int, int);
void heapSort(int *, int);

void printArray(int *, int);
void insertArray(int *, int);



int main(){
	int size, choice;

	printf("Enter size of array: ");
	scanf("%d", &size);

	int arr[size];

	insertArray(arr, size);

	printf("Current State of Array:\n");

	printArray(arr, size);

	printf("Enter method of sorting:\n(Enter 1) Merge Sort\n(Enter 2) Quick Sort\n(Enter 3) Heap Sort\n");
	scanf("%d", &choice);

	switch(choice){

		case 1:
			printf("Using Merge sort: \n");
			mergeSort(arr, 0, size-1);
			break;
		case 2:
			printf("Using Quick sort: \n");
			quickSort(arr, 0, size-1);
			break;
		case 3:
			printf("Using Heap sort: \n");
			heapSort(arr, size);
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

void merge(int *arr, int left, int mid, int right) {
	int i = left, j = mid + 1, k = 0;
	int temp[right - left + 1];
	
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	
	for (i = left, k = 0; i <= right; i++, k++) {
		arr[i] = temp[k];
	}
}

void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int partition(int *arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return i + 1;
}

void quickSort(int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void heapify(int *arr, int size, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}
	
	if (largest != i) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, size, largest);
	}
}

void heapSort(int *arr, int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}
	
	for (int i = size - 1; i > 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}
