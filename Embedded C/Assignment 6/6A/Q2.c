// To convert short integer from little endian to big endian (network order) and vice versa
// PRN: 260240130005 and 260240130032

#include <stdio.h>

void short_swap_BELE(unsigned short int x){
	unsigned char *ptr = (char *)&x;
	unsigned char temp;

	printf("Before converting: %x\n",x);

	temp = *ptr;
	*ptr = *(ptr+1);
	*(ptr+1) = temp;

	printf("After converting: %x\n", x);
}


int main(){
	short int num = 0x1231;
	short_swap_BELE(num); //function call
	return 0;
}
