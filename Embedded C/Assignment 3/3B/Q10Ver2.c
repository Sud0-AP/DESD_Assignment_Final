//Counting the Digits of a number 
// PRN: 260240130005 and 260240130032
#include <stdio.h>

void count_digits(int x){
	static int count = 0; 

	if(x == 0){
		printf("Number of digits: %d\n", count);
		return; // return when end of number
	}

	count++; //counting the digits
	
	count_digits(x/10); //recursive call with reducing the number digit by digit

}

int main(){

	int num;

	printf("Enter a number : ");
	scanf("%d", &num); //taking input

	count_digits(num); //calling function

	return 0;

	
}
