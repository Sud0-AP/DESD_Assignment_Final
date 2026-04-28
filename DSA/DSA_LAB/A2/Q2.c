#include <stdio.h>

int findPivot(int *, int);
void binarySearch(int *, int, int, int);


int main(){	
		
	int SIZE=0;
	int array1[SIZE];
	
	printf("Enter the size of array: ");
	scanf("%d", &SIZE);

	int target;
	int pivot = findPivot(array1, SIZE);

	for(int i=0; i<SIZE; i++){
		printf("Enter Value:\n ");
		scanf("%d",&array1[i]);
	}

	printf("\n");

	printf("Enter Target: ");
	scanf("%d", &target);

	if(target > array1[0]){	
		binarySearch(array1, 0, pivot, target);
	}else if(target == array1[0]){
		printf("%d\n", 0);
	}else {
		binarySearch(array1, 0, SIZE, target);
	}
	return 0;
}

int findPivot(int *arr, int size){
	int index;
	for(int i=0; i<size; i++){
		if(*(arr+i) > *(arr+i+1)){
			index = i;
			return index;
		}
	}
	return -1;
}


void binarySearch(int *arr, int start, int end, int element){
	int mid = (start+end)/2;

	if(arr[mid] == element){
		printf("%d\n", mid);
		return;
	}else if(element > arr[mid]){
		binarySearch(arr, mid+1, end, element);
	}else{
		binarySearch(arr, start, mid-1, element);
	}
}


