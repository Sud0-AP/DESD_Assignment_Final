// To create your function to concatenate and compare two strings
// PRN: 260240130005 260240130032

#include <stdio.h>

char* concat(char *x, char *y){
	int total_size = (sizeof(*x)/sizeof(char)) + (sizeof(*y)/sizeof(char));
	char* result[total_size-1];
	for (int i=0; i<total_size; i++){
		if (i<(sizeof(*x)/sizeof(char))){
			result[i] = *x[i];
		}
		result[i] = *y[i];
	}	

	return result;
}

int main(){


