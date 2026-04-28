// program to convert decimal to octal and binary
// PRN: 260240130005 and 260240130032
#include <stdio.h>
#include <math.h>

void dec_Octal(int x){
	printf("\nOctal conversion of %d is: ",x);
	
	int lenght = (log(x)/log(8.0)) + 1 ; // calculating the lenght of the output
	int result[lenght]; // setting up an array using the previourly determined lenght of output
	for (int i =0 ; x!=0 ; i++){
		result[(lenght-1)-i] = x%8;  // storing the reminder after dividing by 8
		x/=8; // dividing the number itself by 8 and reducing the number 
	}	

	for (int j =0 ; j<lenght ; j++)
		printf("%d", result[j]); // printing the result in reverse as the result was computed in reverse
	
	printf("\n");
}

void dec_Binary(int x){
	printf("\nBinary conversion of %d is: ",x);
	
	int lenght = log2(x) + 1 ; // calculating the lenght of the output
	int result[lenght];  // setting up an array using the previourly determined lenght of output

	for (int i =0 ; x!=0 ; i++){
		result[(lenght-1)-i] = x%2; // storing the reminder after dividing by 2
		x/=2; // dividing the number itself by 2 and reducing the number 
	}

	for (int j =0 ; j<lenght ; j++)
		printf("%d", result[j]);  // printing the result in reverse as the result was computed in reverse


	printf("\n");
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
		dec_Binary(num);
	}
	else{
		dec_Octal(num);
	}

	return 0;
}
