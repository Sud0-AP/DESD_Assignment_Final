//Calculating the power of n 
// PRN: 260240130005 and 260240130032
#include <stdio.h>
#include <math.h>

void power_n(int x, int y){
	static float n = 0.0;
	if (pow(x,n) >= y){ // checking if target power reached
		printf("%d is %0.1f power of %d\n", y,n,x); //printing the result
		return;
	}
	n += 0.01; //incrementing by 0.01 to cover each senario up until the desired power is found
	power_n(x,y); //recursive call
		
}

int main(){
	int num1, num2;

	printf("Enter the numbers you want to find the power of n: ");
	scanf("%d %d", &num1, &num2); //taking two inputs

	//calling functions based on bigger and smaller number
	if(num1>num2)
		power_n(num2,num1);
	else
		power_n(num1,num2);
	return 0;
}


