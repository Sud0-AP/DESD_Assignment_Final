//To check if the given year is leap year or not

#include<stdio.h>

int main()
{
    int a;

    printf("Enter a year :");
    scanf("%d", &a); //taking an input

    
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) //checking if the number is divisible 4 and 100 or divisible by 400 then it is a leap year
    {
        printf("The year %d is a Leap year!!\n", a);
    }
    else
    {
        printf("The year %d is not a leap year!!\n", a);
    }

    return 0;
}
