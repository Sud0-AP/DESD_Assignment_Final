//To solve a Linear equation using matrices
//PRN: 260240130005 and 260240130032

#define DEBUG 1

#include <stdio.h>

// function initialization for solving equations
void linearEquationSolve_2();
void linearEquationSolve_3();

// general usage fuctions for taking array input and printing
void printFloatArray(int row, int col, float arr[row][col]){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("%0.2f ", arr[i][j]);
		}
		printf("\n");
	}
}

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

// functions to do operation on arrays with float data type
void multiplyArrays_float(int row1, int col1, float arr1[row1][col1],int row2, int col2, int arr2[row2][col2], float result[row1][col2]){
	if (col1 == row2){
		for(int i=0 ; i<row1 ; i++){
			for(int j=0; j<col2 ; j++){
				result[i][j] = 0.0;
				for(int k=0; k<col1; k++){
					result[i][j] += arr1[i][k] * ((float)arr2[k][j]);
				}
#ifdef DEBUG
					printf("\n--------Matrix Multiplication A_inv x B----------\n");
					printf("------------------[%d][%d] = %f-------------------", i, j, result[i][j]);
					printf("\n--------------------------------------------------\n");
#endif
			}
		}
	}else {
		printf("Multiplication Not Possible columns of first matrix not equal to rows of second matrix\n");
	}

}

void multiplyArrayFloat(int row, int col, float result[row][col], float arr[row][col], float num){
#ifdef DEBUG
	printf("\n---------1 div by determinant %f----------\n", num );
#endif
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			result[i][j] = (float)arr[i][j] * num;
		}
	}
}

//helper functions to calculate for 2 variable equations

int calDeterminant_2X2(int arr[2][2]){
#ifdef DEBUG
	printf("\n---------Determinant: %d--------\n",  (arr[0][0]*arr[1][1]) - (arr[0][1]*arr[1][0]));
#endif
	return (arr[0][0]*arr[1][1]) - (arr[0][1]*arr[1][0]);
}

void calAdjoint_2X2(int arr[2][2], float result[2][2]){
	result[0][0] = arr[1][1];	result[0][1] = - arr[0][1];
	result[1][0] = - arr[1][0];	result[1][1] = arr[0][0];

#ifdef DEBUG
	printf("\n---------Adjoint---------\n");
	printFloatArray(2, 2, result);
	printf("-------------------------");
#endif
}

void calInverse_2X2(int arr[2][2], float result[2][2]){
	calAdjoint_2X2(arr, result);
	multiplyArrayFloat(2, 2, result, result, (float)(1.0/(float)calDeterminant_2X2(arr)));
#ifdef DEBUG
	printf("\n---------Inverse----------\n");
	printFloatArray(2, 2, result);
	printf("--------------------------");
#endif
}

// helper functions to calculate for 3 variable equations

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

int calDeterminant_3X3(int side, int arr[side][side]){
	int final = 0;
	if( side == 2 ){
		return calDeterminant_2X2(arr);
	}

	for(int i=0; i<side; i++){
		int minorMat[side-1][side-1];
		calMinorMat(i,side,arr,minorMat);
		final = final + (arr[0][i] * (((i%2 == 0)?1:-1) * calDeterminant_3X3(side-1,minorMat)));
#ifdef DEBUG
		printf("\n final at %d = %d \n", i, final);
#endif
	}
	
	return final;
}
//generate 3 matrix with columns replaced with constant values
void genVariableDeterminantMat_3X3(int Dx[3][3], int Dy[3][3], int Dz[3][3], int A[3][3], int B[3][1]){
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			switch(j){
				case 0:
					Dx[i][j] = B[i][0];
					Dy[i][j] = A[i][j];
					Dz[i][j] = A[i][j];
					break;
				case 1:
					Dy[i][j] = B[i][0];
					Dx[i][j] = A[i][j];
					Dz[i][j] = A[i][j];
					break;
				case 2:
					Dz[i][j] = B[i][0];
					Dx[i][j] = A[i][j];
					Dy[i][j] = A[i][j];
					break;
			}
		}
	}
}



