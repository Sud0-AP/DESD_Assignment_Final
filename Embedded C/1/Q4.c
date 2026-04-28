// Check if input variable is a vowel

#include <stdio.h>

int main()
{
	char input_char; // input variable
	
	printf("Input an alphabet: \n");
	scanf("%c", &input_char); // taking input

	if (input_char == 'a' || input_char == 'A' || input_char == 'e' || input_char == 'E' || input_char == 'i' || input_char == 'I' || input_char == 'o' || input_char == 'O' || input_char == 'u' || input_char == 'U'){ // checking if input is a vowel
	printf("Input is a vowel\n");
	}else{
		printf("Input is a consonant \n");
	}

	return 0;
}

/* Using Array and for loop

int main()
{
        char input_char; // input variable
        char vowels[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u','U'}; // defining vowels

        printf("Input an alphabet: \n");
        scanf("%c", &input_char); // taking input


        int i;

        // For loop to check each vowel
        for(i=0; i<10; i++){
                if (input_char == vowels[i]){
                        printf("Input is a vowel \n");
                        return 0;
                }
        }

        printf("Input is a consonant \n");

        return 0;
}

*/
