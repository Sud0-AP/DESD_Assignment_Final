//Evaluate the given expressions using pointers
//PRN: 260240130005 and 260240130032

#include <stdio.h>

int main(){
	int a[5] = {10,20,30,40,50};
	
	int *p = a;
	int *q = *(&a+1) - 1;

	printf("Current values of p = %d\n", *p);

	*p++;
	printf("Current values of p = %d\n", *p);

	*++p;
	printf("Current values of p = %d\n", *p);
	
	(*p)++;
	printf("Current values of p = %d\n", *p);
	
	++(*p);
	printf("Current values of p = %d\n", *p);
	
	++*p;
	printf("Current values of p = %d\n", *p);

	*(p++);
	printf("Current values of p = %d\n", *p);

	*(++q);
	printf("Current values of q = %d\n", *q);

	*q--;
	printf("Current values of q = %d\n", *q);

	*--q;
	printf("Current values of q = %d\n", *q);

	--(*q);
	printf("Current values of q = %d\n", *q);

	--*q;
	printf("Current values of q = %d\n", *q);

	(*q)--;
	printf("Current values of q = %d\n", *q);

	*(q--);
	printf("Current values of q = %d\n", *q);

	*(--q);
	printf("Current values of q = %d\n", *q);
	
	return 0;
}
