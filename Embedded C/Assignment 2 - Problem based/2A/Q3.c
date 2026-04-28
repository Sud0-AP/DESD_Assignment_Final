// Calculate grade of student based on marks in N subjects
//
#include <stdio.h>

int main()
{
	float total_marks, avg_percentage, temp; //float variables for marks and percentage
	int n_sub, i; 

	printf("Enter number of subjects: ");
	scanf("%d",&n_sub); // Asking for number of subjects

	for(i=0 ; i<n_sub ; i++)
	{
		printf("\nEnter marks for subject %d (out of 100) : ", i+1);
		scanf("%f", &temp); // Asking for each subject marks using loop
		total_marks += temp;
	}

	avg_percentage = (total_marks / n_sub); // calculating the percentage

	printf("\nTotal marks earned: in %d subjects : %2f", n_sub, total_marks);
	printf("\nTotal Percentage: %2f", avg_percentage);

	// printing grades based on percentage
	
	if(avg_percentage <40){ 
	printf("\nGrade: F (fail)\n");
	}else if(avg_percentage <60){
		printf("\nGrade: C\n");
	}else if(avg_percentage <80){
                printf("\nGrade: B\n");
        }else if(avg_percentage <90){
                printf("\nGrade: A\n");
        }else {
                printf("\nGrade: A+\n");
        }

	return 0;
}
