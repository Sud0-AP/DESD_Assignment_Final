//program to calculate the income tax based on different tax brackets

#include <stdio.h>

int main()
{
	//initializing variables
	float total_income, taxable_income, investment, tax;
	int age;
	char gender;

	//Taking user details
	printf("Enter Age: ");
	scanf("%d", &age);

	printf("Enter Gender(M/F): ");
	scanf(" %c", &gender);

	printf("Enter income: ");
        scanf("%f", &total_income);

	printf("Enter Total investments: ");
        scanf("%f", &investment);

	//calculating taxable income
	taxable_income = total_income - investment;

	if (age >= 60) {
		//senior citizen
		if(taxable_income < 300000)
			tax = 0;
		else if (taxable_income > 300000 && taxable_income <= 500000)
			tax = (taxable_income - 300000) * 0.05;
		else if (taxable_income > 500000 && taxable_income<=1000000)
			tax = 10000 + ((taxable_income-500000) * 0.2);
		else
			tax = 110000 + ((taxable_income-1000000) * 0.3); 

	}else{
		//normal citizen
		if(taxable_income < 250000)
                        tax = 0;
                else if (taxable_income > 250000 && taxable_income <= 500000)
                        tax = (taxable_income - 250000) * 0.05;
                else if (taxable_income > 500000 && taxable_income<=1000000)
                        tax = 12500 + ((taxable_income-500000) * 0.2);
                else
                        tax = 112500 + ((taxable_income-1000000) * 0.3);
	}

	printf("Total Tax to be paid = %2f\n", tax);

	return 0;
}




	


		
