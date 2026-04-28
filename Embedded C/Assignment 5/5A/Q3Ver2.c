//Perform polynomial evaluation where coefficients are stored in an array (using Math.h)
// PRN: 260240130005 and 260240130032

#include <stdio.h>
#include <math.h>

int main(){
        int n, x, result;

        printf("Enter the number of terms in equation: ");
        scanf("%d", &n);

        int a[n];

        printf("Enter value of x : ");
        scanf("%d", &x);
	
        for(int i=0; i<n; i++){
                printf("Enter coffecient for term number %d : ", i+1);
                scanf("%d", &a[i]);
        }

        for(int i = n-1; i>=0 ; i--){
                result += a[i]*pow(x,i);
        }
        
        printf("Result after polynomial evaluation = %d\n",result);

        return 0;

}
 
