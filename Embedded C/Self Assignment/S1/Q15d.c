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
        int n = 5; //initilizing variables

        for ( int row = 0; row <= n-1; row++ ) // traversing rows
        {
                for ( int col = 0; col <= (n-row); col++ ) // traversing columns
                {
                        printf("  ");
                }
		for (int k = 0; k<row; k++) // loop to print the integers 
		{
			if((k == 0)||(k == row-1)) // if the cursor is at the first location or at the end
					printf("* ");
				else
					printf("  ");
		
		}
                printf("\n");
        }

	
        for ( int row = n; row >= 0; row-- ) // traversing rows
        {
                for ( int col = ((n)-row); col >= 0; col-- ) // traversing columns
                {
                        printf("  ");
                }
		for (int k = 0; k<row; k++) // loop to print the integers 
		{
			if((k == 0)||(k==row-1)) // if the cursor is at the first location or at the end
					printf("* ");
				else
					printf("  ");
		
		}
                printf("\n");
        }

	
	
        return 0;
}
