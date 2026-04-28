#include <stdio.h>
#include <stdlib.h>

void init_array(int *, int);
void display(int *, int);
void enqueue(int *, int *, int *, int, int);
void dequeue(int *, int *, int *, int);

int main(){
	int size, choice, element, start = -1, end = -1;

	printf("Enter size of queue: ");
	scanf("%d", &size);

	int arr[size];

	init_array(arr, size);

	while(1){
		printf("Enter your choice\n(Enter 1) enqueue element\n(Enter 2) dequeue element\n(Enter 3) Display queue\n(Enter 4) Exit\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the element you want to enqueue: ");
				scanf("%d", &element);
				enqueue(arr, &start, &end, size, element);
				break;
			case 2:
				dequeue(arr, &start, &end, size);
				break;
			case 3:
				printf("Start-> [%d] End-> [%d]\n", start, end);
				display(arr, size);
				break;
			case 4:
				exit(1);
		}
	}

}


void enqueue(int *arr, int *start, int *end, int size, int element){
	if(*end == size-1){
		printf("Queue is full!!\n");
		return;
	}

	(*end)++;

	arr[*end] = element;

	if(*start == -1){
		*start = 0;
	}
}

void dequeue(int *arr, int *start, int *end, int size){
	if(*start == -1){
		printf("Queue is empty!!\n");
		return;
	}

	printf("Dequeued element : %d\n", arr[*start]);
	arr[*start] = -99;
	if (*start == *end){
		*start = -1;
		*end = -1;
	}else{
		(*start)++;
	}
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
