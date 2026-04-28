/* Print this pattern:
 1
 22
 333
 4444
 55555
  */

#include <stdio.h>

int main()
{
        int row, col; //initializing variables for row and column

        for ( row = 0; row < 5; row++ ) //traversing rows
        {
		int num = 1; // setup a counter variable
                for ( col = 0; col < 5; col++ ) // traversing columns
                {
                        if (row <= col){ // pattern logic: current row is less than or equal to current column
                                printf("%d", num); // then print the num variable
				 num++; // increment the counter variable
			}
		}
                printf("\n");
        }
        return 0;
}  
