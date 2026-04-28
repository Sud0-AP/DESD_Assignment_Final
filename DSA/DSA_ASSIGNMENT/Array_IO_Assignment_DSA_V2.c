#include <stdio.h>

void init_array(int arr[], int size){
	for(int i=0 ; i<size ; i++){
		arr[i] = -99;
	}
}

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


void display(int arr[], int size){
	for(int i=0 ; i<size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

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

void delete_by_value(int arr[],int size, int val){
	int index = search(arr, size, val);
	if(index == -1){
		printf("Can't Delete the given value from array!!\n");
	}else{
		arr[index] = -99;
		printf("Element at index %d was deleted successfully!\n", index);
	}
}

void delete_by_index(int arr[], int size, int index){
	if((index < size) && (index > 0)){
		arr[index] = -99;
		printf("Element at index %d was deleted successfully!\n", index);
	}else{
		printf("Index entered is out of bounds!!\n");
	}
}

int main(){
	int size = 0, choice = 0;
	printf("Enter the size of array you want\n");
	scanf("%d", &size);

	int arr[size];
	init_array(arr, size);

 	int value = -99, index = -1;			

	while(1){
		printf("What operation do you wish to perform?\n");
		printf("(Enter 1) Display Array\n(Enter 2) Insert element in Array\n(Enter 3) Delete element in Array\n(Enter 4) Search element in Array\n(Enter 5) Exit\n");
		scanf("%d", &choice);

		if(choice < 1 || choice > 5){
			return 0;
		}

		switch(choice){
			case 1:
				printf("Current state of Array: \n");
				display(arr, size);
				break;
			case 2:
				printf("Enter the value and index at which you wish to insert: ");
				scanf("%d %d", &value, &index);
				insert(arr, size, value, index);
				break;
			case 3:
				printf("Do you wish to delete by element or index?? \n");
				printf("(Enter 1) By value\n(Enter 2) By index\n");
				int choice1 = 0;
				scanf("%d", &choice1);
				if(choice1<0 || choice1>2){
					printf("Invalid choice!!\n");
					break;
				}else if(choice1 == 1){
				//	int value = -99;
					printf("Enter the value which you wish to delete: ");
					scanf("%d", &value);
					delete_by_value(arr, size, value);
				}
				else if(choice1 == 2){
				//	int index = -1;
					printf("Enter the index at which you wish to delete an element: ");
					scanf("%d", &index);
					delete_by_index(arr, size, index);
				}
				break;
			case 4:
				//int value = -99;
				printf("Enter the value you want to search for: ");
				scanf("%d", &value);
				search(arr, size, value);
				break;
			case 5:
				return 0;
				break;
			
		}
	}
	return 0;
}


