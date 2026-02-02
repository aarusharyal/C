// Code for checking if the provided number is palindrome or not
#include<stdio.h>
int main(){
	int n,m,i=0,temp;
	printf("Enter the number:");
	// Asking the user for the number
	scanf("%d",&n);
	// Storing the value in variable n
	temp=n;
	// Storing the initial value in a temporary variable "temp"
	while(n!=0)
	// Validating that the provided number is not 0
	{
		m=n%10;
		i=i*10+m;
		n=n/10;
	}
	if (i==temp)
	// Validating the condition
	{
		printf("It is a palindrome number");
	}
	else {
		printf("It is not a palindrome number.");
	}
	return 0;
}