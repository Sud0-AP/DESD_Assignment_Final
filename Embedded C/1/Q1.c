// Swapping two variables without using a third variable
#include <stdio.h>

int main ()
{       
        int a,b; //initalizing variables
        
        printf("Enter two numbers:");
        scanf("%d %d", &a, &b); // taking input

	printf("Entered Numbers: %d %d \n", a,b);
	
	//swapping numbers logic
        a = a + b;
        b = a - b;
        a = a - b;
        
        printf("Swapped numbers: %d %d \n", a, b);

	return 0;
        
}   
