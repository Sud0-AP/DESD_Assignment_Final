//To check if the given number is even or odd

#include <stdio.h>

int main()
{
    int a;

    printf("Enter a number :");
    scanf("%d", &a); // taking user input

    if(a%2 == 0) // check if the number is divisible by 2
    	printf("The number is an Even number.");

    else
    	printf("The number is an Odd number.");

    return 0;
}
