// Print the fibonacci series till n number
#include <stdio.h>

void nextFibonacci(int *a, int *b, int c){
	*a = *b;
	*b = c;
}

int main ()
{
	// defining first 2 numbers  
	int n, end;
	int n_1= 1;
	int n_2= 0;

	//taking input for series print lenght
	printf("Enter the number of items to print of the fibonacci series: ");
	scanf("%d",&end);
	
	//case for when user wants to print series less than 3
	if (end <= 1){
		printf("1st number is: %d", n_2);	
	} else if (end ==2){
		printf("1st number is: %d", n_2);
		printf("\n2nd number is: %d", n_1);
	}else{ 
	
	// lenght greater than 3
	printf("1st number is: %d", n_2);
	printf("\n2nd number is: %d", n_1);
	
		for(int i= 2; i<end ; i++){
			n = n_1 + n_2;
			if (i==2)
				printf("\n%drd number is: %d", i+1, n);
			else
				printf("\n%dth number is: %d", i+1, n);
			//setting new n-1 and n-2 values
			nextFibonacci(&n_2,&n_1,n);
		}
	}
	
	printf("\n");
	
	return 0;
	
	}
