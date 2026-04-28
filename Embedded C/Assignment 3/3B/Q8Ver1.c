//Counting the number of zeros and ones in a given binary number  
// PRN: 260240130005 and 260240130032

#include <stdio.h>

void count_ones_zeros(long x){

	int ones=0, zeros=0; //initializing the count variables

	while(x != 0){ // base case when all ones and zeros are counted and the number is stripped till the last digit
		
		if (x%10 == 1){ //if the current last digit is equal to 1
			ones++; // increment the ones counter
		}
		else if (x%10 == 0){ //if the current last digit is equal to 0
			zeros++; // increment the zeros counter
		}
		else{
			printf("not binary!!"); //if input is not binary end execution
			return;
		}

		x = x/10; //stripping last digit with each while iteration
	}

	printf("Number of Ones in the given binary number is : %d\n", ones);
	printf("Number of Zeros in the given binary number is : %d\n", zeros);
}


int main (){
	long num; //using long instead of int as binary numbers can have more digits to represent comparitively small numbers

	printf("Enter a binary number :");

	scanf("%ld", &num); //taking input from user

	count_ones_zeros(num); //function call

	return 0;
}
