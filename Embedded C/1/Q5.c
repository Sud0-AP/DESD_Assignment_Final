// check if the input year is a leap year
#include <stdio.h>

int main()
{
	int input_year; // input variable 

	printf("Enter a Year: \n");
	scanf("%d", &input_year); // taking input

	if(input_year % 4 == 0){ //checking if divisible by 4
		if(input_year % 100 == 0){ //checking if given year is a century year
			if (input_year % 400 ==0){ //checking if the given century year is divisible by 400
				printf("The year %d is a leap year!!\n", input_year); // the given year is a centruy year and a leap year
				return 0;
			}else {
				  printf("The year %d is not a leap year!!\n", input_year); // the given year is a century year but not a leap year
				  return 0;
			}
		}else {
			printf("The year %d is a leap year!!\n", input_year); // the given year is not a century year but a leap year
			return 0;
		}
	}

	printf("The year %d is not a leap year!!\n", input_year); // the given year is not divisible by 4 i.e. not a leap year

	return 0;
}
