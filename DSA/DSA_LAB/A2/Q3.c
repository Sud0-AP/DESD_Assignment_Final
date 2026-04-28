#include <stdio.h>

int find_factors(int, int);

int main(){
	int num, p;

	printf("Enter the number for which you want the factors for and the index p\n");
	scanf("%d %d",&num, &p);

	
	printf("The %dth factor of %d is %d\n", p, num, find_factors(num, p));

	return 0;
}

// function to find the factors of a number and return the pth factor
int find_factors(int num, int p){
	int temp[num], y=0;
	for(int i = 1; i <= num; i++){
		if(num % i == 0){
			temp[y++] = i;
		}
	}
	if ( (p-1) < (sizeof(temp)/sizeof(int))){
		return temp[p-1];
	}else{
		return 0;
	} 
}
