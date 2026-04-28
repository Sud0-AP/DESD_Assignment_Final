//PRN: 260240130005 260240130032
// C program to declare an array of length N containing integres between 1 and N, implement menu driven program using switch case:-
// insert element at index *
// delete element at index *
// find min val *
// find max val *
// display array element *
// reverse display array element *
// search element in array *
// array element count *
// avg of all array element *
// determine if array contains any duplicates *
// reverse array elements *


#include <stdio.h>
#include <stdlib.h>

//initialize array with elements as -99
void init_array(int arr[], int size);
//insert element at index
void insert(int arr[],int size, int value, int index);
//display array elements
void display(int arr[], int size);
//reverse display array elements
void reverse_display(int arr[], int size);
//search element in array
int search(int arr[],int size, int val);
//delete element by value
void delete_by_value(int arr[],int size, int val);
//delete element by index
void delete_by_index(int arr[], int size, int index);
//find minimum element 
int min_element(int arr[], int size);
//find maximum element
int max_element(int arr[], int size);
//array element count
int count_element(int arr[], int size);
//average of all array elements
float avg_array(int arr[], int size);
//find duplicates
void count_duplicates(int arr[], int size);
//reverse array
void reverse_array(int arr[], int size);

int main(){
	int size = 0, choice = 0, choice1 = 0, choice2 = 0;
	printf("Enter the size of array you want\n");
	scanf("%d", &size);

	int arr[size];
	init_array(arr, size);

 	int value = -99, index = -1;


	while(1){
		printf("What operation do you wish to perform?\n");
		printf("(Enter 1) Insert or Delete Elements\n(Enter 2) Search or Display elements\n(Enter 3) Perform Computations or operations\n(Enter 4) Exit\n");
		scanf("%d", &choice);

		if(choice < 1 || choice > 4){
			return 0;
		}

		switch(choice){
			case 1:
				printf("What do you wish to do? \n");
				printf("(Enter 1) Insert\n(Enter 2) Delete\n");
				choice1 = 0;
				scanf("%d", &choice1);
				if(choice1<1 || choice1>2){
					printf("Invalid choice!!\n");
					break;
				}else if(choice1 == 1){
					printf("Enter the Value and Index at which you wish to Insert: ");
					scanf("%d %d", &value, &index);
					insert(arr, size, value, index);
				}
				else if(choice1 == 2){
					choice2 = 0;
					printf("Delete element by:\n(Enter 1) by Value\n(Enter 2) by Index\n");
					scanf("%d", &choice2);
					if(choice2<1 || choice2>2){
						printf("Invalid choice!!\n");
						break;
					}else if(choice2 == 2){	
						printf("Enter the index at which you wish to delete an element: \n");
						scanf("%d", &index);
						delete_by_index(arr, size, index);
					}else if(choice2 == 1){	
						printf("Enter the element value which you wish to delete: \n");
						scanf("%d", &value);
						delete_by_value(arr, size, value);
					}
				}
				break;

			case 2:
				printf("What do you wish to perform:\n(Enter 1) Search element\n(Enter 2) Display Array\n(Enter 3) Display Array in reverse\n");
				choice1 = 0;
				scanf("%d", &choice1);
				if(choice1<1 || choice1>3){
					printf("Invalid choice!!\n");
					break;
				}
				switch(choice1){
					case 1:	
						printf("Enter the Value which you wish to Search: ");
						scanf("%d", &value);
						search(arr, size, value);
						break;
					case 2:
						printf("Current state of Array:\n");
						display(arr, size);
						break;
					case 3:
						printf("Current state of Array in reverse:\n");
						reverse_display(arr, size);
						break;
				}
				break;
			case 3:
				printf("What do you wish to perform:\n(Enter 1) Find Smallest element\n(Enter 2) Find Largest element\n(Enter 3) Find Average of elements in array\n(Enter 4) Get count of elements in Array\n(Enter 5) Find number of duplicates in array\n(Enter 6) Revese The array\n");
				choice1 = 0;
				scanf("%d", &choice1);
				if(choice1<1 || choice1>6){
					printf("Invalid choice!!\n");
					break;
				}
				switch(choice1){
					case 1:	
						min_element(arr, size);
						break;
					case 2:
						max_element(arr, size);
						break;
					case 3:
						avg_array(arr, size);
						break;
					case 4:
 						count_element(arr, size);
						break;
					case 5:
						count_duplicates(arr, size);
						break;
					case 6:
						reverse_array(arr, size);
						break;
				}

				break;
			case 4:
				exit(1);
				break;

		}
	}
	return 0;
}

