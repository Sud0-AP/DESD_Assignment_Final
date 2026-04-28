//To find the largest digit in the given number  

#include <stdio.h>

int main() {
    int num, digit, large = 0; //initializing variables 
    
    printf("Enter a number: ");
    scanf("%d", &num); //taking user input

    if (num < 0) {
        num = -num; //making the number +ve to avoid errors in calculation
    }

    
    while (num > 0) { // base case where we have iterated through all the digits of the given number
        digit = num % 10;     // storing the last digit of the number in a variable
        if (digit > large) { // then checking if the last digit is greater than the largest digit before this iteration
            large = digit;    // if it is larger then it is the new largest digit
        }
        num = num / 10;       // reducing the number one digit at a time
    }

    
    printf("Largest digit of the number is: %d\n", large); // print the largest digit 

    return 0;
}
