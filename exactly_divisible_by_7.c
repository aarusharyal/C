#include<stdio.h>
int main()
{
	int n,x=7;
	printf("Enter the number");
	// Asking the user for the number
	scanf("%d",&n);
	// Storing the user provided number in the variable n
	if(n%x==0)
	// Checking the condition
	{
		printf("The number is exactly divisible by the number 7 ");
	}
	else
	{
		printf("The number is not exactly divisible by the number 7 ");
	}
	return 0;
}