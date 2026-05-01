//PRN: 260240130005 260240130032
//priority queue using array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct element{
	int data;
	unsigned int priority;
};

int count_elements;
struct element arr[MAX_SIZE];

void insert(int, unsigned int);
void delete(void);
void displayList(void);
int listNodeCount(void);
void peepElement(void);

int main(){
	count_elements = 0;
	int choice, data, priority;

	while(1){
		printf("Enter your choice:\n"
			"(Enter 1) Insert element to the queue\n"
			"(Enter 2) Display the queue\n"
			"(Enter 3) Delete item from the queue\n"
			"(Enter 4) Peep top element and count number of elements\n"
			"(Enter 5) Exit\n");

		scanf("%d", &choice);

		if(choice < 1 || choice > 5){
			return 0;
		}

		switch(choice){
			case 1:
				if(count_elements >= MAX_SIZE){
					printf("Queue is full!!\n");
				}else{
					printf("Enter the element you wish to Insert and it's priority: ");
					scanf("%d %d", &data, &priority);
					insert(data, priority);
				}
				break;
			case 3:
				delete();
				break;
			case 2:
				displayList();
				break;
			case 4:
				peepElement();
				printf("Number of elements in the Queue = %d\n", listNodeCount());
				break;
			case 5:
				exit(1);
				break;
		}
	}
	return 0;

}

//-------------Insert Functions -------------
void insert(int data, unsigned int priority){
	if(count_elements == 0){
		arr[0].data = data;
		arr[0].priority = priority;
		count_elements++;
	}else{
		int pos = count_elements - 1;
		
		while(pos >= 0 && arr[pos].priority < priority){
			arr[pos + 1] = arr[pos];
			pos--;
		}
		
		arr[pos + 1].data = data;
		arr[pos + 1].priority = priority;
		count_elements++;
	}
}

// ---------- Display functions----------------
void displayList(void){
	if(count_elements == 0){
		printf("List is Empty!!\n");
		return;
	}

	for(int i = 0; i < count_elements; i++){
		printf("[%d]|[%u]|[%04x] ->", arr[i].data, arr[i].priority, i);
	}
	printf("\n");
}

// ------------Delete function----------------

void delete(void){
	if(count_elements == 0){
		printf("List is Empty!!\n");
		return;
	}

	for(int i = 0; i < count_elements - 1; i++){
		arr[i] = arr[i + 1];
	}
	count_elements--;
}


//-------------- Other functions ------------
int listNodeCount(void){
	return count_elements;
}

void peepElement(void){
	if(count_elements == 0){
		printf("List is Empty!!\n");
	}else{
		printf("Next element to exit the Queue: [%d]|[%u]\n", arr[0].data, arr[0].priority);
	}
}
