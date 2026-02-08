#include<stdio.h>
// Function declaration
void calc();
int main()
{
    // Call the calculator function
    calc();
    return 0;
}
// Function definition for calculator
void calc()
{
    printf("CALCULATOR\n\n");
    int a, b, result; // Variables to store numbers and result
    char c;           // Variable to store operator
    // Prompt user for two numbers
    printf("Enter the numbers:\n");
    // Note: Using comma in scanf requires input like "5,6"
    scanf("%d,%d", &a, &b);
    // Prompt user for operation
    printf("Enter the operation:\n");
    scanf(" %c", &c); // Space before %c handles leftover newline
    // Perform operation based on user input
    switch (c)
    {
    case '+':
        result = a + b;
        printf("The sum is %d\n\n", result);
        break;
    case '-':
        result = a - b;
        printf("The difference is %d\n\n", result);
        break;
    case '*':
        result = a * b;
        printf("The multiple is %d\n\n", result);
        break;
    case '/':
        result = a / b; // Integer division
        printf("The quotient is %d\n\n", result);
        break;
    default:
        // If user enters an invalid operator
        printf("INVALID\n\n");
    }
}
