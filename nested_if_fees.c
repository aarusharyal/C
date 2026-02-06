#include <stdio.h>
int main()
{
    int studentClass;
    // Initializing the variable in int
    float currentFees;
    // Initializing the variable in float
    printf("Enter the student's class: ");
    // Asking the user for the Student's class
    scanf("%d", &studentClass);
    // Storing the data in studentClass 
    printf("Enter the current fees: ");
    // Asking the user for the Current Fees
	scanf("%f", &currentFees);
    // Storing the data in currentFees
	if (studentClass<=10) 
	{
        if (currentFees<20000)
		{
            currentFees += 5000;
        }
		else
		{
            currentFees += 10000;
        }
    } 
	else
	{
        currentFees += 20000;
    }
    printf("final fee for class %d: %.2f\n", studentClass, currentFees);
    return 0;
}
