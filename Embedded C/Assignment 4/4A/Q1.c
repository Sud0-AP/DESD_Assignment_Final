// To calulate and print pascal's triangle
// PRN: 260240130005 and 260240130032


#include <stdio.h>

int main()
{
	int rows, a, b, n, j=1;
	
	printf("Enter the number of rows : "); // Enter the number of rows
	scanf("%d", &rows);

	for (a=0; a< rows; a++){ 

		for (n = 1; n <= rows - a; n++){
				printf("   "); // Spaces for horizontal spacing
			}

			for (b = 0; b <= a; b++){
				if (b == 0 || a == 0) {
					j = 1; // First and last element of each row is always 1
				} else {
					j = j*(a-b+1)/b; // Calculating the next number by using the previous one
				}

				printf("%6d", j); // Print the number with the width of 6 alignment
			}
			printf("\n");
	}

	return 0;
}






