/*
	PRN - 260240130005 , 260240130032 

	C program to allocate/deallocate memory dynamically. 
	(a)Allocating 1-D array dynamically
	(b)Allocting 2-D array dynamically
		1)Contiguous  rows 
		2)Non-contiguous rows 
	(c)Allocate memory for array of structure variables dynamically 
*/
#include <stdio.h> 
#include <stdlib.h>

typedef struct
{
	int num1; 
	int num2; 
}nums; 

int *create_1Darray(int );
int **create_2D_non_contiguous(int , int );
int **create_2D_contiguous(int , int );
void display_1Darray(int *, int ); 
void display_2Darray(int **, int , int); 
void free_2Darray(int ** , int , int); 
nums *create_structs(int );
int power(int ,int );
void display_structs(nums *, int ); 


int main(void) 
{
	int choice, n, r, c;
	int *arr1D = NULL, **arr2D=NULL;
	nums *structArr = NULL;
	
	int last_2D_mode = 0 , current_2D_rows = 0;;
    
	printf("\n--- Dynamic Memory Allocation ---\n"
					"1 -> Create 1-D Array\n"
					"2 -> Create 2-D Array (Non-Contiguous)\n"
					"3 -> Create 2-D Array (Contiguous)\n"
					"4 -> Create Struct Array\n"
					"5 -> Exit\n"); 

    while(1) {

        printf("\nChoice -> ");
        scanf("%d", &choice);
	
	
        switch(choice)
        {
		case 1:
			printf("Enter size: "); scanf("%d", &n);
			if(arr1D) free(arr1D);
			arr1D = create_1Darray(n);printf("\n"); 
			break;

		case 2:
			if (arr2D)
			{
				free_2Darray(arr2D, current_2D_rows, last_2D_mode);
				arr2D = NULL;
			}
			
			printf("Enter rows and cols: "); 
			scanf("%d %d", &r, &c);
			arr2D = create_2D_non_contiguous(r, c);

			current_2D_rows = r; 
			last_2D_mode = 1;
			break;

		case 3:
			printf("Enter rows and cols: "); scanf("%d %d", &r, &c);
			if(arr2D) free_2Darray(arr2D, r, last_2D_mode);
			arr2D = create_2D_contiguous(r, c);printf("\n");
			last_2D_mode = 2;
			break;

		case 4:
			printf("Enter number of structs: "); scanf("%d", &n);
			if(structArr) free(structArr);
			structArr = create_structs(n);printf("\n");
			display_structs(structArr , n);
			break;

		case 5:
			free(arr1D);
			printf("Ptr-1 Freed."); 
		
			free_2Darray(arr2D , r, last_2D_mode); 
			printf("Ptr-2 Freed."); 

			free(structArr); printf("\nPtr-3 Freed.\n");
			goto exit_loop_;

		default:
			printf("Invaild");
			break;
        }
    }
    
    exit_loop_ : printf("-----Exit-----\n");
}

//Function to display 1-D array
void display_1Darray(int *arr, int len)
{
	printf("Array -> {"); 
	for(int i=0; i<len; i++)
	{
		printf(" %d" , *(arr+i)); 
	}
	printf("}\n"); 
}



//Function to dynamically create a 1-D array of N elements 
int *create_1Darray(int len)
{
	int *arr = (int *)malloc(len * sizeof(int)); 
	
	for(int i=0; i<len; i++)
	{
		arr[i] = i+1; 
	}
	display_1Darray( arr , len); 
	return arr; 
}

//Function to display 2-D array
void display_2Darray(int **arr, int rows, int cols)
{
	printf("Matrix -->\n");
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			printf(" %d", *(*(arr+i)+j) );  
		}
		printf("\n"); 
	}
} 

// 2D Non-Contiguous: Each row is a separate malloc
int **create_2D_non_contiguous(int rows, int cols) 
{
	int **arr = (int **)malloc(rows * sizeof(int *));

	printf("\n2D Non-Contiguous Matrix:\n");

	for(int i=0; i<rows; i++) 
	{
		arr[i] = (int *)malloc(cols * sizeof(int));

		for(int j=0; j<cols; j++) 
		{
			arr[i][j] = i + j;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return arr;
}

// 2D Contiguous: One large block for all elements
int **create_2D_contiguous(int rows, int cols)
 {
	int **arr = (int **)malloc(rows * sizeof(int *));
	int *data = (int *)malloc(rows * cols * sizeof(int)); 

	printf("\n2D Contiguous Matrix:\n");

	for(int i=0; i<rows; i++)
	{
		arr[i] = data + (i * cols);
		for(int j=0; j<cols; j++) 
		{
			arr[i][j] = i + j;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return arr;
}

//Function to free memory 
void free_2Darray(int **arr, int rows, int mode) 
{
	if(!arr) return;
	
	if(mode == 2)
	{ 
		free(arr[0]); 
	}else if(mode == 1)
	{ 
		for(int i=0; i<rows; i++)
		{
			free(arr[i]); 
		}
	}
	free(arr); 
}

//Function to dynamically create a structure
nums *create_structs(int len)
{
	nums *s_ptr = (nums *)malloc(len * sizeof(nums)); 
	
	for(int i=0; i<len; i++)
	{
		if(s_ptr)
		{
			s_ptr[i].num1 = i+1; 
			s_ptr[i].num2 = power(i , 2); // values for num2 are squares of num1
		}
	}

	return s_ptr; 
}

//Function to calculate power
int power(int base ,int exp)
{
	int res = 0; 
	for(int i=0; i<exp; i++)
	{
		res += base;
	}
	return res; 
}

//Function to display structs
void display_structs(nums *s , int len)
{
	for(int i=0; i<len; i++)
	{
		printf("Struct %d ==> {%d , %d}\n",i ,(s+i)->num1, (s+i)->num2);
	}printf("\n");
}
