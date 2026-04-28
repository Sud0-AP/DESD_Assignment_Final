// Finding the day of week based on reference date, say 1 st january 1970 (Thursday)
// PRN: 260240130005 and 260240130032

#include <stdio.h>

int isLeapYear(int y){
	return ((y %4 == 0) && (y % 100 != 0)) || (y % 400 ==0); // checking if the entered year is a leap year or not by checking divisibilty with 4 and 100 or 400  
}

long int daysCalculate(int d, int m, int y){
	//initializing variables to calculate and store answers in
	long int days = 0;
	int day = 1;
	int year = 1970;
	int month = 1;

	for(int i = year; i < y ; i++){
		days += isLeapYear(i) ? 366 : 365; // adding number of days for the years
	}

	for (int j = 1; j < m ; j++){ // adding number of days per month in the current year
		if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12){ // checking if the current month is a month that has 31 days then add 31 days to the total 
			days += 31;
		}else if(j == 2 && isLeapYear(y)){ // checking if the month in current iteration is Feb i.e. 2nd month and the year is a leap year then add 29 days
			days += 29;
		}else if( j == 2 && !(isLeapYear(y)) ){ // if the month in current iteration is Feb and the year is not leap then add 28 days 
			days +=28;
		}else{ // if any other case i.e. months with 30 days then add 30 days
			days+=30;
		}
	}

	days += (d-1); // since we are calulating up to the given date so -1 from the total

	return days; // return the total calulated number of days

}

int main(){

	int day, month, year;
// taking user input for days, month and year
	printf("Enter the Day: ");
	scanf("%d", &day);

	printf("Enter the Month: ");
	scanf("%d", &month);

	printf("Enter the Year: ");
	scanf("%d", &year);

	if ( (day>31 || day<1) || (year<1970) || (month<1 || month>12) || (month == 2 && day > 29)){ // checking if the entered date is valid or not
		printf("Invalid date given!!\n");
		return 0;
	}else{
		printf("Total number of Days from 1/1/1970 to %d/%d/%d is %ld\n", day, month, year, daysCalculate(day,month,year) ); // function call
	}


	return 0;
}
