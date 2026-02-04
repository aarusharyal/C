#include<stdio.h>
int main(){
	int cp,sp,p,l;
	printf("Enter the cost price:");
	// Asking the user for the Cost price
	scanf ("%d",&cp);
	// Storing the number in the variable cp
	printf("Enter the selling price:");
	// Asking the user for the Selling price
	scanf("%d",&sp);
	// Storing the number in the variable sp
	if (sp>cp)
	// Condition For profit
	{
		printf("It is profit\n");
		p=sp-cp;
		printf("The profit is of %d",p);
	}
	else if (cp>sp)
	// Condition For Loss
	{
		printf("It is Loss\n");
		l=cp-sp;
		printf("The loss is of %d",l);
	}
	return 0;
}
