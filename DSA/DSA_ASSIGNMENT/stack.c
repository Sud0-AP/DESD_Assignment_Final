#include <stdio.h>
#include <stdlib.h>

void init_array(int *, int);
void display(int *, int);
void push(int *, int *, int, int);
void pop(int *, int *, int);

int main(){
	int size, choice, element, top = -1;

	printf("Enter size of stack: ");
	scanf("%d", &size);

	int arr[size];

	init_array(arr, size);

	while(1){
		printf("Enter your choice\n(Enter 1) Push element\n(Enter 2) Pop element\n(Enter 3) Display stack\n(Enter 4) Exit\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the element you want to push: ");
				scanf("%d", &element);
				push(arr, &top, size, element);
				break;
			case 2:
				pop(arr, &top, size);
				break;
			case 3:
				printf("Top-> [%d]\n", top);
				display(arr, size);
				break;
			case 4:
				exit(1);
		}
	}

}


void push(int *arr, int *top, int size, int element){
	if(*top == size-1){
		printf("Stack is full!!\n");
		return;
	}

	(*top)++;

	arr[*top] = element;
}

void pop(int *arr, int *top, int size){
	if(*top == -1){
		printf("Stack is empty!!\n");
		return;
	}

	printf("Popped element : %d\n", arr[*top]);
	arr[*top] = -99;
	(*top)--;

}

void init_array(int *arr, int size){
	for(int i=0 ; i<size ; i++){
		arr[i] = -99;
	}
}

void display(int *arr, int size){
	for(int i=0 ; i<size ; i++){
		printf("[%d] ", arr[i]);
	}
	printf("\n");
}
