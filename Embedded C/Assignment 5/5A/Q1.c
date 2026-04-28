// C program to reverse an array in memory
// PRN: 260240130005 and 260240130032

#include <stdio.h>

void reverseArray (int x[], int size){ // iterating through the array using two index pointers one from the start one from the end
        int first = 0;
	int last = size-1;
	int temp;

        while (first<last){ // while the two pointers have not crossed each other keep replacing last with first and vice versa
		temp = x[first];
		x[first] = x[last];
		x[last] = temp;

		last--;
		first++;
	}
	
}

int main(){
// taking user input
	int size;
	printf("Enter the size of array: ");
	scanf("%d",&size);

	int arr[size];

	for(int i = 0; i<size ; i++){
		printf("Enter element at index %d: ", i);
		scanf("%d",&arr[i]);
	}
//function call
	reverseArray(arr,size);
//printing the resultant array
	printf("Reveresed Array :\n");
	for(int i = 0; i<size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;

}
