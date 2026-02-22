#include<stdio.h>
int main()
{
	int n,x;
	// Declaring the variables
	printf("Enter the number");
	// Asking the user for the number
	scanf("%d",&n);
	// Storing the value in variable n
	printf("Enter the number");
	// Asking the user for the number
	scanf("%d",&x);
	// Storing the value in variable x
	if(x==0)
	// Checking if the provided number is 0
	{
		printf("The number is invalid");
	}
	else if(n%x==0)
	// Checking the condition
	{
		printf("The number is exactly divisible by the second number");
	}
	else
	{
		printf("The number is not exactly divisible by the second number");
	}
	return 0;

}
