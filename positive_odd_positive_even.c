#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number");
	//asking the user for a number
	scanf("%d",&n);
	//storing the number in the variable n
	if(n<0)
	//checking if the number is negative
	{
		printf("The number is non positive");
	}
	else if(n>0 && n%2==0)
	//condition for when number is positive and even
	{
		printf("The number is positive even");
	}
	else if(n>0 && n%2 != 0)
	//condition for when number is positive and odd
	{
		printf("The number is positive odd");
	}
	return 0;
}