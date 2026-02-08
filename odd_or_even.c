#include<stdio.h>
// Function declaration
void odd_or_even();
int main()
{
    // Call the function to check odd or even
    odd_or_even();
    return 0;
}
// Function definition to check whether a number is odd or even
void odd_or_even()
{
    int n;
    // Prompt user for input
    printf("Enter the number: ");
    scanf("%d",&n);
    // Check if the number is divisible by 2
    if(n % 2 == 0)
    {
        // If divisible, it's even
        printf("The number is even");   
    }
    else
    { 
        // Otherwise, it's odd
        printf("The number is odd");    
    }
}
