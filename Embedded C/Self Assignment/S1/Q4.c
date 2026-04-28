//To check if the input number is positive negative or zero 

#include<stdio.h>

int main(){
    int num;

    printf("Enter a number:");
    scanf("%d", &num); // take user input 

    if (num > 0){ // if the number is greater than 0 then it is a positive number
        printf("The number is a positive number.");
    }else if (num < 0){ // if the number is less than 0 then it is negative 
        printf("The number is a negative number.");
    }else { // otherwise if it is equal to zero then it is 0
        printf("The Number is Zero.");
    }
    return 0;
}
