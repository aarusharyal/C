#include <stdio.h>
int main() {
    char c;// Variable to store the input character
    printf("Enter the character: ");
    // Ask user to enter a character
    scanf("%c", &c);
	// Read the character from user
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    // Check if the character is an alphabet (lowercase or uppercase)
	{
        printf("The character is an alphabet");
    } 
    else 
        // If character is not in alphabet range
	{
        printf("The character is not an alphabet");
    }
    return 0; 
	// End of program
}
