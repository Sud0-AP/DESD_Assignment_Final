// Print array in forward and reverse

#include <stdio.h>

//--------------Recursive version--------------

void printForward_R (int *x, int size){ //using pointer to point to the array i.e. the first element of array
	if (size <= 0){ // end case where we have reached the ned of array
		return;
	}

	printf("%d\n", *x); //printing the element pointed by the pointer

	printForward_R(x+1,size-1); // incrementing the pointer i.e. incrementing the address to the elements in the array; and reducing the size variable to keep track of the lenght
}

void printReverse_R (int x[], int size){
	if ((size-1) >= 0){ // checking if the we are in bound of the array
		printf("%d\n", x[size-1]); // printing the last element based on size variable
		printReverse_R(x, size-1); // decreasing size veriable with every iteration
	}
}

//--------------Main function------------------

int main(){

        int size;
        printf("Enter the size of array: ");
        scanf("%d",&size); //taking input of the size of the array

        int arr[size]; // initializing the array

        for(int i = 0; i<size ; i++){
                printf("Enter element at index %d: ", i);
                scanf("%d",&arr[i]); //taking input of elements
        }

	//calling the functions

	printf("Forward: \n");
        printForward_R(arr,size);

	printf("Reverse: \n");
        printReverse_R(arr,size);

        return 0;

}

