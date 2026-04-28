//Create an employee structure with the following members empid, employee name, salary, year of joining.
//Accept the data for certain no. of employees and find their total average, max , min salary.
//also find out the employees with maximum, minimum service, use a function to find service for each employee element in the array.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee{
	int emp_id;
	char emp_name[30];
	long emp_salary;
	int emp_yoj;
};

#define YEAR 2026

void take_employee_data(struct employee *, int);
void print_employee_data(struct employee *, int);
long avg_salary(struct employee *, int);
long max_salary(struct employee *, int);
long min_salary(struct employee *, int);
int cal_service(struct employee *, int);
int max_service(struct employee *, int);
int min_service(struct employee *, int);

int main(){
	struct employee *emp_list;
	int num_emp;
	printf("Enter number of employees: \n");
	scanf("%d", &num_emp);

	emp_list = (struct employee *)malloc(num_emp * (sizeof(struct employee)));

	take_employee_data(emp_list, num_emp);

	print_employee_data(emp_list, num_emp);

	avg_salary(emp_list, num_emp);
	max_salary(emp_list, num_emp);
	min_salary(emp_list, num_emp);
	max_service(emp_list, num_emp);
	min_service(emp_list, num_emp);
}

void take_employee_data(struct employee *emp_list, int num_emp){
	for(int i = 0; i<num_emp; i++){
		printf("Enter employee %d ID: ", i+1);
		scanf("%d", &(emp_list + i)->emp_id);

		getchar();
		printf("Enter employee %d name: ", i+1);
		//scanf(" %[^\n]", (emp_list + i)->emp_name);
		fgets((emp_list + i)->emp_name, sizeof((emp_list + i)->emp_name), stdin);
		
		printf("Enter employee %d salary: ", i+1);
		scanf("%ld",  &(emp_list + i)->emp_salary);
		
		printf("Enter employee %d year of joining: ", i+1);
		scanf("%d",  &(emp_list + i)->emp_yoj);
		printf("\n");

	}
}


void print_employee_data(struct employee *emp_list, int num_emp){
	for(int i = 0; i<num_emp; i++){
		printf("Employee %d ID: %d\n", i+1, (emp_list + i)->emp_id);
		printf("Employee %d Name: %s", i+1, (emp_list + i)->emp_name);	
		printf("Employee %d Salary: %ld\n", i+1, (emp_list + i)->emp_salary);
		printf("Employee %d Year of Joining: %d\n", i+1, (emp_list + i)->emp_yoj);
	}
}


long avg_salary(struct employee *emp_list, int num_emp){
	long sum=0;
	for(int i = 0; i<num_emp; i++){
		sum += (emp_list+i)->emp_salary;
	}
	printf("\nAverage Salary: %ld \n", (sum/num_emp));
	return sum/num_emp;
}

long max_salary(struct employee *emp_list, int num_emp){
	long max=(emp_list+0)->emp_salary;
	for(int i = 0; i<num_emp; i++){
		if((emp_list+i)->emp_salary > max){
			max = (emp_list+i)->emp_salary; 
		}
	}	
	printf("\nMaximum Salary: %ld \n", max);
	return max;
}
long min_salary(struct employee *emp_list, int num_emp){
	long min=(emp_list+0)->emp_salary;
	for(int i = 0; i<num_emp; i++){
		if((emp_list+i)->emp_salary < min){
			min = (emp_list+i)->emp_salary; 
		}
	}
	printf("\nMinimum Salary: %ld \n", min);
	return min;
}
int cal_service(struct employee *emp_list, int index){
	return YEAR - ((emp_list+index)->emp_yoj);
}

int max_service(struct employee *emp_list, int num_emp){
	int max = cal_service(emp_list, 0);
	for(int i = 0; i<num_emp; i++){
		if(cal_service(emp_list, i) > max){
			max = cal_service(emp_list, i); 
		}
	}
	printf("\nMaximum Service: %d \n", max);
	return max;
}

int min_service(struct employee *emp_list, int num_emp){
	int min = cal_service(emp_list, 0);
	for(int i = 0; i<num_emp; i++){
		if(cal_service(emp_list, i) < min){
			min = cal_service(emp_list, i); 
		}
	}
	printf("\nMinimum Service: %d \n", min);
	return min;
}

