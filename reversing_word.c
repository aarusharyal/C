#include <stdio.h>
#include <string.h>
int main()  
{
    char word[10000];   // Array to store the input word
    // Ask user to enter a word
    printf("Enter a word: ");
    scanf("%s", word);   // Read the word (no spaces)
    // Print message before reversing
    printf("Reversed alphabet: ");
    // Loop from last character to first
    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        printf("%c", word[i]);
		// Print each character in reverse order
    }
    printf("\n");
	 // Move to next line
    return 0;
	// End of program
}
