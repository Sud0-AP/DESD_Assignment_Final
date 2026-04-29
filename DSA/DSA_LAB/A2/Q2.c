/* 
	PRN numbers -> 260240130002 , 260240130028
	
	Write a C/C++ program to implement Binary Search. We need to check for
	duplicate element inputs, if found any should not insert into the input
	array. The array should manage in sorted order. Apply a duplicacy check
	on the element while inserting the element, if found duplicate then
	discards the input. The input element should insert in the array at the
	right position( index). Appropriate shifting can be applied in the
	array in order to insert the input element at the right position. An
	appropriate condition check needs to apply for element not found
	scenario.

	(a) Binary Search ( iterative approach)
	(b) Binary Search ( recursion approach ) 
*/
#include<stdio.h>

//Function prototypes
void display_array(int *, int );
void sort(int *, int );
int binary_search_iterative(int *, int , int); 
int binary_search_recursive(int *, int , int , int );

int main(void)
{
	int arr[] = {50 , 30 , 34 , 23 , 63 , 47, 53 , 28, 69 , 36 , 85 , 10}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	
	int key;
	
	printf("Input array -> {");
	display_array(arr,size);
	printf(" }\n");
	 
	sort(arr,size);
	 
	printf("Sorted array -> {");
	display_array(arr,size);
	printf(" }\n"); 
	
	printf("\nEnter value to search => ");scanf("%d",&key); 
	
	printf("\n--Binary search using iterative approach---\n");
	
	if(binary_search_iterative(arr,size,key) == -1)
	{
		printf("\nElement does not exist in array.\n"); 
	}else{
		printf("\nElement found at index => %d\n", binary_search_iterative(arr,size,key)); 
	}
		
	printf("\n--Binary search using recursive approach---\n");
	
	if(binary_search_iterative(arr,size,key) == -1)
	{
		printf("\nElement does not exist in array.\n\n"); 
	}else{
		printf("\nElement found at index => %d\n\n", binary_search_iterative(arr,size,key)); 
	}
	
}//main

//Function to display array
void display_array(int arr[], int len)
{
	//("Array -> {"); 
	for(int i=0; i<len; i++)
	{
		printf(" %d", arr[i]); 
	}
	//printf(" }\n"); 
}

//Function to sort array into an ascending order
void sort(int *arr, int size) 
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++) 
		{
            		if (*(arr + j) > *(arr + j + 1)) 
            		{
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
            		}
        	}
    	}
}

//Function to find value in an array using binary search
int binary_search_iterative(int arr[], int len, int key)
{
	int high = len - 1, mid, low = 0;
	
	while(low <= high)
	{
		mid = low + (high-low)/2;
		
		if(arr[mid] == key)
		{
			return mid; 
		}
		if(arr[mid] < key)
		{
			low = mid + 1; 
		}
		if(arr[mid] > key)
		{
			high = mid - 1; 
		}
	}
	return -1; // Element not present
}

//  Binary search using recursive approach
int binary_search_recursive(int arr[], int low, int high, int target) 
{
	if(low <= high)
	{
		int mid = low + (high - low) / 2;

		if(arr[mid] == target)
		{
			return mid;
		}

		if(arr[mid] > target)
		{
			return binary_search_recursive(arr, low, mid - 1, target);
		}

		return binary_search_recursive(arr, mid + 1, high, target);	
	}


	return -1; // Element not present
}
