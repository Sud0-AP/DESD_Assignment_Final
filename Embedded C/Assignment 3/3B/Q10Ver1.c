//Counting the Digits of a number 
// PRN: 260240130005 and 260240130032
#include <stdio.h>

void count_digits(int x){
	int count = 0; 

	if(x<=0){
		return; // return when end of number
	}

	while(x!=0){
		count++; //counting the digits
		x = x/10; //reducing the number digit by digit
	}

	printf("\nNumber of digits: %d\n", count); // printing the count of digits at the end

}

int main(){

	int num;

	printf("Enter a number : ");
	scanf("%d", &num); //taking input

	count_digits(num); //calling function

	return 0;

	
}
