//To reverse a given number 

int reverseNum(int num, int rev){
	if (num == 0){ //base case where we have iterated through all the digits of the given number
		return rev; //return the reveresed number
	}

	int rem = num % 10; // seperating the last digit of the number by taking the reminder after dividing by 10 and storing it in a variable
	
	rev = (rev * 10) + rem; // building the number in revese one digit at a time 
	
	reverseNum(num/10 , rev); // recursion call with one reduced digit from the original number
}

#include<stdio.h>

int main(){
    int num,rev;

    printf("Enter a Number: \n");
    scanf("%d", &num); // tkaing user input
    
    rev = reverseNum(num,0); //function call

    printf("Reversed number: %d\n", rev); //printing the number 

    return 0;
}
