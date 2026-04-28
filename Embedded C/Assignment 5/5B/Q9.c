//Program to generate Identity and Null matrices
//PRN: 260240130005 and 260240130032

#include <stdio.h>
//fucntion to print an array 
void printArray(int row, int col, int arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//function to generate identity matrix
void generateIdentityMat(int row, int col, int arr[row][col]){
	for( int i=0; i<row; i++){
		for( int j=0; j<col; j++){
			if (i==j)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
}
//function to generate null matrix
void generateNullMat(int row, int col, int arr[row][col]){
	for( int i=0; i<row; i++){
		for( int j=0; j<col; j++){
			arr[i][j] = 0;
		}
	}
}


int main() {

	int row, col, choice;
//taking user input
	printf("What type of Matrix do you want to generate?\n(Press 1) Identity matrix\n(Press 2) Null matrix\nEnter choice: ");
	scanf("%d", &choice);
//displaying result based on choice
	if(choice == 1 || choice == 2){
		printf("Enter the number of rows: ");
		scanf("%d", &row);

		printf("Enter the number of columns: ");
		scanf("%d", &col);

		int arr[row][col];

		if(choice == 1){
			if (row!=col)
				printf("Can't generate identity matrix, given dimensions dosen't correrspond to a square matrix!!\n");
			else{
			generateIdentityMat(row,col,arr);
			printArray(row,col,arr);
			}
		}else if(choice == 2){
			generateNullMat(row,col,arr);
			printArray(row,col,arr);
		}
	}

	return 0;

	
}
