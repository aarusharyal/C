#include <stdio.h>
// Function prototype (tells compiler that multiple() exists)
int multiple();
int main()
{
    int i, j, k;
    // Call the function and store returned value in i
    i = multiple();
    // Check if the number is negative
    if (i < 0) {
        printf("Enter a valid number");
    } 
    else {
        // Loop to print multiplication table from 1 to 10
        for (j = 1; j <= 10; j++) {
            k = j * i;
			// Calculate product
            printf("%d * %d = %d\n", i, j, k); 
			// Print result
        }
    }
    return 0; 
	// Program ends successfully
}
// Function to take input and return the number
int multiple() {
    int a;
    printf("Enter the number whose table you want: ");
    scanf("%d", &a);
	// Read and store the number from user
    return a; 
	// Return the entered number
}
