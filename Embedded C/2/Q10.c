/*Printing the pattern:
 *     1
 *    222
 *   33333
 *  4444444
 * 555555555
 * */

#include <stdio.h>

int main()
{
	int row, col, k;
	int n = 5;

	for (row = 1; row <= n; row++)
	{
		for (col = 1; col <= n-row; col++) //printing spaces in front using (Total rows - Current row)
		{
			printf(" ");
		}

		for (k=1; k<=(2*row-1);k++) // printing the digits using (2 * current row -1)
		{
			printf("%d",row);
		}

		printf("\n");
	}
	return 0;
}
