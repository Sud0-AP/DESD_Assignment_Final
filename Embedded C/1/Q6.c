// Calculate the sum and avg of n input numbers
#include <stdio.h>

int main()
{
	int n, sum, i, avg, temp; // initializing variables

	printf("Enter the # of numbers: ");
	scanf("%d",&n); // taking input of number of items to add

	sum = 0; // initializing sum variable with 0

	for (i=0; i<n ; i++){
		printf("\nEnter a number: "); 
		scanf("%d", &temp); // taking input in a temporary variable
		sum += temp; // adding sum + temp and storing it in sum variable
	}

	avg = sum/n; // calculating average

	printf("\nSum of the numbers is %d, the average of the numbers is %d \n", sum, avg);

	return 0;
}
