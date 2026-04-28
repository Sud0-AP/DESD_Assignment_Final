//To check if the given matrix is identity or not 
//PRN: 260240130005 and 260240130032

#include <stdio.h>
//function to check if the input matrix is Null matrix
int checkNullMat(int row, int col, int arr[row][col]){
	int isNull = 1;

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(arr[i][j] != 0)
				isNull = 0;
		}
	}

	return isNull;
}
//function to take user input to an array
void inputArray(int row, int col, int arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("Enter element at index [%d]x[%d]", i,j);
			scanf(" %d", &arr[i][j]);
		}
	}

}


int main() {

	int row, col;
//take user input
	printf("Enter the number of rows: ");
	scanf("%d", &row);

	printf("Enter the number of columns: ");
	scanf("%d", &col);
	
	int arr[row][col];
	inputArray(row,col,arr);
//function call
	checkNullMat(row,col,arr)?(printf("The given Matrix is an Null matrix!!\n")):(printf("The given matrix is not an Null Matrix\n"));
	
	return 0;

}
