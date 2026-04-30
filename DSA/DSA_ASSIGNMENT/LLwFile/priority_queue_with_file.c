#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	unsigned int priority;
	struct node *next;
};

void insert(struct node **, int, unsigned int);
void insertAfter(struct node *, int, unsigned int);
void insertBefore(struct node **, struct node *, int, unsigned int);

void displayList(struct node *);

int listNodeCount(struct node *);

void delete(struct node **);
void freeAllNode(struct node **, struct node *);
void saveToFile(struct node *, const char *);
void retriveFromFile(struct node **, const char *);

int main(){
	const char *file_path = "./priorityQueue.txt";
	struct node *head;
	head = NULL;
	int choice, data, priority;

	retriveFromFile(&head, file_path);

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
				printf("Enter the element you wish to Insert and it's priority: ");
				scanf("%d %d", &data, &priority);
				insert(&head, data, priority);
				break;
			case 3:
				delete(&head);
				break;
			case 2:
				displayList(head);
				break;
			case 4:
				if(head==NULL)
				printf("Next element to exit the Queue: [%d]|[%u]\n", head->data, head->priority);
				printf("Number of elements in the Queue = %d\n", listNodeCount(head));
				break;
			case 5:
				saveToFile(head, file_path);
				freeAllNode(&head, head);
				exit(1);
				break;
		}
	}
	return 0;

}

//-------------Insert Functions -------------
void insertAfter(struct node *t1, int data, unsigned int priority){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;


	if(t1->next == NULL){
		t1->next = temp;
	}else{
		temp->next = t1->next;
		t1->next = temp;
	}
}

void insertBefore(struct node **head, struct node *t1, int data, unsigned int priority){
	struct node *temp, *t2;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;

	t2 = *head;

	if(t1==*head){
		temp->next = *head;
		*head = temp;
	}else{
		while(t2->next != t1){
			t2 = t2->next;
		}
		temp->next = t1;
		t2->next = temp;
	}
}

void insert(struct node **head, int data, unsigned int priority){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	struct node *t1;
	t1=*head;

	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;

	if(*head == NULL){
		*head = temp;
	}else{
		if(t1->priority < priority){
			insertBefore(head, t1, data, priority);
		}else{
			while(t1->next != NULL){
				t1 = t1->next;
				if(t1->priority < priority){
					insertBefore(head, t1, data, priority);
					return;
				}
			}
			insertAfter(t1, data, priority);
		}
	}
	
}
// ---------- Display functions----------------
void displayList(struct node *head){
	struct node *t1;
	t1 = head;

	while(t1!=NULL){
		printf("[%d]|[%u]|[%04lx] ->", t1->data, t1->priority, (unsigned long)t1->next & 0xFFFF);
		t1=t1->next;
	}
	printf("\n");
}

// ------------Delete function----------------

void delete(struct node **head){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	struct node *t1;
	t1 = *head;

	*head = t1->next;

	free(t1);
}


//-------------- Other functions ------------
int listNodeCount(struct node *head){
	int count = 1;
	struct node *t1;
	t1=head;
	
	if(head == NULL){
		return 0;
	}else{
		while(t1->next!=NULL){
			count++;
			t1=t1->next;
		}
	}
	return count;
}

void freeAllNode(struct node **head, struct node *t1){
	if(t1->next == NULL){
		free(t1);
		return;
	}
	freeAllNode(head, t1->next);
	free(t1);
	if(t1 == *head){
		*head = NULL;
		printf("All nodes freed list is now empty!!\n");
	}

}

void saveToFile(struct node *head, const char *PATH){
	struct node *t1;
	t1 = head;

	if(head == NULL){
		return;
	}

	FILE *fptr = fopen(PATH, "r+");
	if(fptr == NULL){
		perror("fopen:");
		printf("Creating the file!!\n");
		fptr = fopen(PATH, "w");
		
		if(fptr == NULL){
			perror("fopen:");
		}
		
		fclose(fptr);
		fptr = fopen(PATH, "r+");
	}

	while(t1!=NULL){
		fprintf(fptr, "%d %u\n", t1->data, t1->priority);
		t1=t1->next;
	}

}
void retriveFromFile(struct node **head, const char *PATH){	
	FILE *fptr = fopen(PATH, "r+");
	if (fptr == NULL){
		perror("fopen:");
		return;
	}

	int temp1; unsigned int temp2;

	while(fscanf(fptr, "%d %u", &temp1, &temp2) != EOF){
		insert(head, temp1, temp2);
	}


}
