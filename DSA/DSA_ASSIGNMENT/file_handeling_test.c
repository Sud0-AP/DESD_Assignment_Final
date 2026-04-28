#include <stdio.h>
#include <errno.h>

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

	int arr[] = { 10, 20, 30, 40, 50};
	int arr[SIZE];
	int count;
	for(i = 0; i < SIZE; i++)
	fprintf("%d \n",arr[i]);
	while((fscanf(fptr," %d", &arr[count++]))!= EOF){}
	
	

	
}

