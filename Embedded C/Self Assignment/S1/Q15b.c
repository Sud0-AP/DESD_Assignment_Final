/* Print this pattern:
 1
 2 2
 3   3
 4     4
 5 5 5 5 5
  */

#include <stdio.h>

int main()
{
        int row, col; //initializing variables for row and column

	int n = 5;

        for ( row = 0; row < n; row++ ) //traversing rows
        {
                for ( col = 0; col < n; col++ ) // traversing columns
                {
                        if (row >= col){ // pattern logic: current row is greater than or equal to current column
                                if(((row == col) || (col == 0)) || (row == n-1)) // if the current row is equal to current column or the row is at the last row or the current column is the first column
					printf("%d ", row+1); // then print the row number
				else
					printf("  "); // else put a blank space
			}
                        else{
                                printf(" "); // blank spaces
			}
                }
                printf("\n");
        }
        return 0;
}  
