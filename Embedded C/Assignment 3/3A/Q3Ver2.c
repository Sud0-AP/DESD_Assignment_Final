// Calculate the sum of n numbers

#include <stdio.h>

int calSum(int *x, int size){
	if (size <= 0){ // end case where we have reached the end of array
		return 0;
	}

	return *x + calSum(x+1, size-1); // add the current element pointed by the variable x and call the fucntion while decrementing the size variable and incementing the array pointer 
}

int main(){
	int size;
	printf("Enter the number of numbers you want to add: ");
	scanf("%d",&size); // taking input of the array size

	int arr[size]; // declaring the array

	for(int i = 0; i<size ; i++){
		printf("Enter number %d: ", i+1);
		scanf("%d",&arr[i]); // taking input of each element
	}
	
	printf("Sum: %d\n",calSum(arr, size)); // calling the function 


	return 0;
}
