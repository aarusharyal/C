#include <stdio.h.>
#include <math.h>
int main()
{
	int n;
	// Declaring the variable
	printf("Enter the pyramid size: ");
	// Getting the data from the user
	scanf("%d",&n);
	// Storing the data on the variable n
	int z=1;
	int i,j,k;
	for(i=1;i<=n;i++)
	// Initialziing the first for loop
	{
		for(j=n-1;j>=i;j--)
		// Initializing the second for loop
		{
			printf(" ");
			// Printing The blank spaces
		}
		for(k=z;k>=1;k--)
		// Initializing the other for loop
		{
			printf("%d",abs(k-i)+1);
		}
		z+=2;
		printf("\n");
		// Adding a new line after the first step
	}
	return 0;
	// Finishing the program
}