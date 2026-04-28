// Try some nested function calls
// PRN: 260240130005 and 260240130032

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int subtract(int x, int y){
	return x-y;
}

int main(){
	int num1 = 10, num2 = 20;
	
	int result = sqrt(pow(abs(subtract(num1, num2)),2));

	printf("Result after calculations = %d\n", result);

	return 0;
}