//initialize array with elements as -99
void init_array(int arr[], int size){
	for(int i=0 ; i<size ; i++){
		arr[i] = -99;
	}
}

//insert element at index
void insert(int arr[],int size, int value, int index){
       if(index>=size || index <0){
	       printf("Index is out of bounds!!\n");
	       return;
       }
	if (arr[index] == -99){
		arr[index] = value;
		printf("Value at index %d set to %d\n", index, value);
	}else{
		printf("Already another value stored at the given index do you want to store in next available index? (enter Y/N)\n");
		char choice;
		scanf(" %c", &choice);
		if(choice == 'y'|| choice == 'Y'){
			for(int i = index; i<size ; i++){
				if(arr[i] == -99){
					arr[i] = value;
					printf("Value at index %d set to %d\n", i, value);
					break;
				}else if((i == size-1) && (arr[i] != -99)){
					printf("Going to the start of the array\n");
					for(int j = 0; j<index ; j++){
						if(arr[j] == -99){
							arr[j] = value;
							printf("Value at index %d set to %d\n", j, value);
							break;
						}else if((j == index-1) && (arr[j] != -99)){
							printf("No indexes available to insert the given element!!\n");
						}

					}
				}
			}
		}else{
			arr[index] = value;
			printf("Value at index %d replaced to %d\n", index, value);
		}
	}

}

//display array element
void display(int arr[], int size){
	for(int i=0 ; i<size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//reverse display array elements
void reverse_display(int arr[], int size){
	for(int i=size-1 ; i>=0 ; i--){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//search element in array
int search(int arr[],int size, int val){
	for(int i=0 ; i<size ; i++){
		if(arr[i] == val){
			printf("Element found at index %d\n", i);
			return i;
		}
	}
	printf("Element not found!!\n");
	return -1;
}

//delete element by value
void delete_by_value(int arr[],int size, int val){
	int index = search(arr, size, val);
	if(index == -1){
		printf("Can't Delete the given value from array!!\n");
	}else{
		arr[index] = -99;
		printf("Element at index %d was deleted successfully!\n", index);
	}
}

//delete element by index
void delete_by_index(int arr[], int size, int index){
	if((index < size) && (index > 0)){
		arr[index] = -99;
		printf("Element at index %d was deleted successfully!\n", index);
	}else{
		printf("Index entered is out of bounds!!\n");
	}
}

//array element count
int count_element(int arr[], int size){
	int count = 0;
	for(int i=0 ; i<size ; i++){
		if(arr[i] != -99){
			count++;
		}
	}
	printf("Number of elements present in the array = %d\n", count);
	return count;
}

//find minimum element 
int min_element(int arr[], int size){	
	int min = arr[0];
	for(int i=0 ; i<size ; i++){
		if(arr[i] < min){
			min = arr[i];
		}
	}
	printf("Smallest element in Array = %d\n", min);
	return min;
}


//find maximum element
int max_element(int arr[], int size){
	int max = arr[0];
	for(int i=0 ; i<size ; i++){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	printf("Largest element in Array = %d\n", max);
	return max;
}

//average of all array elements
float avg_array(int arr[], int size){
	int sum = 0;
	int num = 0;
	for(int i=0 ; i<size ; i++){
		if(arr[i] != -99){
			sum += arr[i];
			num++;
		}
	}
	printf("Average of elements in Array = %0.2f\n", (float)(sum/num));
	return (float)(sum/num);
}

//reverse array
void reverse_array(int arr[], int size){ 
	// iterating through the array using two index pointers one from the start one from the end
       	int first = 0;
	int last = size-1;
	int temp;

        while (first<last){ // while the two pointers have not crossed each other keep replacing last with first and vice versa
		temp = arr[first];
		arr[first] = arr[last];
		arr[last] = temp;

		last--;
		first++;
	}

}

//find duplicates
void count_duplicates(int arr[], int size){
	for(int i=0; i<size; i++){
		if(arr[i] != -99){
			int dup_num = 0;
			for(int j=0; j<size; j++){
				if( (j != i) && (arr[i] == arr[j])){
				 	dup_num++;
				}
			}
			if(dup_num != 0){
				printf("Number of duplicates for element %d = %d\n", arr[i], dup_num);
			}

		}
	}
}

