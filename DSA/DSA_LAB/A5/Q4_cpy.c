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
void reverseDisplay(struct node *, struct node *);

int listNodeCount(struct node *);

void deleteFromEnd(struct node **);
void deleteFromBeg(struct node **);
void deleteFromPos(struct node **, int);
void freeAllNode(struct node **, struct node *);


int main(){
	struct node *head;
	head = NULL;
	int choice, data, priority, pos, choice1;

	while(1){
		printf("Enter your choice:\n"
			"(Enter 1) Insert element to Linked List\n"
			"(Enter 2) Display Linked List\n"
			"(Enter 3) Delete from the linked list\n"
			"(Enter 4) Count the number of nodes in the linked list\n"
			"(Enter 5) Exit\n");

		scanf("%d", &choice);

		if(choice < 1 || choice > 5){
			return 0;
		}

		switch(choice){
			case 1:
				printf("Enter the Value which you wish to Insert and it's priority: ");
				scanf("%d %d", &data, &priority);
				insert(&head, data, priority);
				break;
			case 3:
				printf("What do you wish to do? \n");
				printf("(Enter 1) Delete from the end\n"
					"(Enter 2) Delete from the Begining\n"
					"(Enter 3) delete from position\n"
					"(Enter 4) Delete the whole linked list\n"
					"(Enter 5) Go back\n");

				scanf("%d", &choice1);
				if(choice1<1 || choice1>4){
					printf("Invalid choice!!\n");
					break;
				}else {
				switch(choice1){ 
					case 1:
						deleteFromEnd(&head);
						break;
					case 2:
						deleteFromBeg(&head);
						break;
					case 3:
						printf("Enter the position which you wish to delete: ");
						scanf("%d", &pos);
						deleteFromPos(&head, pos);
						break;
					case 4:
						freeAllNode(&head, head);
						break;
					case 5:
						break;
					}
					break;
				}
			case 2:
				printf("What do you wish to perform:\n"
					"(Enter 1) Display the Linked list\n"
					"(Enter 2) Display the Linked list in reverse\n"
					"(Enter 3) Go Back\n");
				scanf("%d", &choice1);
				if(choice1<1 || choice1>3){
					printf("Invalid choice!!\n");
					break;
				}
				switch(choice1){
					case 1:	
						displayList(head);
						break;
					case 2:
						reverseDisplay(head, head);
						break;
					case 3:
						break;
				}

				break;
			case 4:
				printf("Number of nodes in the Linked list = %d\n", listNodeCount(head));
				break;
			case 5:
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

void reverseDisplay(struct node *head, struct node *t1){
	if(t1->next == NULL){
		printf("<--[%d]|[%u]|[%04lx]", t1->data, t1->priority, (unsigned long)t1->next & 0xFFFF);
		return;
	}
	reverseDisplay(head, t1->next);
	printf("<--[%d]|[%u]|[%04lx]", t1->data, t1->priority, (unsigned long)t1->next & 0xFFFF);
	if(t1 == head){
		printf("\n");
	}
}

// ------------Delete functions----------------

void deleteFromEnd(struct node **head){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	struct node *t1;
	t1 = *head;

	while(t1->next->next!=NULL){
		t1=t1->next;
	}
	free(t1->next);
	t1->next = NULL;
}


void deleteFromBeg(struct node **head){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	struct node *t1;
	t1 = *head;

	*head = t1->next;

	free(t1);
}

void deleteFromPos(struct node **head, int pos){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	int num_nodes = listNodeCount(*head);
	int count = 0;

	if(pos > num_nodes){
		printf("Invalid position choose from 1 to %d position!!\n", num_nodes);
		return;
	}

	struct node *t1;
	t1 = *head;

	if(pos == 1){
		*head = t1->next;
		free(t1);
	}else if(pos == num_nodes){
		while(t1->next->next!=NULL){
			t1=t1->next;
		}
		free(t1->next);
		t1->next = NULL;
	}else{
		while(count != pos-2){
			count++;
			t1=t1->next;
		}
		struct node *t2;
		t2 = t1->next;
		t1->next = t1->next->next;
		free(t2);
	}

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

