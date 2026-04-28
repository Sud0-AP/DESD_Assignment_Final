// print the given senarios to diffrentiate between post and pre decrement/increment operators
// PRN: 260240130005 and 260240130032

#include <stdio.h>

int main()
{
	int a, b, temp;
	
	printf("Enter a number :");
	scanf("%d", &a);
	
	temp = a; // storing the orginal value to reset for each example

	printf("Post increment 'i++' on %d = %d \n",temp,a++); //when we use post increment operator then the number is printed first then incremented so the value will be the same for this print statement but the next time we use the variable a then the value will be incremented by one 
	printf("Pre increment '++i' on %d = %d \n", temp, ++a); //in the pre increment operator the variable is incremented first and then the updated value is printed in this case it will appear to be incremented twice since the variable was already incremented once before this but not printed as a post increment operator was used

	a=temp; // resetting the value for next case

	printf("Post increment 'i++*10' on %d = %d \n",temp,a++*10); //here we will multiply 10 with the orignal value only since the value of the variable is not updated till the end of the execution of this line
	printf("Pre increment '++i*10' on %d = %d \n", temp, ++a*10); //here we will multiply the variable with incremented value as we used a pre increment operator

	a=temp; //resetting the value for next case

	printf("Post decrement 'i--/3' on %d = %0.2f \n",temp,(float)(a--/3)); //here the orignal variable value will be divided by 3 then afterwards it would be decremented
	printf("Pre decrement '--i/3' on %d = %0.2f \n", temp, (float)(--a/3)); //here the value will be decremented first then the decremented value will be divided
	return 0;
}




		
