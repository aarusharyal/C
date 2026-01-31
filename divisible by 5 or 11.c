#include <stdio.h>
int main(){
	int a;
	printf("Enter the number:");
	//Asking The user for the numbers
	scanf("%d",&a);
	// Placing the user given value to the variable a
	if (a%5==0 && a%11==0)
	{
		printf("The number is divisible by both 5 and 11");
	}
	else if (a%5==0)
	{
		printf("The number is divisible by 5");
	}
	else if (a%11==0)
	{
		printf("The number is divisible by 11");
	}
	return 0;
}