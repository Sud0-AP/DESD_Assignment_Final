//PRN: 260240130005 260240130032
// Singly linked list with student PRN and Name, with delete element by element

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentInfo{
	char studentName[50];
	int studentPRN;
	struct studentInfo *next;
};

void insertAtEnd(char *, int);
void insertAtBeg(char *, int);
void insertAtPos(char *, int, int);

void displayList();
void reverseDisplay(struct studentInfo *);
int listNodeCount();

void deleteFromEnd();
void deleteFromBeg();
void deleteFromPos(int);
void deleteByElement(int);

void freeAllNode(struct studentInfo *);
void reverseList();
void sortedList();

struct studentInfo *head;

int main(){
	head = NULL;
	int choice, data, pos, choice1;
	char name[50];

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
						printf("Enter the PRN of Student which wish to Insert: ");
						scanf("%d", &data);
						printf("Enter the name of the student:");
						scanf(" %[^\n]", name);
						insertAtEnd(name, data);
						memset(name, 0 , 50);
						break;
					case 2:
						printf("Enter the PRN of Student which wish to Insert: ");
						scanf("%d", &data);
						printf("Enter the name of the student:");
						scanf(" %[^\n]", name);
						insertAtBeg(name, data);
						memset(name, 0 , 50);
						break;
					case 3:
						printf("Enter the PRN of Student which wish to Insert: ");
						scanf("%d", &data);
						printf("Enter the name of the student:");
						scanf(" %[^\n]", name);
						printf("Enter the position at which you wish to Insert: ");
						scanf("%d", &pos);
						insertAtPos(name, data, pos);
						memset(name, 0 , 50);
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
void insertAtEnd(char *name, int data){
	struct studentInfo *temp;
	temp = (struct studentInfo *)malloc(sizeof(struct studentInfo));

	if (temp == NULL){
		printf("Memory allocation failed!!\n");
		return;
	}

	struct studentInfo *t1;
	t1=head;
	
	strcpy(temp->studentName, name);
	temp->studentPRN = data;
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

void insertAtBeg(char *name, int data){
	struct studentInfo *temp;
	temp = (struct studentInfo *)malloc(sizeof(struct studentInfo));

	if (temp == NULL){
		printf("Memory allocation failed!!\n");
		return;
	}

	strcpy(temp->studentName, name);
	temp->studentPRN = data;
	temp->next = head;

	head = temp;
}

void insertAtPos(char *name, int data, int pos){

	int num_nodes = listNodeCount();
	int count = 1;

	if(pos > num_nodes+1){
		printf("Invalid position choose from 1 to %d position!!\n", num_nodes+1);
		return;
	}

	struct studentInfo *temp;
	temp = (struct studentInfo *)malloc(sizeof(struct studentInfo));

	if (temp == NULL){
		printf("Memory allocation failed!!\n");
		return;
	}

	struct studentInfo *t1;
	t1=head;

	strcpy(temp->studentName, name);
	temp->studentPRN = data;
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
	struct studentInfo *t1;
	t1 = head;

	while(t1!=NULL){
		printf("[%s]|[%d]|[%p] ->", t1->studentName, t1->studentPRN, t1->next);
		t1=t1->next;
	}
	printf("\n");
}

void reverseDisplay(struct studentInfo *t1){
	if(t1->next == NULL){
		printf("<--[%p]|[%d]|[%s]", t1->next, t1->studentPRN, t1->studentName);
		return;
	}
	reverseDisplay(t1->next);
	printf("<--[%p]|[%d]|[%s]", t1->next, t1->studentPRN, t1->studentName);
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

	struct studentInfo *t1;
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

	struct studentInfo *t1;
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

	struct studentInfo *t1;
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
		struct studentInfo *t2;
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
	struct studentInfo *t1;
	t1 = head;
	
	if(t1->studentPRN == element){
		head = t1->next;
		free(t1);
	}else{
		struct studentInfo *t2;

		while(t1!=NULL){
			t2 = t1;
			t1 = t1->next;
			if(t1->studentPRN == element){
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
	struct studentInfo *t1;
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

void freeAllNode(struct studentInfo *t1){
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

}
void sortedList(){
}


