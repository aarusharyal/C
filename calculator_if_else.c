#include <stdio.h>
int main() {
    int ip, a, b, result;
	// Variables for operation choice, inputs, and result
    printf("Choose operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Divide\n");
    printf("4. Multiply\n");
    printf("Enter your choice (1-4): ");
    // Display menu for user to choose an operation
    scanf("%d", &ip);
	// Store user choice in 'ip'
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    // Ask for two numbers to perform the chosen operation
    // Perform operation based on user choice
    if (ip == 1) {
        // Addition
        result = a + b;
        printf("The sum is %d\n", result);
    }
    else if (ip == 2) {
        // Subtraction
        result = a - b;
        printf("The difference is %d\n", result);
    }
    else if (ip == 3) {
        // Division (with zero check)
        if (b != 0) {
            result = a / b;
            printf("The quotient is %d\n", result);
        } else {
            printf("Error: Division by zero is not allowed.\n");
        }
    }
    else if (ip == 4) {
        // Multiplication
        result = a * b;
        printf("The product is %d\n", result);
    }
    else {
        // Invalid choice handling
        printf("Invalid choice.\n");
    }
    return 0;
	// End of program
}
