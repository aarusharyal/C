#include<stdio.h>
int main(){
	int n,i,rev=0;
	printf("Enter the number: ");
	// Asking the user for a number
	scanf("%d",&n);
	// Storing the value into the variable n
	while(n!=0)
	// Checking if the value is non zero
	{
	i=n%10;
	rev= rev*10+i;
	n=n/10;
	// Reversing the digits
	}
	printf("The reverse is %d",rev);
	// Printing the output
	return 0;	
	}
