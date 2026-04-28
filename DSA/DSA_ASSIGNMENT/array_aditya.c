`	#include <stdio.h> 
#include <ctype.h> 
#define nl printf("\n"); 
#define FILE_NAME "array_data.txt"

enum MenuOptions {
    MENU = 1,
    DISPLAY,
    INSERT_ALL,
    INSERT_BY_INDEX,
    DELETE_BY_INDEX,
    DELETE_BY_VALUE,
    SEARCH_BY_INDEX,
    SEARCH_BY_VALUE,
    UPDATE,
    SHIFT,
    BETWEEN,
    EXIT
};

//All Function Declaration
void saveToFile(int array[]);
void loadFromFile(int array[]); 
void menu();
void display(int array[]);
void takeArray(int array[]);
void insert(int array[], int num, int index);
void deleteByindex(int array[], int index);
void deleteByValue(int array[], int num);
void searchByindex(int array[],int index);
void searchByValue(int array[],int num);
void update(int array[], int num, int index);
void shiftArray(int arr[] );
void between(int arr[]);


//MAIN
int main(void)
{	
	int arr[10] , choice_raw, index , num; 
	
	//loads the array from file
	loadFromFile(arr);
	
	printf("\n\n<----- Array Operations ----->\n\n");
	printf("1.Menu\n2.Display\n3.Insert All\n4.Insert by Idx\n5.Delete by Idx\n6.Delete by Val\n7.Search by Idx\n8.Search by Val\n9.Update\n10.Shift\n11.Insert Between\n12.Exit\n");
    
	while(1) 
	{
		printf("\nEnter choice for operations => "); 
		if(scanf("%d", &choice_raw) != 1) break;nl

		enum MenuOptions choice = (enum MenuOptions)choice_raw;
		
		switch(choice)
		{
			case MENU:
			printf("1.Menu\n2.Display\n3.Insert All\n4.Insert by Idx\n5.Delete by Idx\n6.Delete by Val\n7.Search by Idx\n8.Search by Val\n9.Update\n10.Shift\n11.Insert Between\n12.Exit\n");
			continue;
	
			case DISPLAY:
			display(arr); //displays array
			continue; 
			
			case INSERT_ALL:
			printf("Enter  Elements:\n"); 
			takeArray(arr); // takes the whole array
			continue; 
			
			case INSERT_BY_INDEX:
			printf("Enter (Number , index) to insert element => "); 
			scanf("%d %d", &num , &index); 
			insert(arr,num,index);// inserting array with number and index
			continue; 
			
			case DELETE_BY_INDEX:
			printf("Enter index to delete => "); 
			scanf("%d", &index); 		
			deleteByindex(arr,index);// deleting array by index input 
			continue; 
			
			case DELETE_BY_VALUE:
			printf("Enter Number to delete => "); 
			scanf("%d", &num); 		
			deleteByValue(arr,num);// deleting array by number input
			continue; 
			
			case SEARCH_BY_INDEX:
			printf("Enter index to return array element => "); 
			scanf("%d", &index); 
			searchByindex(arr,index);// searching element by index input
			continue; 
			
			case SEARCH_BY_VALUE:
			printf("Enter Number to search array => "); 
			scanf("%d", &num); 		
			searchByValue(arr,num);// searching element by value input
			continue;
			
			case UPDATE:
			printf("Enter (Number , index) to update array => "); 
			scanf("%d %d", &num , &index); 		
			update(arr,num,index);// array update 
			continue;

			case SHIFT: 
			printf("Before shift : "); 
			display(arr);nl
			printf("After shift  : ");
			shiftArray(arr); 	
			continue; 
			
			case BETWEEN:
			between(arr);
			continue;	
			
			case EXIT: 
			saveToFile(arr);
			goto exit_;// exit case
			
			default:
			continue;
		}//switch
	}//while
	exit_: printf("----Exit----\n\n");// exited out of the while loop 
}//main

// Function to save the array to a file
void saveToFile(int array[])
{
	FILE *file = fopen(FILE_NAME,"w");
	if(file == NULL)
	{	
		printf("Error opening file for writing!");nl
		return;
	}
	for(int i = 0; i<10; i++)
	{	
		fprintf(file, "%d\n",array[i]);
	}
	fclose(file);
	printf("Array successfully saved to %s",FILE_NAME);nl
}

// Function to load the array from a file
void loadFromFile(int array[]) 
{
	FILE *file = fopen(FILE_NAME, "r");
	if (file == NULL) 
	{
		printf("No existing data found. Starting with a blank array.");nl
		// Initialize with -99 if file doesn't exist
		for(int i = 0; i < 10; i++) 
		{
			array[i] = -99;
		}
		return;
	}
	for (int i = 0; i < 10; i++) 
	{
		if (fscanf(file, "%d", &array[i]) == EOF)//EOF = end of file 
		{
		array[i] = -99; // Fill remainder if file is short
		}
	}
	fclose(file);
	printf("Array loaded from %s", FILE_NAME);nl
}

//Fucntion to display a menu
void menu()
{
	printf("1.Display\n2.Insert All\n3.Insert by Idx\n4.Delete by Idx\n5.Delete by Val\n6.Search by Idx\n7.Search by Val\n8.Update\n9.Shift\n10.Between\n11.Exit\n");
}
//Function to display array
void display(int array[])
{
	printf("Array => { "); 
	for(int i=0 ; i<10; i++)
		{
			printf("%d  " , array[i]); 
		}
	printf(" }");nl	
}

// Function to take whole array at a time 
void takeArray(int array[])
{
	for(int i=0 ; i<10; i++)
		{	
			printf("Element %d: ",i+1);
			scanf("%d" , &array[i]); 
		}
}

//Function to insert element into array 
void insert(int array[], int num, int index)
{
	if(array[index] != -99)
	{
		printf("\n Record Already exists.\n Finding next empty index..\n");
		int inserted = 0;
		for(int i = index; i < 10; i++)
		{
			if(array[i] == -99)
			{            
				printf(" \n Empty slot found at index => %d\n Continue write? y/n => " , i );  
				char insert; 
				scanf(" %c",&insert); 
				insert = tolower(insert); 

				if(insert=='y')
				{
					array[i] = num;
					inserted = 1;
					break;
				}
				else 
				{ 
					inserted = 1; 
					break;
				} 
			}
		}
		if(inserted != 1)
		{
			for(int i = 0; i < index; i++)
			{
				if(array[i] == -99)
				{            
					printf(" \n Empty slot found at index => %d\n Continue write? y/n => " , i );  
					char insert; 
					scanf(" %c",&insert); 
					insert = tolower(insert); 

					if(insert=='y')
					{
						array[i] = num;
						inserted = 1;
						break;
					}
					else 
					{ 
						inserted = 1; 
						break;
					} 
				}
			}
		}
		if(inserted == 0)
		{	
			printf(" Array is completely full, Could not insert.\n");
		}
	}
	else    
	{
		array[index] = num;
	}nl

		display(array);
}//Insert fuction

//Function to delete element at an array index
void deleteByindex(int array[], int index)
{
	array[index] = -99;nl
	display(array);
}

//Function to delete element in an array by value
void deleteByValue(int array[], int num)
{
	int found ; 
	for(int i=0;i<10;i++)
	{
		if(array[i]==num)
		{	
			array[i] = -99; 
			printf("\n Record found and deleted at index => %d.\n", i);
			found = 1;
			break; 	
		}
	}
	if(found != 1) printf("\n Record not found.\n");

	display(array);
}

//Function to return elemnt at an index
void searchByindex(int array[],int index)
{	
	int found ; 
	
	if( array[index] != -99) 
		{
			printf("\n Element at index %d => %d\n" , index , array[index]); 
			found = 1; 
		}
	if(found != 1) printf("\n Record not found.\n");

	display(array);
}

//Function to search a record in array 
void searchByValue(int array[],int num)
{	
	int found ; 
	for(int i=0;i<10;i++)
	{
		if(array[i]==num)
		{	
			printf("\n Record found at %d.\n", i);
			found = 1;	
		}
	}
	if(found != 1) printf("\n Record not found.\n");
	
	display(array);
}

//Function to update an element in array
void update(int array[], int num, int index)
{
	char input; 
	if( array[index] == -99) array[index] = num;

	if( array[index] != -99)
	{
		printf("\n Existing record found at this index.\n");
		printf("\n Do you want to update the existing record Y/N\n"); 
		scanf(" %c", &input); 
		input = tolower(input); 
		if(input == 'y'){ 
			array[index] = num;
		}
		//else ; 	 		
	}
	display(array);


}

//Function to shift array if last index are default
void shiftArray(int arr[] ) 
{
    while (arr[9] == -99) 
    {
        for (int i=9; i>0; i--) 
        {
            arr[i] = arr[i-1];
        } 
        *arr = -99;
    }
    display(arr);
}

//Function to insert the value in between the array
void between(int arr[]) 
{
	int num, targetIdx;
	printf("Enter value and target index (0-9): ");
	if (scanf("%d %d", &num, &targetIdx) != 2 || targetIdx < 0 || targetIdx > 9) 
	{
		printf("Invalid input.\n");
		return;
	}

	// Check for empty space on the right side first
	int emptyRight = -1;//flag 0 is valid index so used -1 
	for (int i = targetIdx; i < 10; i++) 
	{
		if (arr[i] == -99) 
		{
		emptyRight = i;
		break;
		}
	}

	if (emptyRight != -1) 
	{
	// Shift Right
		for (int i = emptyRight; i > targetIdx; i--) 
		{
			arr[i] = arr[i - 1];
		}
		arr[targetIdx] = num;
		printf("Shifted right to insert.\n");
	} 
	else 
	{
		// Right is full, goes on the left side, starting from the left of the target index
		int emptyLeft = -1;
		for (int i = targetIdx; i >= 0; i--) 
		{
			if (arr[i] == -99) 
			{
				emptyLeft = i;
				break;
			}
		}

		if (emptyLeft != -1) 
		{
			// Shift Left
			for (int i = emptyLeft; i < targetIdx; i++) 
			{
				arr[i] = arr[i + 1];
			}
			arr[targetIdx] = num;
			printf("Shifted left to insert.\n");
		} 
		else 
		{
			printf("Array is completely full! No space to shift.\n");
		}
	}
	display(arr);
}
// ALL FUNCTIONS END

