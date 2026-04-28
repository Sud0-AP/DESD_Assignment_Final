//To check if the given matrix is identity or not 
//PRN: 260240130005 and 260240130032

#include <stdio.h>
//function to check if the input matrix is an identity matrix or not
int checkIdentityMat(int row, int col, int arr[row][col]){
	int isIdentity = 1;

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if((arr[i][j] != 1) && (i==j))
				isIdentity = 0;
			else if((i!=j) && (arr[i][j] != 0))
				isIdentity = 0;
		}
	}

	return isIdentity;
}
//function to take user input into an array
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
//taking user input
	printf("Enter the number of rows: ");
	scanf("%d", &row);

	printf("Enter the number of columns: ");
	scanf("%d", &col);
//function call if row = column condition satisfies 
	if (row == col){
		int arr[row][col];
		inputArray(row,col,arr);
		checkIdentityMat(row,col,arr)?(printf("The given Matrix is an Identity matrix!!\n")):(printf("The given matrix is not an Identity Matrix\n"));

	}else{
		printf("The given matrix is not an Identity Matrix\n");
	}

	return 0;

}
