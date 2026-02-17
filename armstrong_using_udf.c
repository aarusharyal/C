#include <stdio.h>
#include <math.h>
int countDigits(int num)
// Function to calculate the number of digits in a number
{
    int count = 0;          
	// Variable to store digit count
    while (num != 0)
    // Loop until number becomes 0
	{
        num /= 10;           // Remove last digit
        count++;              // Increase digit count
    }
    return count;
	// Return total digits
}
int isArmstrong(int num) 
// Function to check if a number is an Armstrong number
{
    int originalNum = num;        // Store original number for comparison
    int numDigits = countDigits(num); // Get total number of digits
    int sum = 0;                   // Store sum of powers of digits
    while (num != 0)
    // Extract each digit and calculate power
	{
        int digit = num % 10;              // Get last digit
        sum += pow(digit, numDigits);      // Add digit^number_of_digits
        num /= 10;                          // Remove last digit
    }
    return sum == originalNum;
    // If sum equals original number → Armstrong number
}
int main() {
    int number; 
	// Variable to store input number
    printf("Enter a number: ");
    scanf("%d", &number);
    // Ask user for input
    if (isArmstrong(number))
	// Check and print result
	{
        printf("%d is an Armstrong number.\n", number);
    } 
    else {
        printf("%d is not an Armstrong number.\n", number);
    }
    return 0;
	// End of program
}