int main(){

	int choice;

	printf("How many variables do you need to solve?\n(Enter 1) 2 Variables X and Y\n(Enter 2) 3 Variables X, Y and Z\nEnter choice: ");
	scanf("%d",&choice);
	printf("\n");
	
	if(choice == 1){
		linearEquationSolve_2();
	}else if(choice == 2){
		linearEquationSolve_3();
	}

	return 0;

}

void linearEquationSolve_2(){
	int A[2][2];
	int B[2][1];
	float X[2][1];
//taking user input
	printf("Enter the Coefficiants of the linear equations:\nConsider index[0][0] as coefficiant of X in equation 1, [0][1] as coefficiant of Y in equation 1\nConsider index[1][0] as coefficiant of X in equation 2, [1][1] as coefficiant of Y in equation 2\n");
	
	inputArray(2, 2, A);
	
	printf("\nEnter the constant terms of the linear equation:\nConsider index[0][0] as constant term of equation 1\nConsider index[1][0] as the constant term of equation 2\n");

	inputArray(2, 1, B);

	printf("\nThe equation entred is:\nEquation 1: (%d)x + (%d)y = %d\nEquation 2: (%d)x + (%d)y = %d\n", A[0][0], A[0][1], B[0][0], A[1][0], A[1][1], B[1][0] );

//calculation logic step by step using helper functions defined earlier
	float A_inv[2][2];

	calInverse_2X2(A,A_inv);

	multiplyArrays_float(2, 2, A_inv, 2, 1, B, X);

	printf("\nAfter solving the equation Result for X = %0.2f, Y = %0.2f\n", X[0][0], X[1][0]);

}

void linearEquationSolve_3(){
	int A[3][3];
	int B[3][1];
//taking user input
	printf("Enter the Coefficiants of the linear equations:\nConsider index[0][0] as coefficiant of X in equation 1, [0][1] as coefficiant of Y in equation 1, [0][2] as coefficient of Z in equation 1\nConsider index[1][0] as coefficiant of X in equation 2, [1][1] as coefficiant of Y in equation 2 , [1][2] as coefficient of Z in equation 2\nConsider index[2][0] as coefficiant of X in equation 3, [2][1] as coefficiant of Y in equation 3 , [2][2] as coefficient of Z in equation 3\n");
	
	inputArray(3, 3, A);
	
	printf("\nEnter the constant terms of the linear equation:\nConsider index[0][0] as constant term of equation 1\nConsider index[1][0] as the constant term of equation 2\nConsider index[2][0] as the constant term of equation 3\n");

	inputArray(3, 1, B);

	printf("\nThe equation entred is:\nEquation 1: (%d)x + (%d)y + (%d)z = %d\nEquation 2: (%d)x + (%d)y + (%d)z = %d\nEquation 3: (%d)x + (%d)y + (%d)z = %d\n", A[0][0], A[0][1], A[0][2], B[0][0], A[1][0], A[1][1], A[1][2], B[1][0], A[2][0], A[2][1], A[2][2], B[2][0]);
//calculation logic step by step using helper functions defined earlier
	int det_Coefficients = calDeterminant_3X3(3, A);

#ifdef DEBUG
	printf("\n-----Coefficient matrix-----\n");
	printArray(3,3,A);
	printf("\n----------------------------\n");

	printf("Determinant of coefficient matrix: %d\n", det_Coefficients);
#endif

	if (det_Coefficients == 0){
		printf("No real solutions available!! \n");
		return;
	}

	int Dx[3][3], Dy[3][3], Dz[3][3];

	genVariableDeterminantMat_3X3(Dx, Dy, Dz, A, B);

#ifdef DEBUG
	printf("\n---Dx---\n");
	printArray(3,3,Dx);
	printf("\n--------\n");

	printf("\n---Dy---\n");
	printArray(3,3,Dy);
	printf("\n--------\n");

	printf("\n---Dz---\n");
	printArray(3,3,Dz);
	printf("\n--------\n");
#endif

	float x = ((float) calDeterminant_3X3(3, Dx)) / ((float)det_Coefficients);
	float y = ((float) calDeterminant_3X3(3, Dy)) / ((float)det_Coefficients);
	float z = ((float) calDeterminant_3X3(3, Dz)) / ((float)det_Coefficients);

	printf("\nAfter solving the equation Result for X = %0.2f, Y = %0.2f, Z = %0.2f\n", x, y, z);

}
