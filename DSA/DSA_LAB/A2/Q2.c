/* 
	PRN : 260240130005 , 260240130032
	
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
#include <stdio.h>

#define MAX_SIZE 100

//Function prototypes
void display_array(int *, int );
int binary_search_iterative(int *, int , int); 
int binary_search_recursive(int *, int , int , int );
void insert_sorted(int *, int *, int);
void display_menu(void);

int main(void)
{
	int arr[MAX_SIZE]; 
	int size, count = 0; // size = user-defined size, count = number of actual elements
	int choice, value, key;
	
	printf("====================================\n");
	printf("Sorted Array with Binary Search\n");
	printf("====================================\n\n");
	
	// Take array size from user
	printf("Enter the size of array (max %d): ", MAX_SIZE);
	scanf("%d", &size);
	
	if(size <= 0 || size > MAX_SIZE)
	{
		printf("\nInvalid size! Size must be between 1 and %d.\n", MAX_SIZE);
		return 1;
	}
	
	// Initialize all array elements with -99 (empty slot marker)
	for(int i = 0; i < size; i++)
	{
		arr[i] = -99;
	}
	
	printf("\nArray initialized with size %d. (Empty slots marked as -99)\n\n", size);
	
	while(1)
	{
		display_menu();
		printf("Enter your choice => ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				if(count >= size)
				{
					printf("\nArray is full! Cannot insert more elements.\n\n");
				}
				else
				{
					printf("Enter element to insert => ");
					scanf("%d", &value);
					
					// Prevent user from inserting -99 (reserved for empty slots)
					if(value == -99)
					{
						printf("\nError! -99 is reserved for empty slots. Cannot insert.\n\n");
					}
					else
					{
						insert_sorted(arr, &count, value);
					}
				}
				break;
				
			case 2:
				if(count == 0)
				{
					printf("\nArray is empty! No elements to display.\n\n");
				}
				else
				{
					printf("\nCurrent sorted array -> {");
					display_array(arr, count);
					printf(" }\n\n");
				}
				break;
				
			case 3:
				if(count == 0)
				{
					printf("\nArray is empty! Cannot search.\n\n");
				}
				else
				{
					printf("Enter value to search => ");
					scanf("%d", &key);
					
					printf("\n--Binary search using iterative approach---\n");
					int result_iterative = binary_search_iterative(arr, count, key);
					if(result_iterative == -1)
					{
						printf("Element does not exist in array.\n");
					}
					else
					{
						printf("Element found at index => %d\n", result_iterative);
					}
					
					printf("\n--Binary search using recursive approach---\n");
					int result_recursive = binary_search_recursive(arr, 0, count - 1, key);
					if(result_recursive == -1)
					{
						printf("Element does not exist in array.\n\n");
					}
					else
					{
						printf("Element found at index => %d\n\n", result_recursive);
					}
				}
				break;
				
			case 4:
				printf("\nExiting program...\n");
				return 0;
				
			default:
				printf("\nInvalid choice! Please try again.\n\n");
		}
	}
	
	return 0;
}//main

//Function to display menu
void display_menu(void)
{
	printf("--------MENU--------\n");
	printf("1. Insert element\n");
	printf("2. Display array\n");
	printf("3. Search element\n");
	printf("4. Exit\n");
	printf("--------------------\n");
}

//Function to display array
void display_array(int arr[], int len)
{
	for(int i=0; i<len; i++)
	{
		if(arr[i] != -99)  // Skip empty slots (-99)
		{
			printf(" %d", arr[i]); 
		}
	}
}

//Function to insert element in sorted order with duplicate check
void insert_sorted(int arr[], int *count, int value)
{
	// Check for duplicate using binary search
	int result = binary_search_iterative(arr, *count, value);
	
	if(result != -1)
	{
		printf("\nDuplicate element! %d already exists in array. Insertion discarded.\n\n", value);
		return;
	}
	
	// Find the correct position to insert
	int pos = *count;
	
	// Find position where value should be inserted to maintain sorted order
	for(int i = 0; i < *count; i++)
	{
		if(arr[i] > value)
		{
			pos = i;
			break;
		}
	}
	
	// Shift elements to the right to make space for insertion
	for(int i = *count; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	
	// Insert the element at the correct position
	arr[pos] = value;
	(*count)++; // Increment count
	
	printf("\nElement %d inserted successfully at index %d.\n", value, pos);
	printf("Current array -> {");
	display_array(arr, *count);
	printf(" }\n\n");
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
