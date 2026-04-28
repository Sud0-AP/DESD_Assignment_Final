//To print the smallest digit of the given number
#include <stdio.h>

int main() {
    int num, digit, small; 
    
    printf("Enter a number: ");
    scanf("%d", &num); //taking user input

    if (num < 0) {
        num = -num; // checking if the given numebr is negative if yes the make it positive to avoid calculation errors
    }

    
    while (num > 0) { // base case where all digits have been traversed
        digit = num % 10;    // taking the last digit of the number
        if (digit < small) { // checking if the last digit is the smallest number till the current iteration
            small = digit;    // if it is then the current last digit is the smallest digit
        }
        num = num / 10;       // reduce the number digit by digit from the end
    }

    
    printf("Smallest digit of the number is: %d\n", small); //print the smallest digit at the end 

    return 0;
}
