//Perform polynomial evaluation where coefficients are stored in an array
//PRN: 260240130005 and 260240130032
#include <stdio.h>

int main(){
	int n, x, result;

	printf("Enter the number of terms in equation: ");
	scanf("%d", &n); //taking user input
	
	int a[n];

	printf("Enter value of x : ");
	scanf("%d", &x);

	for(int i=0; i<n; i++){
		printf("Enter coffecient for term number %d : ", i+1);
		scanf("%d", &a[i]);
	} //taking input for coefficients

	result = a[n-1]; // taking last element of array as result

	for(int i = n-2; i>=0 ; i--){
		result = result * x + a[i]; //evaluating result
	}

	printf("Result after polynomial evaluation = %d\n",result);

	return 0;

}
