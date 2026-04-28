//To print all the even numbers till N

#include<stdio.h>

int main(){
        int n, i;

	printf("Enter the digits you want the n numbers:");
	scanf("%d", &n); //taking user input

	for(i = 1; i <= n; i++) { // iterating through all numbers from 1 to N
		if( i % 2!= 0){ // if not divisible by 2 then it is odd
			printf("The Odd number are: %d\n", i);
			}		
	}
 
    return 0;
}
