#include<stdio.h>
int main()
{
	int n;
	// Initializing the variable n
	printf("Enter a number");
	// Asking the user for a number
	scanf("%d",&n);
	// Storing the provided number in the variable n
	if(n<0)
	// Checking if the number is negative
	{
		printf("The number is negative");
	}
	else if(n=0)
	// Checking if the number is positive
	{
		printf("The number is zero");
	}
	else
	// If both conditions are unfulfilled then the number must be positive
	{
		printf("The number is positive");
	}
	return 0;
}