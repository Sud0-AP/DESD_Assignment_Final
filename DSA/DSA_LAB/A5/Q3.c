//PRN: 260240130005 260240130032
// doubly cicular linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

void insertAtEnd(struct node **, int);
void insertAtBeg(struct node **, int);
void insertAtPos(struct node **, int, int);

void displayList(struct node *);
int listNodeCount(struct node *);

void deleteFromEnd(struct node **);
void deleteFromBeg(struct node **);
void deleteFromPos(struct node **, int);


int main(){
	struct node *head;
	head = NULL;
	int choice, data, pos;
	
	while(1){
		printf("Enter your choice:\n"
			"(Enter 1) Insert element at end\n"
			"(Enter 2) Insert element at begining\n"
			"(Enter 3) Insert element at position\n"
			"(Enter 4) Delete element at end\n"
			"(Enter 5) Delete element at start\n"
			"(Enter 6) Delete element at position\n"
			"(Enter 7) Display Linked List\n"
			"(Enter 8) Exit\n");

		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the element you wish to insert:\n");
				scanf("%d", &data);
				insertAtEnd(&head, data);
				break;
			case 2:	
				printf("Enter the element you wish to insert:\n");
				scanf("%d", &data);
				insertAtBeg(&head, data);
				break;
			case 3:
				printf("Enter the element you wish to insert and position:\n");
				scanf("%d %d", &data, &pos);
				insertAtPos(&head, data, pos);
				break;

			case 4:	printf("Deleting the last element....\n");
				deleteFromEnd(&head);
				break;
			case 5:
				printf("Deleting the first element....\n");
				deleteFromBeg(&head);
				break;
			case 6:
				printf("Enter the position which you wish to delete \n");
				scanf("%d", &pos);
				deleteFromPos(&head, pos);
				break;
			case 7:
				printf("Current state of the linked list\n");
				displayList(head);
				break;
			case 8: 
				exit(1);
				break;		
		}
	}

}
//-------------Insert Functions -------------
void insertAtEnd(struct node **head, int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	
	if(temp == NULL){
		printf("Memory allocation failed !!\n");
		return;
	}

	struct node *t1;
	t1=*head;

	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;

	if(*head == NULL){
		*head = temp;
		temp->prev = temp;
		temp->next = *head;
		return;
	}

	while(t1->next != *head){
		t1=t1->next;
	}

	temp->prev = t1;
	t1->next = temp;
	temp->next = *head;
	(*head)->prev = temp;
}

void insertAtBeg(struct node **head, int data){
	struct node *temp, *t1;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("Memory allocation failed !!\n");
		return;
	}
	t1=*head;

	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;

	if(*head == NULL){
		*head = temp;
		temp->next = temp;
		temp->prev = temp;
		return;
	}

	if( (*head)->next == *head ){
		temp->next = *head;
		temp->prev = *head;
		
		(*head)->next = temp;
		(*head)->prev = temp;
		
		*head = temp;
		return;
	}

	t1=(*head)->prev;

	temp->next = *head;
	t1->next = temp;

	(*head)->prev = temp;
	*head = temp;	

	temp->prev = t1;
}

void insertAtPos(struct node **head, int data, int pos){

	int num_nodes = listNodeCount(*head);
	int count = 1;

	if( (pos > num_nodes+1) || (pos < 1)){
		printf("Invalid position choose from 1 to %d position!!\n", num_nodes+1);
		return;
	}

	if(pos == 1){
		insertAtBeg(head, data);
		return;
	}

	if(pos == (num_nodes+1)){
		insertAtEnd(head, data);
		return;
	}

	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("Memory allocation failed !!\n");
		return;
	}
	
	struct node *t1;
	t1=*head;

	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;

	while(count != pos-1){
		count++;
		t1=t1->next;
	}

	temp->prev = t1;
	temp->next = t1->next;
	
	t1->next->prev = temp;
	t1->next = temp;
}
// ---------- Display functions----------------
void displayList(struct node *head){
	struct node *t1;
	t1 = head;
	printf("Head - [%04lx]\n", (unsigned long)t1 & 0xFFFF);

	if(head == NULL){
		return;
	}

	printf("[%04lx]|[%d]|[%04lx]-->",  (unsigned long)t1->prev & 0xFFFF, t1->data, (unsigned long)t1->next & 0xFFFF);

	t1=t1->next;

	while(t1!=head){
		printf("[%04lx]|[%d]|[%04lx]-->",  (unsigned long)t1->prev & 0xFFFF, t1->data, (unsigned long)t1->next & 0xFFFF);
		t1=t1->next;
	}

	printf("\n");
}

// ------------Delete functions----------------

void deleteFromEnd(struct node **head){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	if((*head)->next == *head){
		free(*head);
		*head = NULL;
		return;
	}

	struct node *t1;
	t1 = (*head)->prev->prev;

	free(t1->next);
	t1->next = *head;
	
	(*head)->prev = t1;
}


void deleteFromBeg(struct node **head){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	if((*head)->next == *head){
		free(*head);
		*head = NULL;
		return;
	}

	struct node *t1;
	t1 = *head;

	*head = t1->next;
	t1->next->prev = t1->prev;
	t1->prev->next = t1->next;

	free(t1);
}

void deleteFromPos(struct node **head, int pos){
	if(*head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	int num_nodes = listNodeCount(*head);
	int count = 1;

	if( (pos > num_nodes) || (pos < 1) ){
		printf("Invalid position choose from 1 to %d position!!\n", num_nodes);
		return;
	}

	if(pos == 1){
		deleteFromBeg(head);
		return;
	}
	if(pos == num_nodes){
		deleteFromEnd(head);
		return;
	}
	
	struct node *t1;
	t1 = *head;

	while(count != pos){
		count++;
		t1=t1->next;
	}

	t1->prev->next = t1->next;
	t1->next->prev = t1->prev;

	free(t1);
}
int listNodeCount(struct node *head){
	int count = 1;
	struct node *t1;
	t1=head;
	
	if(head == NULL){
		return 0;
	}else{
		while(t1->next != head){
			count++;
			t1=t1->next;
		}
	}
	return count;
}
