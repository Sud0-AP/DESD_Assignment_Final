#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insertAtEnd(int);
void insertAtBeg(int);
void insertAtPos(int, int);

void displayList();
void reverseDisplay(struct node *);
int listNodeCount();

void deleteFromEnd();
void deleteFromBeg();
void deleteFromPos(int);
void deleteByElement(int);

void freeAllNode(struct node *);
void reverseList();
void sortedList();

struct node *head;

int main(){
	head = NULL;
	int choice, data, pos, choice1;

	while(1){
		printf("Enter your choice:\n(Enter 1) Insert element to Linked List\n(Enter 2) Display Linked List\n(Enter 3) Delete from the linked list\n(Enter 4) other operations\n(Enter 5) Exit\n");

		scanf("%d", &choice);

		if(choice < 1 || choice > 5){
			return 0;
		}

		switch(choice){
			case 1:
				printf("What do you wish to do? \n");
				printf("(Enter 1) Insert at end\n(Enter 2) Insert at Begining\n(Enter 3) Insert at position\n(Enter 4) Go back\n");
				scanf("%d", &choice1);
				if(choice1<1 || choice1>4){
					printf("Invalid choice!!\n");
					break;
				}else {
				switch(choice1){ 
					case 1:
						printf("Enter the Value which you wish to Insert: ");
						scanf("%d", &data);
						insertAtEnd(data);
						break;
					case 2:
						printf("Enter the Value which you wish to Insert: ");
						scanf("%d", &data);
						insertAtBeg(data);
						break;
					case 3:
						printf("Enter the Value and position at which you wish to Insert: ");
						scanf("%d %d", &data, &pos);
						insertAtPos(data, pos);
						break;
					case 4:
						break;				
					}
					break;
				}
			case 3:
				printf("What do you wish to do? \n");
				printf("(Enter 1) Delete from the end\n(Enter 2) Delete from the Begining\n(Enter 3) delete from position\n(Enter 4) delete by value\n(Enter 5) Delete the whole linked list\n(Enter 6) Go back\n");
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
						printf("Enter the element which you wish to delete: ");
						scanf("%d", &data);
						deleteByElement(data);
						break;
					case 5:
						freeAllNode(head);
						break;
					case 6:
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
				printf("What do you wish to perform:\n(Enter 1) Count the number of nodes in the Linked list\n(Enter 2) Reverse the Linked list\n(Enter 3) Sort the Linked List\n(Enter 4) Go Back\n");
				scanf("%d", &choice1);
				if(choice1<1 || choice1>4){
					printf("Invalid choice!!\n");
					break;
				}
				switch(choice1){
					case 1:	
						printf("Number of nodes in the Linked list = %d\n", listNodeCount());
						break;
					case 2:
						reverseList();
						break;
					case 3:
						sortedList();
						break;
					case 4:
						break;
				}

				break;
			case 5:
				exit(1);
				break;

		}
	}
	return 0;

}

//-------------Insert Functions -------------
void insertAtEnd(int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	struct node *t1;
	t1=head;

	temp->data = data;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
	}else{
		while(t1->next!=NULL){
			t1=t1->next;
		}
		t1->next = temp;
	}
}

void insertAtBeg(int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->next = head;

	head = temp;
}

void insertAtPos(int data, int pos){

	int num_nodes = listNodeCount();
	int count = 1;

	if(pos > num_nodes+1){
		printf("Invalid position choose from 1 to %d position!!\n", num_nodes+1);
		return;
	}

	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	struct node *t1;
	t1=head;

	temp->data = data;
	temp->next = NULL;

	if(head == NULL && pos == 1){
		head = temp;
	}else if(pos == 1 && head != NULL){
		temp->next = head;
		head = temp;
	}else{
		while(count != pos-1 && t1->next != NULL){
			count++;
			t1=t1->next;
		}
		temp->next = t1->next;
		t1->next = temp;
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

void deleteByElement(int element){
	if(head == NULL){
		printf("List is empty!!\n");
		return;
	}
	struct node *t1;
	t1 = head;
	
	if(t1->data == element){
		head = t1->next;
		free(t1);
	}else{
		struct node *t2;

		while(t1!=NULL){
			t2 = t1;
			t1 = t1->next;
			if(t1->data == element){
				t2->next = t1->next;
				free(t1);
				return;
			}
		}
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

void reverseList(){
	struct node *t1, *t2, *t3;
	if(head == NULL || head->next == NULL){
		return;
	}
	t1 = head;
	t2 = NULL;
		while(t1 != NULL){
			t3 = t2;
			t2 = t1;
			t1 = t1->next;
			t2->next = t3;
		}
	head = t2;
}

void sortedList(){
	
	int swapflag;
	struct node *t1;
	struct node *x = NULL;

	if(head == NULL || head->next == NULL)
		return;
	do
	{
		swapflag = 0;
		t1 = head;
		while(t1->next!=x){
			if(t1->data > t1->next->data){
				int temp = t1->data;
				t1->data = t1->next->data;
				t1->next->data = temp;
				swapflag = 1;
			}
			t1 = t1->next;
		}
		x = t1;
	}while(swapflag);


}

