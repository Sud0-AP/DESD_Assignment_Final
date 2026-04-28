// calculate the sum of n numbers 

#include <stdio.h>

int calSum(int x[], int size){
	int sum = 0;

	for(int i = 0; i < size ; i++){ // iterating through the array one by one 
		sum += x[i]; // adding elements of the array together
	}

	return sum;
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
