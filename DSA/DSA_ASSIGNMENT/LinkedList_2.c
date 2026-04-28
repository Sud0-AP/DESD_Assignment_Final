#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert(struct node **, int);
void display(struct node *);
void delete(struct node *);

int main(){
 	struct node *head;
	head = NULL;
	int choice, data;
	
	
	while(1){
		printf("Enter your choice:\n(Enter 1) Insert element to Linked List\n(Enter 2) Display Linked List\n(Enter 3) Delete last node\n(Enter 4) Exit program\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the element you wish to insert:\n");
				scanf("%d", &data);
				insert(&head, data);
				break;
			case 2:
				printf("Current state of linked list:\n");
				display(head);
				break;
			case 3:
				printf("Deleting the last element!!\n");
				delete(head);
				break;				
			case 4:
				exit(1);
				break;
		}
	}

}
void insert(struct node **head, int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	struct node *t1;
	t1 = *head;

	temp->data = data;
	temp->next = NULL;

	if(*head == NULL){
		*head = temp;
	}else{
		while(t1->next != NULL){
			t1 = t1->next;
		}
		t1->next = temp;
	}

}

void display(struct node *head){
	struct node *t1;
	t1 = head;
	
	while(t1!= NULL){
		printf("[%d]|[%p]--->", t1->data, t1->next);
		t1 = t1->next;
	}
	printf("\n");
}

void delete(struct node *head){
		
	struct node *t1;
	t1 = head;
	
	while(t1->next->next!= NULL){
		t1 = t1->next;
	}
	free(t1->next);
	t1->next = NULL;
}
