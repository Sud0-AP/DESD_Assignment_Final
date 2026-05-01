//PRN: 260240130005 260240130032
//count the duplicates in an array

#include <stdio.h>

int count_duplicates(int [], int);
int element_in_array(int [], int, int);
void input_array(int [], int);

int main(){
	int size;
	printf("Enter the size of array: ");
	scanf("%d", &size);
	
	int array[size];

	input_array(array, size);

	printf("Number of unique duplicate elements in the array = %d\n", count_duplicates(array, size));

	return 0;

}
void input_array(int arr[], int size){
	for(int i=0 ; i<size ; i++){
		printf("Enter element at index %d :", i);
		scanf("%d", &arr[i]);
	}
	printf("\n");
}

//counting number of appreances of an element in the array
int element_in_array(int arr[], int size, int element){
	int count = 0;
	for(int i=0; i<size; i++){
		if(arr[i] == element){
			count++;
		}
	}

	return count;
}

int count_duplicates(int arr[], int size){
	int count=0;
	for(int i=0; i<size; i++){
		if(element_in_array(arr, size, arr[i]) > 1){ // if an element apprears more than once the increment the counter
			int temp = element_in_array(arr, i, arr[i]);  
			if(temp < 1){
				count++;
			}
		}
	}

	return count;
}


