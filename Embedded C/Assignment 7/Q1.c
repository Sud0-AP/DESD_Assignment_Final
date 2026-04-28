#include <stdio.h>

void function_count_call(void){

	static int count_call = 0;

	count_call ++;


	printf("This function has been callled %d times\n", count_call);

	}

int main(){

	printf("Starting the Program.. \n\n");

	function_count_call();
	function_count_call();
	function_count_call();
	function_count_call();

	printf("\n");

	return 0;
}
