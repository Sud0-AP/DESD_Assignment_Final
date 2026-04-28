/* Print this pattern:
 
 *
 * *
 *   *
 *     *
 *       *
 *     *
 *   *
 * *
 *
 
  */

#include <stdio.h>

int main()
{
        int row, col; //initializing variables for row and column

	int n = 5;

//top half of the pattern
        for ( row = 0; row < n; row++ ) //traversing rows
        {
                for ( col = 0; col < n; col++ ) // traversing columns
                {
                        if (row >= col){ // pattern logic 
                               if( (row == col) || (col == 0)) // if row is equal to column or the current column is the first column
					printf("* ");
				else
					printf("  ");
			}
                        else{
                                printf(" "); // blank spaces
			}
                }
                printf("\n");
        }

// bottom half of the pattern

        for ( row = 0; row < n-1; row++ ) //traversing rows
        {
                for ( col = 0; col < n-1; col++ ) // traversing columns
                {
                        if (row <= col){ // pattern logic 
                       		 if( (row == col) || (col == 0) || (col == n-2) ) // if the row si equal to current column or the current column is the first column or the column is the last coulumn
					printf("* ");
				 else 
					printf("  "); 
			}
		}
                printf("\n");
        }	

        return 0;
}  
