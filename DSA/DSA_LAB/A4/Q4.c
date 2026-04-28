#include <stdio.h>
#include <stdlib.h>

void init_array(int *, int);
void displayQueue(int *, int);
void add(int *, int *, int *, int, int);
void delete(int *, int *, int *, int);
void peep(int *, int, int);

int isQueueEmpty(int);
int isQueueFull(int, int, int);

int main(){
	int size, choice, element, start = -1, end = -1;

	printf("Enter size of queue: ");
	scanf("%d", &size);

	int arr[size];

	init_array(arr, size);

	while(1){
		printf("Enter your choice\n(Enter 1) Add element\n(Enter 2) Delete element\n(Enter 3) Display Queue\n(Enter 4) Peep the start and end elements\n(Enter 5) Check if Queue is empty or full\n(Enter 6) Exit\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the element you want to enqueue: ");
				scanf("%d", &element);
				add(arr, &start, &end, size, element);
				break;
			case 2:
				delete(arr, &start, &end, size);
				break;
			case 3:
				printf("Start-> [%d] End-> [%d]\n", start, end);
				displayQueue(arr, size);
				break;
			case 4:
				peep(arr, start, end);
				break;
			case 5:
				if(isQueueEmpty(start)){
					printf("Queue is Empty!!\n");
				}else if(isQueueFull(start, end, size)){
					printf("Queue is Full!!\n");
				}else{
					printf("Queue is neither Full nor Empty\n");
				}
				break;
			case 6:
				exit(1);
		}
	}

}


void add(int *arr, int *start, int *end, int size, int element){
	if(isQueueFull(*start, *end, size)){
		printf("Queue is full!!\n");
		return;
	}

	if(*end == size-1){
		*end = 0;
	}else{
		(*end)++;
	}
	arr[*end] = element;

	if(*start == -1){
		*start = 0;
	}
}

void delete(int *arr, int *start, int *end, int size){
	if(isQueueEmpty(*start)){
		printf("Queue is empty!!\n");
		return;
	}

	printf("Dequeued element : %d\n", arr[*start]);
	arr[*start] = -99;
	if (*start == *end){
		*start = -1;
		*end = -1;
	}else if(*start == size-1){
		*start = 0;
	}else{
		(*start)++;
	}
}

void init_array(int *arr, int size){
	for(int i=0 ; i<size ; i++){
		arr[i] = -99;
	}
}

void displayQueue(int *arr, int size){
	for(int i=0 ; i<size ; i++){
		printf("[%d] ", arr[i]);
	}
	printf("\n");
}


int isQueueEmpty(int start){
	return (start == -1) ? 1:0;
}

int isQueueFull(int start, int end, int size){
	return (((end == size-1) && (start == 0)) || (end+1 == start) ) ? 1:0;
}

void peep(int *arr, int start, int end){
	printf("Element at the start of queue : [%d]\n", arr[start]);
	printf("Element at the end of queue : [%d]\n", arr[end]);
}
