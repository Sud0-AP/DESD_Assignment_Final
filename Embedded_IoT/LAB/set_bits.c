#include <stdio.h>

int main(){

	unsigned int x = 0x10;

	//unsigned int y = (1U << 20 ) - 1;

	int count = 0;
	while (x>0){
		count += (x & 1);
		x >>= x;
	}

	printf("%d\n", count);

	return 0;
}
