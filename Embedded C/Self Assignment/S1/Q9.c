//To check if the given number is divisible by both 3 and 5 or not  

#include<stdio.h>

int main(){
    int num;

    printf("Enter a number:");
    scanf("%d", &num); //taking user input

    if( num % 3 == 0 && num % 5 == 0){ // checking if it is divisible by 3 and 5 
        printf("The Number %d is divisible by both 3 and 5.\n", num);
    }else{ // if not then say is is not 
        printf("The Number %d is not Divisible by both 3 and 5\n", num);
    }
    return 0;
}
