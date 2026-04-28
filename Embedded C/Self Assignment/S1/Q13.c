//To print sum of all the even numbers till N
#include<stdio.h>

int main(){
    int n, i,sum = 0;

    printf("Enter the number till which you want to print sum of even numbers:");
    scanf("%d", &n); //taking user input

    for(i = 1; i <= n; i++) { //iterating through all the numbers from 1 to N
        if( i % 2 == 0){ // if the number is divisible by 2 i.e. is an even number
            sum += i; //add it to the result variable
            }
    }

    printf("The sum of Even Number are: %d\n", sum); // print the result
    
    return 0;
}
