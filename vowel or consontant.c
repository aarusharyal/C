#include <stdio.h>
int main() {
    char c;                 
	// Variable to store the input character
    int lowercase, uppercase; 
	// Variables to check lowercase and uppercase vowels
    // Ask the user to enter a character
    printf("Enter the character: ");
    scanf("%c", &c);
    // Check if the character is a lowercase vowel
    lowercase = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    // Check if the character is an uppercase vowel
    uppercase = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    // If character is either lowercase or uppercase vowel
    if (lowercase || uppercase)
        printf("The character %c is a vowel", c);
    else {
        // If not a vowel, it is a consonant
        printf("The character %c is a consonant", c);
    }
    return 0; 
	// End of program
}
