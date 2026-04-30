#include <stdio.h>
#include <errno.h>

#define SIZE 5

int main(){
	FILE *fptr = fopen("test.txt", "r+");
	if (fptr == NULL){
		perror("fopen:");
		printf("Creating the file!!\n");
		fptr = fopen("test.txt", "w");
		if(fptr == NULL){
			perror("fopen:");
		}
		fclose(fptr);
		fptr = fopen("test.txt", "r+");
	}

	int arr1[] = { 10, 20, 30, 40, 50};
	int arr2[SIZE];
	int count;
	for(int i = 0; i < SIZE; i++)
		fprintf("%d ",arr1[i]);
	while((fscanf(fptr," %d", &arr2[count++]))!= EOF){
		
	}
	
	

	
}

