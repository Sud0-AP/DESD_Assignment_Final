//Program to test function pointers
//PRN: 260240130005 and 260240130032

#include <stdio.h>

int add(int x, int y){
	return x+y;
}

int mul(int x, int y){
	return x*y;
}

int sub(int x, int y){
	return x-y;
}

typedef int (*pftype)(int, int);

int main(){
	int num1, num2, choice;

	printf("What operation do you wish to perform? \n(Enter 1) Addition \n(Enter 2) Subtraction \n(Press 3) Multiplication\nEnter Choice: ");
	scanf("%d", &choice);

	if (choice == 1 || choice == 2 || choice == 3){
		printf("Enter Two numbers: ");
		scanf("%d %d", &num1, &num2);

		pftype menu[] = {add, sub ,mul};
		//pftype (*menu[])(int, int) = {add, sub ,mul};
		
		switch(choice){
			case 1:
				printf("Addition of the two given numbers = %d\n",menu[0](num1, num2));
				break;
			case 2:
				printf("Subtraction of the two given numbers = %d\n", menu[1](num1, num2));
				break;
			case 3:
				printf("Multiplication of the two given numbers = %d\n", menu[2](num1, num2));

		}
	}

	return 0;
}

