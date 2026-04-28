//To give grades for the input marks 
 
#include <stdio.h>

int main() {
    int marks;

    
    printf("Enter your marks (0-100): ");
    scanf("%d", &marks); // taking user input for marks

    
    if (marks < 0 || marks > 100) {
        printf("Invalid input. Please enter a value between 0 and 100.\n");
    } // checking if the input is valid
    
    else if (marks >= 90) { // if marks is greater than or equal to 90 then give grade A 
        printf("Grade: A\n");
    } 
    else if (marks >= 75) { // if marks is greater than or equal to 75 then give grade B
        printf("Grade: B\n");
    } 
    else if (marks >= 60) { // if marks is greater than or equal to 60 then give grade C
        printf("Grade: C\n");
    } 
    else if (marks >= 50) { // if marks is greater than or equal to 50 then give grade D
        printf("Grade: D\n");
    } 
    else { // else fail
        printf("Grade: Fail\n");
    }

    return 0;
}
