/* Print this pattern:
 
* * * * * * * * * * 
*	        *
*	      *   
*	    *     
*	  *       
*          *     
*	     *   
*	       * 
*                * 
* * * * * * * * * *
  
*/

#include <stdio.h>

int main()
{
        int n = 10; //initilizing variables

        for ( int row = 1; row <= (n/2); row++ ) // traversing rows
        {
                for ( int col = 1; col <= (n-row); col++ ) // traversing columns
                {
			if (row==1 || col == 1){ //if first row or column
				printf("* "); //print star
			}
			else
				printf("  "); //else print blanks
                }
		for (int k = 0; k<row; k++){ // loop to print the stars at an angle
			if(k == 0)
					printf("* ");
				else
					printf("  ");
		
		}
                printf("\n");
        }

	
        for ( int row = n/2; row >= 1; row-- ) // traversing rows
        {
                for ( int col = (n-row)+1; col >= 1; col-- ) // traversing columns
                {
			if(row == 1 || col == n-row+1) // if first row or column
				printf("* "); //print star
			else
				printf("  ");
                }
		for (int k = 0; k<row; k++) // loop to print the stars at an angle 
		{
			if(k == 0)
					printf("* ");
				else
					printf(" ");
		}
                printf("\n");
        }

	
	
        return 0;
}
