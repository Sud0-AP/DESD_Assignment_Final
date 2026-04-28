//To convert an integer from little endian to big endian and vice versa
//PRN: 260240130005 and 260240130032

#include <stdio.h>

void int_swap_BELE(unsigned int x){
	unsigned char *start = (char *)&x;
	unsigned char *end = start + 3;
	unsigned char temp;

	printf("Before converting: %x\n",x);

	while(start<end){
		temp = *start;
		*start = *end;
		*end = temp;
		end--;
		start++;	
	}

	printf("After converting: %x\n", x);
}


int main(){
	int num = 0x12313415;
	int_swap_BELE(num);//function call
	return 0;
}
