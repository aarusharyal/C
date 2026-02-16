#include <stdio.h>
int main() {
    int year;
	// Variable to store the year
    printf("Enter the year: ");
    // Ask user to enter a year
    scanf("%d", &year);
    if (year % 400 == 0)
    // Leap year rule 1: divisible by 400
	{
        printf("%d is a leap year.", year);
    }
    else if (year % 100 == 0)
    // Leap year rule 2: divisible by 100 but NOT by 400 → common year
	{
        printf("The year is a common year");
    }
    else if (year % 4 == 0)
    // Leap year rule 3: divisible by 4 but NOT by 100 → leap year
	{
        printf("The year is a leap year");
    }
    else
    // Otherwise, not a leap year
	{
        printf("The year is not a leap year");
    }
    return 0;
	// End of program
}
