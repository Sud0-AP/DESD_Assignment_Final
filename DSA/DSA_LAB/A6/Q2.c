// Shopping Cart CLI - Doubly Circular Linked List Implementation
// PRN: 260240130005 260240130032

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char itemName[50];
    float cost;
    int quantity;
    struct node *next;
    struct node *prev;
};

// Insert item into cart (maintaining sorted order by cost)
void insertItem(struct node **, char *, float, int);
// Delete item from cart by name
void deleteItem(struct node **, char *);
// Display all items in cart
void displayCart(struct node *);
// Calculate total cost and item count
void cartSummary(struct node *);
// Search for item by name
struct node *searchItem(struct node *, char *);
// Sort cart by cost (bubble sort)
void sortByPrice(struct node **);
// Check if cart is empty
int isEmpty(struct node *);
// Count unique items
int countItems(struct node *);

int main() {
    struct node *head = NULL;
    int choice;
    char itemName[50];
    float cost;
    int quantity;

    while (1) {
        printf("\n========== SHOPPING CART ==========\n");
        printf("(Enter 1) Add item to cart\n");
        printf("(Enter 2) Delete item from cart\n");
        printf("(Enter 3) View cart\n");
        printf("(Enter 4) View cart summary\n");
        printf("(Enter 5) Sort cart by price\n");
        printf("(Enter 6) Exit\n");
        printf("===================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = 0; // remove newline
                
                printf("Enter cost: ");
                scanf("%f", &cost);
                
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                getchar(); // consume newline
                
                if (cost > 0 && quantity > 0) {
                    insertItem(&head, itemName, cost, quantity);
                    printf("Item added successfully!\n");
                } else {
                    printf("Invalid cost or quantity!\n");
                }
                break;

            case 2:
                printf("Enter item name to delete: ");
                fgets(itemName, sizeof(itemName), stdin);
                itemName[strcspn(itemName, "\n")] = 0;
                
                if (isEmpty(head)) {
                    printf("Cart is empty!\n");
                } else if (searchItem(head, itemName) == NULL) {
                    printf("Item not found in cart!\n");
                } else {
                    deleteItem(&head, itemName);
                    printf("Item deleted successfully!\n");
                }
                break;

            case 3:
                if (isEmpty(head)) {
                    printf("Cart is empty!\n");
                } else {
                    printf("\n========== CART ITEMS ==========\n");
                    displayCart(head);
                    printf("================================\n");
                }
                break;

            case 4:
                if (isEmpty(head)) {
                    printf("Cart is empty!\n");
                } else {
                    cartSummary(head);
                }
                break;

            case 5:
                if (isEmpty(head)) {
                    printf("Cart is empty!\n");
                } else {
                    sortByPrice(&head);
                    printf("Cart sorted by price!\n");
                }
                break;

            case 6:
                printf("Thank you for shopping!\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Insert item into cart (doubly circular linked list)
void insertItem(struct node **head, char *name, float price, int qty) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->itemName, name);
    newNode->cost = price;
    newNode->quantity = qty;

    if (*head == NULL) {
        // First node
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        // Check if item already exists
        struct node *temp = searchItem(*head, name);
        if (temp != NULL) {
            temp->quantity += qty;
            free(newNode);
            printf("Item quantity updated!\n");
            return;
        }

        // Find insertion point to maintain sorted order by cost
        struct node *current = *head;
        struct node *tail = (*head)->prev;

        if (price <= current->cost) {
            // Insert at beginning
            newNode->next = *head;
            newNode->prev = tail;
            tail->next = newNode;
            (*head)->prev = newNode;
            *head = newNode;
        } else if (price >= tail->cost) {
            // Insert at end
            newNode->next = *head;
            newNode->prev = tail;
            tail->next = newNode;
            (*head)->prev = newNode;
        } else {
            // Insert in middle
            while (current->next != *head && current->next->cost < price) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }
}

// Delete item from cart by name
void deleteItem(struct node **head, char *name) {
    if (*head == NULL) {
        return;
    }

    struct node *current = *head;
    struct node *foundNode = NULL;

    // Search for the node
    if (strcmp(current->itemName, name) == 0) {
        foundNode = current;
    } else {
        current = current->next;
        while (current != *head && strcmp(current->itemName, name) != 0) {
            current = current->next;
        }
        if (strcmp(current->itemName, name) == 0) {
            foundNode = current;
        }
    }

    if (foundNode == NULL) {
        return;
    }

    if (foundNode->next == foundNode) {
        // Only one node
        *head = NULL;
    } else {
        foundNode->prev->next = foundNode->next;
        foundNode->next->prev = foundNode->prev;
        if (foundNode == *head) {
            *head = foundNode->next;
        }
    }

    free(foundNode);
}

// Display all items in cart
void displayCart(struct node *head) {
    if (head == NULL) {
        return;
    }

    struct node *current = head;
    int index = 1;

    printf("%-5s %-20s %-10s %-10s %-10s\n", "No.", "Item Name", "Cost", "Qty", "Total");
    printf("%-5s %-20s %-10s %-10s %-10s\n", "---", "----------", "----", "---", "-----");

    do {
        printf("%-5d %-20s %-10.2f %-10d %-10.2f\n", 
               index, current->itemName, current->cost, 
               current->quantity, current->cost * current->quantity);
        current = current->next;
        index++;
    } while (current != head);
}

// Calculate total cost and item count
void cartSummary(struct node *head) {
    if (head == NULL) {
        return;
    }

    struct node *current = head;
    float totalCost = 0;
    int totalItems = 0;

    do {
        totalItems += current->quantity;
        totalCost += (current->cost * current->quantity);
        current = current->next;
    } while (current != head);

    printf("\n========== CART SUMMARY ==========\n");
    printf("Total unique items: %d\n", countItems(head));
    printf("Total items (quantity): %d\n", totalItems);
    printf("Total cost: Rs. %.2f\n", totalCost);
    printf("==================================\n");
}

// Count unique items
int countItems(struct node *head) {
    if (head == NULL) {
        return 0;
    }

    struct node *current = head;
    int count = 1;

    current = current->next;
    while (current != head) {
        count++;
        current = current->next;
    }

    return count;
}

// Search for item by name
struct node *searchItem(struct node *head, char *name) {
    if (head == NULL) {
        return NULL;
    }

    struct node *current = head;

    do {
        if (strcmp(current->itemName, name) == 0) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return NULL;
}

// Sort cart by price (bubble sort)
void sortByPrice(struct node **head) {
    if (*head == NULL || (*head)->next == *head) {
        return;
    }

    struct node *end = (*head)->prev;
    int swapped;

    do {
        swapped = 0;
        struct node *current = *head;

        do {
            if (current->cost > current->next->cost) {
                // Swap data between nodes
                char tempName[50];
                float tempCost;
                int tempQty;

                strcpy(tempName, current->itemName);
                tempCost = current->cost;
                tempQty = current->quantity;

                strcpy(current->itemName, current->next->itemName);
                current->cost = current->next->cost;
                current->quantity = current->next->quantity;

                strcpy(current->next->itemName, tempName);
                current->next->cost = tempCost;
                current->next->quantity = tempQty;

                swapped = 1;
            }
            current = current->next;
        } while (current != end && current != *head);

        end = end->prev;
    } while (swapped && end != *head);
}

// Check if cart is empty
int isEmpty(struct node *head) {
    return head == NULL;
}