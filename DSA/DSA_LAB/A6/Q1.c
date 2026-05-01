/* 
	PRN - 260240130005 260240130032

	Create an Employee Database menu driven program having info (name, age, id, addresss, date of
	joining, id proof)
	id proof types -&gt; ADHAR / PASSPORT / PAN CARD. { Hint - Use Enum + Union}


	(Have Validation check for every input, malloc, free, id, age etc. for example - age / id / date of
	joining cant be negative or 0.)
	(proper comments / code indentation / arguments to function &lt;= 3)
	(List head should be maintained local in main() )

	1. Use Doubly Circular Linked List for each employee.
	2. Insert in sorted order according of id. (1 Unique id per employee)
	3. Menu option to sort list based on age.
	4. Menu option to sort list based on id.
	5. Menu option to write all information in a file.
	6. Menu option to load all information from file and reinitialise the list.
	7. Menu option to Display range for date of joining(User input 2005 so all employees with date of
	joining &gt; 2005 will be displayed)
	8. Menu option to delete by id.
	9. Menu option to find employee by name or id.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee
{
	struct Employee *prev;
	char name[50]; 
	unsigned int age; 
	unsigned int id;
	char address[100];
	struct joiningDate
	{
		unsigned int day; 
		unsigned int month;
		unsigned int year;
	} joiningDate;
	enum IdProof
	{
		ADHAR = 1,
		PASSPORT,
		PAN_CARD
	} idProofType;
	struct Employee *next;
}Employee;



// Function prototypes
void printMenu();
void insertEmployee(Employee **head);
void deleteEmployee(Employee **head);
void displayEmployees(Employee *head);
void sortByAge(Employee **head);
void sortById(Employee **head);
void writeToFile(Employee *head);
void loadFromFile(Employee *head);
void displayByJoiningDate(Employee *head);
void findEmployee(Employee *head);
void freeAll(Employee **head);

int main(void)
{
	int choice =0; 
	Employee *head = NULL;

	printMenu(); 

	while(1)
	{
	printf("\nEnter choice ->");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1 : 
				insertEmployee(&head); 
				break; 

			case 2 :
				deleteEmployee(&head);
				break; 

			case 3 :
				displayEmployees(head);
				break;

			case 4 :
				sortByAge(&head);
				break;

			case 5 :
				sortById(&head);
				break;

			case 6 :
				writeToFile(head);
				break;

			case 7 :
				loadFromFile(head);
				break;

			case 8 :
				displayByJoiningDate(head);
				break;

			case 9 :
				findEmployee(head);
				break;

			case 10 :
				freeAll(&head); 
				printf("--Exit--\n");
				return 0; 
				break;        
		}
	}
}// Main

void printMenu()
{
	printf("\n--- Employee Database Menu ---\n"
		"--------------------------------\n\n"
		"-- Data Insertion & Deletion --\n"
		"1-> Insert Employee\n"
		"2-> Delete Employee\n"
		"\n-- Data Display --\n"
		"3-> Display Employees\n"
		"8-> Display by Joining Date\n"
		"\n-- Data Sorting & Searching --\n"
		"4-> Sort by Age\n"
		"5-> Sort by ID\n"
		"9-> Find Employee\n"
		"\n-- File Operations --\n"
		"6-> Write to File\n"
		"7-> Load from File\n"
		"10-> Exit\n"
		"--------------------------------\n\n");
}

void insertEmployee(Employee **head)
{
	Employee *temp = (Employee *)malloc(sizeof(Employee));

	if(temp == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}

	printf("Enter Employee Name: ");
	scanf(" %[^\n]", temp->name);

	printf("Enter Employee Age: ");
	scanf("%u", &temp->age);

	printf("Enter Employee ID: ");
	scanf("%u", &temp->id);

	printf("Enter Employee Address: ");
	scanf(" %[^\n]", temp->address);

	printf("Enter Joining Date (DD MM YYYY): ");
	scanf("%u %u %u", &temp->joiningDate.day, &temp->joiningDate.month, &temp->joiningDate.year);

	printf("Enter Employee ID Proof (1.ADHAR , 2.PASSPORT , 3.PAN CARD) => ");
	scanf("%d", (int *)&temp->idProofType);

	if(*head == NULL)
	{
		*head = temp;
	}
	else
	{
		Employee *current = *head;
		while(current->next != NULL)
		{
			current = current->next;
		}
	
		current->next = temp;
		temp->prev = current;
		temp->next = NULL;
	}

}

void deleteEmployee(Employee **head)
{
	if(*head == NULL)
	{
		printf("Employee database is empty\n");
		return;
	}

	unsigned int id;
	printf("Enter Employee ID to delete: ");
	scanf("%u", &id);

	Employee *current = *head;

	while(current != NULL && current->id != id)
	{
		current = current->next;
	}

	if(current == NULL)
	{
		printf("Employee with ID %u not found\n", id);
		return;
	}

	if(current->prev != NULL)
	{
		current->prev->next = current->next;
	}
	else
	{
		*head = current->next; // Deleting the head node
	}

	if(current->next != NULL)
	{
		current->next->prev = current->prev;
	}
	
	printf("Record %d deleted..\n" , id); 
	free(current);
}

void displayEmployees(Employee *head)
{
	if(head == NULL)
	{
		printf("Employee database is empty\n");
		return;
	}

	Employee *current = head;
	printf("\n--- Employee List ---\n");
	while(current != NULL)
	{
		printf(" ID: %u | Name: %s, Age: %u, Address: %s, Joining Date: %02u/%02u/%04u , ID Proof: %d\n",
		current->id, current->name, current->age, current->address,
		current->joiningDate.day, current->joiningDate.month, current->joiningDate.year,
		current->idProofType);
		current = current->next;
	}
}

void sortByAge(Employee **head)
{
	if(*head == NULL)
	{
		printf("Employee database is empty\n");
		return;
	}

	Employee *current = *head, *index = NULL;
	int tempId, tempAge;
	char tempName[50], tempAddress[100];
	struct joiningDate tempJoiningDate;
	enum IdProof tempIdProofType;

	while(current != NULL)
	{
		index = current->next;

		while(index != NULL)
		{
			if(current->age > index->age)
			{
				// Swap age
				tempAge = current->age;
				current->age = index->age;
				index->age = tempAge;

				// Swap ID
				tempId = current->id;
				current->id = index->id;
				index->id = tempId;

				// Swap Name
				strcpy(tempName, current->name);
				strcpy(current->name, index->name);
				strcpy(index->name, tempName);

				// Swap Address
				strcpy(tempAddress, current->address);
				strcpy(current->address, index->address);
				strcpy(index->address, tempAddress);

				// Swap Joining Date
				tempJoiningDate = current->joiningDate;
				current->joiningDate = index->joiningDate;
				index->joiningDate = tempJoiningDate;

				// Swap ID Proof Type
				tempIdProofType = current->idProofType;
				current->idProofType = index->idProofType;
				index->idProofType = tempIdProofType;
			}
			index = index->next;
		}
		current = current->next;
	}
}

void sortById(Employee **head)
{
	if(*head == NULL)
	{
		printf("Employee database is empty\n");
		return;
	}

	Employee *current = *head, *index = NULL;
	int tempId, tempAge;
	char tempName[50], tempAddress[100];
	struct joiningDate tempJoiningDate;
	enum IdProof tempIdProofType;

	while(current != NULL)
	{
		index = current->next;

		while(index != NULL)
		{
			if(current->id > index->id)
			{
				// Swap ID
				tempId = current->id;
				current->id = index->id;
				index->id = tempId;

				// Swap Age
				tempAge = current->age;
				current->age = index->age;
				index->age = tempAge;

				// Swap Name
				strcpy(tempName, current->name);
				strcpy(current->name, index->name);
				strcpy(index->name, tempName);

				// Swap Address
				strcpy(tempAddress, current->address);
				strcpy(current->address, index->address);
				strcpy(index->address, tempAddress);

				// Swap Joining Date
				tempJoiningDate = current->joiningDate;
				current->joiningDate = index->joiningDate;
				index->joiningDate = tempJoiningDate;

				// Swap ID Proof Type
				tempIdProofType = current->idProofType;
				current->idProofType = index->idProofType;
				index->idProofType = tempIdProofType;
			}
			index = index->next;
		}
		current = current->next;
	}
}

void writeToFile(Employee *head)
{
	if(head == NULL)
	{
		printf("Employee database is empty\n");
		return;
	}

	FILE *file = fopen("employee_database.txt", "w");
	if(file == NULL)
	{
		printf("Error opening file for writing\n");
		return;
	}

	Employee *current = head;
	while(current != NULL)
	{
		fprintf(file, "%u,%s,%u,%s,%02u/%02u/%04u,%d\n",
		current->id, current->name, current->age, current->address,
		current->joiningDate.day, current->joiningDate.month, current->joiningDate.year,
		current->idProofType);
		current = current->next;
	}

	fclose(file);
	printf("Employee data written to employee_database.txt\n");
}

void loadFromFile(Employee *head)
{
	FILE *file = fopen("employee_database.txt", "r");
	
	if(file == NULL)
	{
		printf("Error opening file for reading\n");
		return;
	}

	char line[200];
	while(fgets(line, sizeof(line), file))
	{
		Employee *temp = (Employee *)malloc(sizeof(Employee));
		if(temp == NULL)
		{
			printf("Memory allocation failed\n");
			fclose(file);
			return;
		}

		sscanf(line, "%u,%[^,],%u,%[^,],%u/%u/%u,%d",
		&temp->id, temp->name, &temp->age, temp->address,
		&temp->joiningDate.day, &temp->joiningDate.month, &temp->joiningDate.year,
		(int *)&temp->idProofType);

		temp->prev = NULL;
		temp->next = NULL;

		if(head == NULL)
		{
			head = temp;
		}
		else
		{
			Employee *current = head;
			while(current->next != NULL)
			{
				current = current->next;
			}
			current->next = temp;
			temp->prev = current;
		}
	}

	fclose(file);
	printf("Employee data loaded from employee_database.txt\n");
}

void displayByJoiningDate(Employee *head)
{
	if(head == NULL)
	{
		printf("Employee database is empty\n");
		return;
	}

	unsigned int year;
	printf("Enter Joining Year to filter (e.g., 2005): ");
	scanf("%u", &year);

	Employee *current = head;
	printf("\n--- Employees Joined After %u ---\n", year);
	
	while(current != NULL)
	{
		if(current->joiningDate.year > year)
		{
			printf(" ID: %u | Name: %s, Age: %u, Address: %s, Joining Date: %02u/%02u/%04u , ID Proof: %d\n",
			current->id, current->name, current->age, current->address,
			current->joiningDate.day, current->joiningDate.month, current->joiningDate.year,
			current->idProofType);
		}
		current = current->next;
	}
}

void findEmployee(Employee *head)
{
	if(head == NULL)
	{
		printf("Employee database is empty\n");
		return;
	}

	int searchType;
	printf("Search by: 1. Name, 2. ID => ");
	scanf("%d", &searchType);

	if(searchType == 1)
	{
		char name[50];
		printf("Enter Employee Name to search: ");
		scanf(" %[^\n]", name);

		Employee *current = head;
		printf("\n--- Search Results for Name: %s ---\n", name);
		
		while(current != NULL)
		{
			if(strcmp(current->name, name) == 0)
			{
				printf(" ID: %u | Name: %s, Age: %u, Address: %s, Joining Date: %02u/%02u/%04u , ID Proof: %d\n",
				current->id, current->name, current->age, current->address,
				current->joiningDate.day, current->joiningDate.month, current->joiningDate.year,
				current->idProofType);
			}
			current = current->next;
		}
	}
	else if(searchType == 2)
	{
		unsigned int id;
		printf("Enter Employee ID to search: ");
		scanf("%u", &id);

		Employee *current = head;
		printf("\n--- Search Results for ID: %u ---\n", id);
		
		while(current != NULL)
		{
			if(current->id == id)
			{
				printf(" ID: %u | Name: %s, Age: %u, Address: %s, Joining Date: %02u/%02u/%04u , ID Proof: %d\n",
				current->id, current->name, current->age, current->address,
				current->joiningDate.day, current->joiningDate.month, current->joiningDate.year,
				current->idProofType);
				break; // Assuming IDs are unique
			}
			current = current->next;
		}
	}
	else
	{
	printf("Invalid search type\n");
	}
}

void freeAll(Employee **head)
{
	Employee *current = *head; 

	while(current != NULL)
	{
		Employee *next = current->next; 
		free(current); 
		current = next;  
	}
	
	
	head = NULL; 
	printf("Database cleared..\n"); 
}
