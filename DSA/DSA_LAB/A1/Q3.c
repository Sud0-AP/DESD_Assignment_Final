/* Write a C prog which allocate and deallocate memory dynamically 
 * (a) Allocating 1D array dynamically and access the elements
 * (b) Allocating 2D array dynamically
 * 	(1) Contiguous rows with fixed no. of cols
 * 	(2) Non contiguous rows with variable no. of cols
 * (c) Allocate memory for array of structure variables dynamically and access members of each elements.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
	int emp_id;
	char emp_name[30];
};

void input_array(int **, int, int);
void input_jagged_array(int **, int);

void print_array(int **, int, int);
void print_jagged_array(int **, int);

void take_employee_data(struct employee *, int);
void print_employee_data(struct employee *, int);

int main(){
	int row, col, n, choice;
	
	int *arr_1D, **arr_2D_non;
	
	printf("What type of array you wish to create?\n(Enter 1) 1D dynamic array\n(Enter 2) 2D Array with contigous memory allocation\n(Enter 3) 2D Array with non contiguous rows and variable no. of columns \n(Enter 4) Interact with an array of structure and input data then print it \n(Enter 5) Exit\n");
	scanf("%d", &choice);

	switch(choice){
		
		case 1:
			printf("Enter the size for 1D Array: ");
			scanf("%d", &n);
			arr_1D = (int *)malloc(sizeof(int) * (n));
			input_array(&arr_1D, 0, n);
			print_array(&arr_1D, 0, n);
			break;

		case 2:
			printf("Enter the number of rows for 2D contiguous array: ");
			scanf("%d", &row);

			printf("Enter the number of column for 2D contiguous array: ");
			scanf("%d", &col);

			int (*arr_2D_con)[col];
			arr_2D_con = (int (*)[])malloc(row * sizeof(*arr_2D_con));
			input_array(arr_2D_con, row, col);

			print_array(arr_2D_con, row, col);
			break;
		case 3:
			printf("Enter the numner of rows for the 2D non contigous array with variable columns: ");
			scanf("%d", &row);

			arr_2D_non = (int **)malloc(row*sizeof(int *));
	
			input_jagged_array(arr_2D_non, row);
			print_jagged_array(arr_2D_non, row);
			break;
		case 4:
			struct employee *emp_list;
			int num_emp;
			printf("Enter number of employees: \n");
			scanf("%d", &num_emp);
			emp_list = (struct employee *)malloc(num_emp * (sizeof(struct employee)));

			take_employee_data(emp_list, num_emp);

			print_employee_data(emp_list, num_emp);
			break;
		case 5:
			exit(1);
			return 0;
	}
}
void input_array(int **arr, int row, int col){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("Enter element at index [%d]x[%d]", i,j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void input_jagged_array(int **arr, int row){
	int col[row];
	for(int i=0 ; i<row ; i++){
		printf("Enter number of elements/columns at row %d", i);
		scanf("%d", &col[i]);
		arr[i] = malloc(col[i] * sizeof(int));
	}

	for (int i=0; i<row; i++){
		for(int j=0; j<col[i]; j++){
			printf("Enter element at index [%d]x[%d]", i,j);
			scanf(" %d", &arr[i][j]);
		}
	}
}


void print_jagged_array(int **arr, int row){
}
void printArray(int **arr, int row, int col){
	for(int i=0 ; i<row ; i++){
		for(int j=0; j<col ; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void take_employee_data(struct employee *emp_list, int num_emp){
	for(int i = 0; i<num_emp; i++){
		printf("Enter employee %d ID: ", i+1);
		scanf("%d", &(emp_list + i)->emp_id);

		printf("Enter employee %d name: ", i+1);
		scanf(" %[^\n]", (emp_list + i)->emp_name);

		printf("\n");
	}
}


void print_employee_data(struct employee *emp_list, int num_emp){
	for(int i = 0; i<num_emp; i++){
		printf("Employee %d ID: %d\n", i+1, (emp_list + i)->emp_id);
		printf("Employee %d Name: %s", i+1, (emp_list + i)->emp_name);	
	}
}

