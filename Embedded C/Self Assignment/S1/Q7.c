//To check if the given number is palindrome or not  

#include <stdio.h>

int reverseNum(int num, int rev){
	if (num == 0){ //base case where we have iterated through all the digits of the given number
		return rev; //return the reveresed number
	}

	int rem = num % 10; // seperating the last digit of the number by taking the reminder after dividing by 10 and storing it in a variable
	
	rev = (rev * 10) + rem; // building the number in revese one digit at a time 
	
	reverseNum(num/10 , rev); // recursion call with one reduced digit from the original number
}


int main(){
    int num,rev;

    printf("Enter a Number: \n");
    scanf("%d", &num); //taking user input

    rev = reverseNum(num,0); // reversing the number using the function from before

    if (num == rev){ // if the reverse of the number is equal to the number itself then it is indeed a palindrome number 
	    printf("The number %d is a palindrome !!\n", num);
    }else{ // otherwise the number is not a palindrome number
	    printf("The number %d is not a palindrome !!\n",num);
    }

    return 0;
}
