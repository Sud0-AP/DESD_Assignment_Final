//To Print number from 1 to N and N is accuired by user input 

#include<stdio.h>

int main(){
    int n, i;

    printf("Enter the number till you want to print 1 -> N: ");
    scanf("%d", &n); //taking user input

    for(i = 1; i <= n; i++) {
        printf("%d\n", i); // print the number
    }
    
    return 0;
}
