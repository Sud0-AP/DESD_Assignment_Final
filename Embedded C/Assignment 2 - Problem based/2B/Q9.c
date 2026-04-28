// recursive sum of digits in a number

#include <stdio.h>

int sumOfDigits(int x){
	int temp, sum = 0;

	temp = x; //using a temporary variable to calculate sum of digits of the input variable

	while(temp>0){
		sum += temp % 10; //adding the unit digit of the temp variable to the sum
		temp = temp / 10; //removing the unit digit from the temp variable
	}

	if(x/10 > 0){ //if input number is more than one digit 
		return sumOfDigits(sum); // run the function again with the sum of digits
	}
	else
		return sum; // else return the final sum
}

int main(){
	int num;

	printf("Enter a number: ");
	scanf("%d",&num); // taking input

	printf("The result after recursively summing the digits of the input number %d =  %d\n", num, sumOfDigits(num));

	return 0;
}
