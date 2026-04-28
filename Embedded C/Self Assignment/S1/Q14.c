// To print the sum of all the odd numbers from 1 to N
#include<stdio.h>

int main(){
        int n, i, sum = 0;

    printf("Enter the number till which you want to print sum of odd numbers:");
    scanf("%d", &n); // tkaing user input

    for(i = 1; i <= n; i++) { // iterating through all the numbers from 1 to N
        if( i % 2!= 0){ // if the number is not divisible by 2 i.e. it is odd
            sum += i; // add it to the result varialbe
        }
    }
    printf("The sum of Odd Number are: %d\n", sum); // print the final sum
    
    return 0;
}
