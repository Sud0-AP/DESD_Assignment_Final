// Print a string in reverse and forward

#include <stdio.h>
#include <string.h>

//--------------Recursive version--------------

void printReverse (char x[],int size){ 
	if (size <= 0){
		return; // stop execution when size variable is less than 0 i.e. first index reached
	}
	printf("%c", x[size-1]);
	printReverse(x,size-1);  // recursive loop with decrement of size variable
}

void printForward (char *x){
	if (*x == '\0') 
		return; //stop execution when the last character is next for printing
        printf("%c", *x);
 	printForward (x+1); //increment the pointer and call the function recursively 
}

int main(){

	int size = 20;
	char input_string[size]; //initializing string

	printf("Enter a string: ");
	fgets(input_string, size, stdin); //taking string as input from user

	printf("Forward: ");
	printForward(input_string);

	printf("\nReverse: ");
	printReverse(input_string,strlen(input_string));
	printf("\n");

	return 0;

}
