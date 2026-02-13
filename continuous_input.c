#include<stdio.h>
#include<conio.h>
int main()
{
 	int x,b,z;
 	// Initializing multiple variables
 	char n='y';
 	// Setting the value of n to the character 'y'
	while(n=='y'){
	 	printf("Enter the numbers \n");
	 	// Asking the user for the number
	 	scanf("%d %d",&x,&b);
	 	// Saving the numbers in the variable x and b
		z=x+b;
		// Peforming the operation
		printf("%d \n",z);
		// Printing the output
		printf("Continue? \n");
		// Asking the user if they want to still continue.
		scanf(" %c",&n);
		// Saving the input to n
	}
 	return 0;
 	// Finishing the program.
}
