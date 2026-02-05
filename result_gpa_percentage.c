#include<stdio.h>
int main(){
	int Physics,Chemistry,Math,Biology,Computer;
	// Initializing the variables of the various subjects
	float percentage;
	printf("Enter the Marks of the five subjects (Physics,Chemistry,Math,Biology,Computer):\n");
	// Asking the user for the marks of the subjects
	scanf("%d %d %d %d %d",&Physics,&Chemistry,&Math,&Biology,&Computer);
	// Storing the data in their respective variables
	percentage = (Physics+Chemistry+Math+Biology+Computer)/5.0;
	// Calculating the percentage
	printf("Percentage =%.2f\n",percentage);
	// Displaying the percentage
	if (percentage>=90)
	// Validating condition for the Grade A
	{
		printf("Grade A");
	}
	else if (percentage>=80)
	// Validating condition for the Grade B
	{
		printf("Grade B");
	}
	else if (percentage>=70)
	// Validating condition for the Grade C
	{
		printf("Grade C");
	}
	else if (percentage>=60)
	// Validating condition for the Grade D
	{
		printf("Grade D");
	}
	else if (percentage>=40)
	// Validating condition for the Grade E
	{
		printf("Grade E");
	}
	else 
	// Validating condition for the Grade F
	{
		printf("Grade F");
	}
	return 0;
}