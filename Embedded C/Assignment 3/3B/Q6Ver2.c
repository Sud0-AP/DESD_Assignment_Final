// Print the fibonacci series till n number
// PRN: 260240130005 and 260240130032
#include <stdio.h>

void nextFibonacci(int first, int second, int end){
	if (end <= 0) //when end of range is reached stop execution
		return;
	printf("%d ", first);
	nextFibonacci(second, first+second, end-1); // swapping the first with second and adding the first and second in place of second and reducing the end variable to keep track of end range	
}

int main ()
{
	// defining first 2 numbers  
	int end;
	int n_1= 1;
	int n_2= 0;

	//taking input for series print lenght
	printf("Enter the number of items to print of the fibonacci series: ");
	scanf("%d",&end);
	
	//function call
	nextFibonacci(n_2,n_1,end);	
	
	printf("\n");
	
	return 0;
	
}
