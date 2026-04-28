//To give print the multiplication table of the given number 

#include <stdio.h>

int main() {
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num); //taking user input

    printf("Multiplication Table of %d:\n", num);

    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    } //using a for loop to iterate from 1-10 and multiplying it by the given number

    return 0;
}
