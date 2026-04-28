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

                for ( col = 0; col < 5; col++ ) // traversing columns
                {
                        if (row >= col) // pattern logic 
                                printf("%d", row+1);
                        else
                                printf(" "); // blank spaces
                }
                printf("\n");
        }
        return 0;
}  
