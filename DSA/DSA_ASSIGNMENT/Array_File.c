#include<stdio.h>

#define SIZE 5

void insert(int arr[],int index, int element);
void deleteElement(int arr[],int index);
int search(int arr[],int element);
void display(int arr[],int index);
void saveToFile(int arr[]);
void loadFromFile(int arr[]);

int main()
{ 
 int arr[SIZE];

 // Load previous data
 loadFromFile(arr);

 int choice,loc,ele;

 while(1)
 {
  printf("\nEnter 1 to insert element\nEnter 2 to delete element\nEnter 3 to search elements\nEnter 4 to display elements\nEnter 5 to exit\n");
  scanf("%d", &choice);
	
  switch(choice)
  {
   case 1:
    printf("\nEnter the element and index to insert: ");
    scanf("%d %d", &ele, &loc);
    insert(arr,loc,ele);
    display(arr,SIZE);
    printf("\n");
    break;

   case 2:
    printf("\nEnter the index to delete: ");
    scanf("%d", &loc);
    deleteElement(arr,loc);
    display(arr,SIZE);
    printf("\n");
    break;

   case 3:
    printf("\nEnter the element to search: ");
    scanf("%d", &ele);

    int i = search(arr,ele);

    if(i >= 0)   // fixed condition
      printf("The element %d is at index %d\n",ele,i);

    printf("\n");
    break;

   case 4:
    printf("The elements of array are: ");
    display(arr,SIZE);
    printf("\n");
    break;

   case 5:
   {
    int ch;
    printf("Do you want to save data? (1-Yes / 0-No): ");
    scanf("%d",&ch);

    if(ch==1)
    {
        saveToFile(arr);
        printf("Data saved successfully.\n");
    }
    else
    {
        printf("Data not saved.\n");
    }

    printf("Exiting....Thankyou!\n");
    return 0;
   }

   default:
    printf("Invalid option \n");
  }
 }
}



void display(int arr[],int index)
{
 for(int i=0;i<index;i++)
 {
  printf("%d ",arr[i]);
 }
}


void insert(int arr[],int index, int element)
{
 if(index < 0 || index >= SIZE)
 {
  printf("Invalid index!\n");
  return;
 }

 // prevent duplicate
 for(int i=0;i<SIZE;i++)
 {
  if(arr[i]==element)
  {
   printf("Element already exists. Cannot insert.\n");
   return;
  }
 }

 if(arr[index]==-99)
 {
  arr[index]= element;
 }
 else
 {
  printf("Index occupied. Finding empty slot...\n");

  for(int i=0;i<SIZE;i++)
  {
   if(arr[i]==-99)
   {
    arr[i]= element;
    return;
   }
  }

  printf("Array is full!\n");
 }
}



void deleteElement(int arr[],int index)
{
 if(index < 0 || index >= SIZE)
 {
  printf("Invalid index!\n");
  return;
 }

 if(arr[index]!=-99)
 {
  arr[index]= -99;
 }
 else
 {
  printf("Element at given index does not exist\n");
 }
}



int search(int arr[],int element)
{
 for(int i=0;i<SIZE;i++)
 {
  if(arr[i]==element)
  {
   return i;
  }
 }

 printf("The element does not exist\n");
 return -1;
}

//Save to file
void saveToFile(int arr[])
{
 FILE *fp = fopen("data.txt","r+");

 if(fp==NULL)
 {
  printf("Error opening file\n");
  return;
 }

 for(int i=0;i<SIZE;i++)
 {
  fprintf(fp,"%d ",arr[i]);
 }

 fclose(fp);
}

// Load from file
void loadFromFile(int arr[])
{
 FILE *fp = fopen("data.txt","r");

 if(fp==NULL)
 {

  printf("No previous data found. Initializing array.\n");
  for(int i=0;i<SIZE;i++)
  {
   arr[i] = -99;
  }
  return;
 }

 for(int i=0;i<SIZE;i++)
 {
  fscanf(fp,"%d",&arr[i]);
 }

 fclose(fp);

 printf("Previous data loaded successfully.\n");
}
