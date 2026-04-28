// Find trace of the given matrix
//PRN: 260240130005 and 260240130032

#include <stdio.h>
//function to take input from user
void inputArray(int row, int col, int arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("Enter element at index [%d]x[%d]: ", i,j);
			scanf(" %d", &arr[i][j]);
		}
	}

}
//function to calculate the trace of an matrix
int calculateTrace(int side, int arr[side][side]){
	int trace=0;
	for(int i=0 ; i<side ; i++){
		trace += arr[i][i];	
	}

	return trace;
}



int main(){
	int side;
//taking user input
	printf("Enter dimension of the array (Trace can only be computed from a square matrix)\n");
	printf("Lenght of Side: (Array dimension L x L) ");
	scanf("%d", &side);

	int arr[side][side];

	inputArray(side,side,arr);
//function call
	printf("Trace of the given matrix is : %d\n",calculateTrace(side,arr));

	return 0;
}
