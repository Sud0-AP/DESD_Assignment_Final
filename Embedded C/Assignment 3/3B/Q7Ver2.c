// program to convert decimal to octal and binary
// PRN: 260240130005 and 260240130032
#include <stdio.h>
#include <math.h>

void dec_Octal(int x){

	if (x>0){ //if the last digit is not reached 
		dec_Octal(x/8); //recursive call with dividing by 8 and putting quotient as input
		printf("%d", x%8); // printing the remainder
	}
}

void dec_Binary(int x){
	
	if (x>0) { //if the last digit is not reached
		dec_Binary(x/2); //recursive call with dividing by 2 and putting quotient as input
		printf("%d", x%2); // printing the remainder
	}
}

int main(){
	int num, choice;

	printf("Press (1) for Decimal(B-10) to Binary(B-2) \nPress (2) for Decimal(B-10) to Octal(B-8) \n");
	scanf("%d", &choice); // asking for choice of which to convert

	if(!(choice == 2 || choice == 1)){
		printf("Wrong choice start over!!\n"); //edge case where choice is out of realm of possibility 
		return 0;
	}

	printf("Enter the number you want to convert: "); 
	scanf("%d",&num); //ask user for the number to convert
	

	if(choice == 1){ //function execution based on choice
		printf("Binary conversion of %d is :  ", num);
		dec_Binary(num);
		printf("\n");
	}
	else{
		printf("Octal conversion of %d is :  ", num);
		dec_Octal(num);
		printf("\n");
	}

	return 0;
}
