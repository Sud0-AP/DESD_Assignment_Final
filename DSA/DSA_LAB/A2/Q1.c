/* Write a c prog to implement linear search we need to check for duplicate inputs, 
 * if the duplicate elements is allowed then a linear search algo needs to implement accordingly. 
 * An appropiate condition check needs to apply for elements not found scenario.
 * (a) Search Element (Iterative Approach)
 * (b) Search Element (Recursion Approach)
 * (c) Print input array (Iterative Approach)
 * (d) Print input array (Recursion Approach)
 * (e) Print input array Reverse order (Iterative Approach)
 * (f) Print input array Reverse order (Recursion Approach)
 */

#include <stdio.h>

void search_recursive(int *, int, int);
int search_iterative(int [], int, int);
void print_recursive(int *, int, int);
void print_iterative(int [], int);
void print_reverse_recursive(int *, int);
void print_reverse_iterative(int [], int);

int main(){

	int array[5] = {1, 2, 3, 4, 5};

	search_recursive(array, 5, 2);
	search_iterative(array, 5, 3);
	print_recursive(array, 5, 0);
	print_iterative(array, 5);
	print_reverse_recursive(array, 5);
	print_reverse_iterative(array, 5);
	return 0;
}

void search_recursive(int *arr, int size, int value){
	if (size <= 0 && *arr != value){
		printf("Value not found in array!!\n");
		return;
	}

	if(*(arr+(size-1)) == value){
		printf("Value found at index %d\n", size-1);
		return;
	}else{
		search_recursive(arr, size-1, value);
	}
}

int search_iterative(int arr[], int size, int value){
	for(int i=0 ; i<size ; i++){
			if(arr[i] == value){
				printf("Element found at index %d\n", i);
				return i;
			}
		}
		printf("Element not found!!\n");
		return -1;
}


void print_reverse_recursive(int *arr, int size){
	if (size-1 <= 0){
		printf("%d\n", *(arr+(size-1)));
		return;
	}
	printf("%d ", *(arr+(size-1)));
	print_reverse_recursive(arr, size-1);
}
void print_recursive(int *arr, int size , int index){
	if (index >= size){
		printf("\n");
		return;
	}
	printf("%d ", *(arr+index));
	print_recursive(arr, size, index+1);
}

void print_iterative(int arr[], int size){
	for(int i=0 ; i<size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print_reverse_iterative(int arr[], int size){
	for(int i=size-1 ; i>=0 ; i--){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
