// Program to Add, Subtract, Multiply two matrices 
//PRN: 260240130005 and 260240130032

#include <stdio.h>
//function to print an array
void printArray(int row, int col, int arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
//function to take input from user and store them in an array
void inputArray(int row, int col, int arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("Enter element at index [%d]x[%d]", i,j);
			scanf(" %d", &arr[i][j]);
		}
	}

}
//function to add two array
void addArray(int row, int col, int result[row][col],int arr1[row][col], int arr2[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			result[i][j] = arr1[i][j] + arr2[i][j];
		}
	}

}
//function to subtract two arrays
void subtractArray(int row, int col, int result[row][col],int arr1[row][col], int arr2[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			result[i][j] = arr1[i][j] - arr2[i][j];
		}
	}

}
//function to multiply two arrays
void multiplyArray(int row, int col, int result[row][col],int arr1[row][col], int arr2[row][col]){
	for(int i=0 ; i<=row ; i++){
		for(int j=0; j<=col ; j++){
			result[i][j] = 0;

			for(int k=0; k<col; k++){
				result[i][j] += arr1[i][k] * arr2[k][j]; 
			}
		}
	}

}

int main ()
{
	int row, column, choice;
	
	printf("What do you wish to perform? \n(Press 1) Addition \n(Press 2) Substraction\n(Press 3) Multiplication :  ");
	scanf("%d", &choice);
//taking user input
	if((choice == 1) || (choice == 2) || (choice == 3)){
	
	printf("Enter the dimension of the arrays: \n");
	printf("\nRows = ");
	scanf("%d", &row);

	printf("Columns = ");
	scanf("%d", &column);

	if(choice == 3 && (row != column)){	
		printf("Wrong Dimensions !! \n");
		return 0;
	}

	int arr1[row][column], arr2[row][column], result[row][column];

	printf("Enter elements for Array 1: \n");

	inputArray(row,column,arr1);
	
	printf("Enter elements for Array 2: \n");
	
	inputArray(row,column,arr2);
//fucntion calls based on user input
	if (choice == 1){
		printf("Addition of arrays: \n");
		addArray(row, column, result, arr1, arr2);
		printArray(row,column,result);
	}else if(choice == 2){
		printf("Subtraction of arrays: \n");
		subtractArray(row, column, result, arr1, arr2);
		printArray(row,column,result);
	}else if(choice == 3){
		printf("Multiplication of arrays: \n");
		multiplyArray(row, column, result, arr1, arr2);
		printArray(row,column,result);
	}
	}
	return 0;
}
