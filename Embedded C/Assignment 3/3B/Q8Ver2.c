//Counting the number of zeros and ones in a given binary number  
// PRN: 260240130005 and 260240130032
#include <stdio.h>

void count_ones_zeros(long x){
	static int count0 = 0, count1 = 0; //initializing the count variables

	if(x==0){ // base case when all ones and zeros are counted and the number is stripped till the last digit
		printf("Number of Ones: %d\n", count1);
		printf("Number of Zeros: %d\n", count0);
		return;
	}

	if (x%10 == 0){ //if the current last digit is equal to 0 
		count0 += 1; // increment the zeros counter
	}
	else if (x%10 == 1){ //if the current last digit is equal to 1
		count1 += 1; // increment the ones counter
	}

	count_ones_zeros(x/10); //recursive call with last digit stripped

	
}

int main (){
	long num; //using long instead of int as binary numbers can have more digits to represent comparitively small numbers

	printf("Enter a binary number :");

	scanf("%ld", &num); //taking input from user

	count_ones_zeros(num); //calling the function

	return 0;
}
