// Print a string in reverse and forward

#include <stdio.h>
#include <string.h>

//--------------Iterative version--------------

void printReverse (char x[]){
       	printf("Reverse:");
	for (int j = strlen(x); j>=0 ; j--){
		printf("%c", x[j]);
	}
	printf("\n");
}

void printForward (char x[]){
        printf("Forward:\n");
        printf("%s", x);
}

int main(){

	int size = 20;
	char input_string[size];

	printf("Enter a string: ");
	fgets(input_string, size, stdin);

	printForward(input_string);
	printReverse(input_string);

	return 0;

}
