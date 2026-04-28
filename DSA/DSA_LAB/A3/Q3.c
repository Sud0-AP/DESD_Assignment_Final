#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert(int);
void insertAfter(struct node *, int);
void insertBefore(struct node *, int);

void displayList();
void reverseDisplay(struct node *);

int listNodeCount();

void deleteFromEnd();
void deleteFromBeg();
void deleteFromPos(int);
void freeAllNode(struct node *);

struct node *head;

int main(){
	head = NULL;
	int choice, data, pos, choice1;

	while(1){
		printf("Enter your choice:\n(Enter 1) Insert element to Linked List\n(Enter 2) Display Linked List\n(Enter 3) Delete from the linked list\n(Enter 4) Count the number of nodes in the linked list\n(Enter 5) Exit\n");

		scanf("%d", &choice);

		if(choice < 1 || choice > 5){
			return 0;
		}

		switch(choice){
			case 1:
				printf("Enter the Value which you wish to Insert: ");
				scanf("%d", &data);
				insert(data);
				break;
			case 3:
				printf("What do you wish to do? \n");
				printf("(Enter 1) Delete from the end\n(Enter 2) Delete from the Begining\n(Enter 3) delete from position\n(Enter 4) Delete the whole linked list\n(Enter 5) Go back\n");
				scanf("%d", &choice1);
				if(choice1<1 || choice1>4){
					printf("Invalid choice!!\n");
					break;
				}else {
				switch(choice1){ 
					case 1:
						deleteFromEnd();
						break;
					case 2:
						deleteFromBeg();
						break;
					case 3:
						printf("Enter the position which you wish to delete: ");
						scanf("%d", &pos);
						deleteFromPos(pos);
						break;
					case 4:
						freeAllNode(head);
						break;
					case 5:
						break;
					}
					break;
				}
			case 2:
				printf("What do you wish to perform:\n(Enter 1) Display the Linked list\n(Enter 2) Display the Linked list in reverse\n(Enter 3) Go Back\n");
				scanf("%d", &choice1);
				if(choice1<1 || choice1>3){
					printf("Invalid choice!!\n");
					break;
				}
				switch(choice1){
					case 1:	
						displayList();
						break;
					case 2:
						reverseDisplay(head);
						break;
					case 3:
						break;
				}

				break;
			case 4:
				printf("Number of nodes in the Linked list = %d\n", listNodeCount());
				break;
			case 5:
				exit(1);
				break;
		}
	}
	return 0;

}

//-------------Insert Functions -------------
void insertAfter(struct node *t1, int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->next = NULL;

	if(t1->next == NULL){
		t1->next = temp;
	}else{
		temp->next = t1->next;
		t1->next = temp;
	}
}

void insertBefore(struct node *t1, int data){
	struct node *temp, *t2;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->next = NULL;

	t2 = head;

	if(t1==head){
		temp->next = head;
		head = temp;
	}else{
		while(t2->next != t1){
			t2 = t2->next;
		}
		temp->next = t1;
		t2->next = temp;
	}
}

void insert(int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	struct node *t1;
	t1=head;

	temp->data = data;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
	}else{
		if(t1->data > data){
			insertBefore(t1, data);
		}else{
			while(t1->next != NULL){
				t1 = t1->next;
				if(t1->data > data){
					insertBefore(t1, data);
					return;
				}
			}
			insertAfter(t1, data);
		}
	}
	
}
// ---------- Display functions----------------
void displayList(){
	struct node *t1;
	t1 = head;

	while(t1!=NULL){
		printf("[%d]|[%p] ->", t1->data, t1->next);
		t1=t1->next;
	}
	printf("\n");
}

void reverseDisplay(struct node *t1){
	if(t1->next == NULL){
		printf("<--[%p]|[%d]", t1->next, t1->data);
		return;
	}
	reverseDisplay(t1->next);
	printf("<--[%p]|[%d]", t1->next, t1->data);
	if(t1 == head){
		printf("\n");
	}
}

// ------------Delete functions----------------

void deleteFromEnd(){
	if(head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	struct node *t1;
	t1 = head;

	while(t1->next->next!=NULL){
		t1=t1->next;
	}
	free(t1->next);
	t1->next = NULL;
}


void deleteFromBeg(){
	if(head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	struct node *t1;
	t1 = head;

	head = t1->next;

	free(t1);
}

void deleteFromPos(int pos){
	if(head == NULL){
		printf("List is Empty!!\n");
		return;
	}

	int num_nodes = listNodeCount();
	int count =0;

	if(pos > num_nodes){
		printf("Invalid position choose from 1 to %d position!!\n", num_nodes);
		return;
	}

	struct node *t1;
	t1 = head;

	if(pos == 1){
		head = t1->next;
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
int listNodeCount(){
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

void freeAllNode(struct node *t1){
	if(t1->next == NULL){
		free(t1);
		return;
	}
	freeAllNode(t1->next);
	free(t1);
	if(t1 == head){
		head = NULL;
		printf("All nodes freed list is now empty!!\n");
	}

}

