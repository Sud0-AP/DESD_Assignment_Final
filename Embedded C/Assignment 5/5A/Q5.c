//Transpose a matrix
//PRN: 260240130005 and 260240130032

#include<stdio.h>
//funcion to print an array and to take input
void printArray(int row, int col, int arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void inputArray(int row, int col, int arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("Enter element at index [%d]x[%d]", i,j);
			scanf(" %d", &arr[i][j]);
		}
	}

}
//function to calculate the transpose of an array and store it in an seprate array
void transposeArray(int row, int col, int arr[row][col], int tpose[col][row]){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			tpose[j][i] = arr[i][j];
		}
	}
}


int main ()
{
	int row, column;
//taking user input
	printf("Enter the dimension of the arrays: \n");
	printf("Rows = ");
	scanf("%d", &row);

	printf("Columns = ");
	scanf("%d", &column);
//initializing arrays based on input from user
	int arr[row][column], transpose[column][row];

	inputArray(row,column,arr);
//function calls
	transposeArray(row,column,arr,transpose);

	printf("Transpose of the given array: \n");

	printArray(column, row, transpose);
	return 0;
}
