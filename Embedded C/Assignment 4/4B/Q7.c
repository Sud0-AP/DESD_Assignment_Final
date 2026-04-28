// To print the given statements and see the difference of same statement with and without paraenthesis  
// PRN: 260240130005 and 260240130032
#include <stdio.h>

int main ()
{
	int a = 10, b = 20, c = 30, d;

	d = ++a, ++b, ++c, a+5; 
	
	/* In C this statement will be equivalent to :
		(d = ++a) , ++b, ++c, a+5 ;
		and the value of the other three will not be saved as the precedence of the = operator is higher than , comma so only = one will be executed 
	*/

	printf("The value of d after ++a, ++b, ++c, a+5 is %d\n", d);
        
	d = 0;

	d = (++a,++b,++c,a+5);
	
	/* In C this statement will be equivalent to :
		d = a+5;
		and the value of the other three will be executed but not be saved as the comma operator is evaluated from left to right so in the end only the last one will be saved in variable d 
	*/
		
	printf("The value of d after (++a, ++b, ++c, a+5) is %d\n", d);
        
	return 0;
}
	


