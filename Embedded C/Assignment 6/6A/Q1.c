//to check if the current system is little endian or big endian
//PRN: 260240130005 and 260240130032

#include <stdio.h>

int main(){

	unsigned int i = 1; //Declaring an integer
	char *c = (char*)&i; //Storing the address of integer i in a character pointer

	if (*c == 1){ // if the value stored at the pointer c is 1 then the system is little endian as it is storing elements starting from LSB
		printf("The System is Little Endian\n");

	}else{ //else it is a big endian system
		printf("The System is Big Endian\n");

	}

	return 0;
	
}
