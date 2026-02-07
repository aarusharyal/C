#include <stdio.h>
int main(){
	char c;
	// Initializing the variable c
	printf("Enter the character: ");
	// Asking the user for the character
	scanf("%c",&c);
	// Storing the character in the variable c
	if (c>='A' && c<='Z')
	// Checking if the character is a uppercase letter
	{
		printf("The character %c is a uppercase letter.");
	}
	else if (c>= 'a' && c<= 'z')
	// Checking if the character is a lowercase letter
	{
		printf("The character %c is a lowercase letter. ");
	} 
	else if (c>='0' && c<='9')
	// Checking if the character is a number 
	{
		printf("The character %c is a number ");
	}
	else
	{
		printf("The character is not a alphabet or a number");
	}
	return 0;
	// Ending the program
}