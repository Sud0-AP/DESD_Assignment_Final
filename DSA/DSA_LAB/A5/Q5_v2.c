//dequeue or doubly ended queue using array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct deque {
	int arr[MAX_SIZE];
	int front;
	int rear;
	int size;
};

void initDeque(struct deque *);
void enqueueAtFront(struct deque *, int);
void enqueueAtRear(struct deque *, int);
int dequeueFromFront(struct deque *);
int dequeueFromRear(struct deque *);
void displayDeque(struct deque *);
int isEmpty(struct deque *);
int isFull(struct deque *);

int main(){
	struct deque dq;
	int choice, data;
	
	initDeque(&dq);

	while(1){
		printf("\nEnter your choice:\n");
		printf("(Enter 1) Enqueue at Front\n");
		printf("(Enter 2) Enqueue at Rear\n");
		printf("(Enter 3) Dequeue from Front\n");
		printf("(Enter 4) Dequeue from Rear\n");
		printf("(Enter 5) Display Deque\n");
		printf("(Enter 6) Exit\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the element to enqueue at front:\n");
				scanf("%d", &data);
				enqueueAtFront(&dq, data);
				break;
			case 2:
				printf("Enter the element to enqueue at rear:\n");
				scanf("%d", &data);
				enqueueAtRear(&dq, data);
				break;
			case 3:
				data = dequeueFromFront(&dq);
				if(data != -1){
					printf("Dequeued from front: %d\n", data);
				}
				break;
			case 4:
				data = dequeueFromRear(&dq);
				if(data != -1){
					printf("Dequeued from rear: %d\n", data);
				}
				break;
			case 5:
				printf("Current state of deque:\n");
				displayDeque(&dq);
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("Invalid choice!\n");
				break;
		}
	}

	return 0;
}

void initDeque(struct deque *dq){
	dq->front = -1;
	dq->rear = -1;
	dq->size = 0;
}

int isEmpty(struct deque *dq){
	return (dq->size == 0);
}

int isFull(struct deque *dq){
	return (dq->size == MAX_SIZE);
}

void enqueueAtFront(struct deque *dq, int data){
	int i;

	if(isFull(dq)){
		printf("Deque is full!\n");
		return;
	}

	if(isEmpty(dq)){
		dq->front = 0;
		dq->rear = 0;
		dq->arr[0] = data;
		dq->size++;
		return;
	}

	for(i = dq->size; i > 0; i--){
		dq->arr[i] = dq->arr[i-1];
	}

	dq->arr[0] = data;
	dq->rear++;
	dq->size++;
}

void enqueueAtRear(struct deque *dq, int data){
	if(isFull(dq)){
		printf("Deque is full!\n");
		return;
	}

	if(isEmpty(dq)){
		dq->front = 0;
		dq->rear = 0;
		dq->arr[0] = data;
		dq->size++;
		return;
	}

	dq->rear++;
	dq->arr[dq->rear] = data;
	dq->size++;
}

int dequeueFromFront(struct deque *dq){
	int i, data;

	if(isEmpty(dq)){
		printf("Deque is empty!\n");
		return -1;
	}

	data = dq->arr[dq->front];
	
	for(i = 0; i < dq->rear; i++){
		dq->arr[i] = dq->arr[i+1];
	}

	dq->rear--;
	dq->size--;

	if(isEmpty(dq)){
		dq->front = -1;
		dq->rear = -1;
	}

	return data;
}

int dequeueFromRear(struct deque *dq){
	int data;

	if(isEmpty(dq)){
		printf("Deque is empty!\n");
		return -1;
	}

	data = dq->arr[dq->rear];
	dq->rear--;
	dq->size--;

	if(isEmpty(dq)){
		dq->front = -1;
		dq->rear = -1;
	}

	return data;
}

void displayDeque(struct deque *dq){
	int i;

	if(isEmpty(dq)){
		printf("Deque is empty!\n");
		return;
	}

	printf("Deque elements (Front -> Rear): ");
	for(i = dq->front; i <= dq->rear; i++){
		printf("%d ", dq->arr[i]);
	}
	printf("\n");
}