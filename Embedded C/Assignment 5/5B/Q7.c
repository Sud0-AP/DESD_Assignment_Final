// Find determinant of the given matrix
// PRN: 260240130005 260240130032

//#define DEBUG 1

#include <stdio.h>
//fucntions to print an array and take input 
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
			printf("Enter element at index [%d]x[%d]: ", i,j);
			scanf(" %d", &arr[i][j]);
		}
	}

}
//fucntion to calculate the determinant of a 2X2 matrix
int calDeterminant_2X2(int arr[2][2]){
#ifdef DEBUG
	printf("\nArray input to 2x2 determinant calculator:\n");
	printArray(2,2,arr);
	printf("\n---------Determinant: %d--------\n",  (arr[0][0]*arr[1][1]) - (arr[0][1]*arr[1][0]));
#endif
	return (arr[0][0]*arr[1][1]) - (arr[0][1]*arr[1][0]);
}

//function to deduce the minor matrix based on input column number
void calMinorMat(int index, int side, int arr[side][side], int res[side-1][side-1]){
	int *ptr = &res[0][0];
	for (int i=0; i<side; i++){
		for (int j=0; j<side; j++){
			if(i!=0 && j!=index){
				*ptr = arr[i][j];
#ifdef DEBUG
				printf("Result at wtv index = %d\n", *ptr);
#endif
				ptr++;
			}
		}
	}

#ifdef DEBUG
	printf("\nsmaller matrix:\n");
	printArray(side-1, side-1, res);
	printf("----------\n");
#endif
}
//function to calculate the determinant of a 3X3 matrix
int calDeterminant(int side, int arr[side][side]){
	int final = 0;
	if( side == 2 ){
		return calDeterminant_2X2(arr);
	}

	for(int i=0; i<side; i++){
		int minorMat[side-1][side-1];
		calMinorMat(i,side,arr,minorMat);
		final = final + (arr[0][i] * (((i%2 == 0)?1:-1) * calDeterminant(side-1,minorMat)));
#ifdef DEBUG
		printf("\n final at %d = %d \n", i, final);
#endif
	}
	
	return final;
}


int main(){
	int side;
//taking user input
	printf("Enter dimension of the array of which you want to calculate the determinant of: \n");
	printf("Lenght of Side: (Array dimension L x L) ");
	scanf("%d", &side);

	int arr[side][side];

	inputArray(side,side,arr);
//function call
	printf("Determinant of the given matrix = %d\n", calDeterminant(side, arr));

	return 0;
}
