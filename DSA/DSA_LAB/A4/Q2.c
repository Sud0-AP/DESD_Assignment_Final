#include <stdio.h>
#include <stdlib.h>

void init_array(int *, int);
void displayStack(int *, int);
void push(int *, int *, int, int);
void pop(int *, int *, int);
void peep(int *, int);
int isStackEmpty(int);
int isStackFull(int, int);

int main(){
	int size, choice, element, top = -1;

	printf("Enter size of stack: ");
	scanf("%d", &size);

	int arr[size];

	init_array(arr, size);

	while(1){
		printf("Enter your choice\n(Enter 1) Push element\n(Enter 2) Pop element\n(Enter 3) Display stack\n(Enter 4) Peep top element\n(Enter 5) Check if stack is empty or full\n(Enter 6) Exit\n");
		scanf("%d", &choice);

		if(choice < 1 || choice > 6){
			printf("Wrong Choice!!\n");
			break;
		}

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
				displayStack(arr, size);
				break;
			case 4:
				peep(arr, top);
				break;
			case 5:
				if(isStackEmpty(top)){
					printf("Stack is Empty!!\n");
				}else if(isStackFull(top, size)){
					printf("Stack is Full!!\n");
				}else{
					printf("Stack is neither Full nor Empty\n");
				}
				break;
			case 6:
				exit(1);
		}
	}

}


void push(int *arr, int *top, int size, int element){
	if(isStackFull(*top, size)){
		printf("Stack is full!!\n");
		return;
	}

	(*top)++;

	arr[*top] = element;
}

void pop(int *arr, int *top, int size){
	if(isStackEmpty(*top)){
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

void displayStack(int *arr, int size){
	for(int i=0 ; i<size ; i++){
		printf("[%d] ", arr[i]);
	}
	printf("\n");
}

int isStackEmpty(int top){
	return (top == -1) ? 1:0;
}

int isStackFull(int top, int size){
	return (top == size-1) ? 1:0;
}

void peep(int *arr, int top){
	printf("Top Element of stack : [%d]\n", arr[top]);
}
