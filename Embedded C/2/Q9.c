/*Print this pattern:
 *     1
 *    22
 *   333
 *  4444
 * 55555
 * */

#include <stdio.h>

int main()
{
        int row, col, k; //initilizing variables

        for ( row = 0; row <= 5; row++ ) // traversing rows
        {
                for ( col = 0; col <= (5-row); col++ ) // traversing columns
                {
                        printf(" ");
                }
		for (k = 0; k<row; k++) // loop to print the integers 
		{
			printf("%d", row);
		
		}
                printf("\n");
        }
        return 0;
}
