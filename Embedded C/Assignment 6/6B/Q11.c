//Program an expression to print the last element of an array irrespective of the lenght using pointers
//PRN: 260240130005 and 260240130032

#include <stdio.h>

void inputArray(int num, int arr[num]){
	for(int i=0 ; i<num ; i++){
		printf("Enter element at index [%d]", i);
		scanf(" %d", &arr[i]);
	}

}

int main(){
	int size;
	printf("Enter size of array: ");
	scanf("%d", &size);

	int arr[size];

	inputArray(size, arr);

	int *ptr = arr; 

	int last = *(ptr + (sizeof(arr)/sizeof(int)) -1);
	printf("Last element of the given array = %d\n", last);

	return 0;
}
