#include <stdio.h>
#include <stdlib.h>

//enum Action { ADD_ITEM, REMOVE_ITEM, DISPLAY_BASKET, EXIT };

typedef struct Node {
    int item;
    struct Node *next, *prev;
} Node;

Node* createNode(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

void addToBasket(Node** head, int item) {
    if (*head == NULL) {
        *head = createNode(item);
    } else {
        Node* newNode = createNode(item);
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void removeFromBasket(Node** head, int item) {
    if (*head == NULL) return;

    Node* current = *head;
    do {
        if (current->item == item) {
            if (current == *head) {
                if (current->next == current) {
                    free(current);
                    *head = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    *head = current->next;
                    free(current);
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
            }
            return;
        }
        current = current->next;
    } while (current != *head);
}

void displayBasket(Node* head) {
    if (head == NULL) {
        printf("Your basket is empty.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d ", current->item);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
   // enum Action action;
    int item, action;
    Node* head = NULL;

    while (1) {
        printf("1. Add Item\n2. Remove Item\n3. Display Basket\n4. Exit\nChoose an action: ");
        scanf("%d",(int *) &action);

        switch (action) {
            case 1:
                printf("Enter item to add: ");
                scanf("%d", &item);
                addToBasket(&head, item);
                break;
            case 2:
                printf("Enter item to remove: ");
                scanf("%d", &item);
                removeFromBasket(&head, item);
                break;
            case 3:
                displayBasket(head);
                break;
            case 4:
                while (head != NULL) {
                    Node* temp = head->prev;
                    free(head);
                    head = temp;
                }
                return 0;
            default:
                printf("Invalid action.\n");
        }
    }

    return 0;
}
