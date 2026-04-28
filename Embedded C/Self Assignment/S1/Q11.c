//To print all the even numbers till N  

#include<stdio.h>

int main(){
        int n, i;

    	printf("Enter the number till which you want to print the even numbers:");
    	scanf("%d", &n); //taking user input

	for(i = 1; i <= n; i++) { // iterating from 1 to N
		if( i % 2 == 0){ //if the number is divisible by 2 then print it
			printf("The Even number are: %d\n", i);
		}
	}
	
	return 0;
}
