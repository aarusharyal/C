#include<stdio.h>
void area_of_rect();
// Declaring the function
int main()
{
	area_of_rect();
	// Calling the function
	return 0;
}
void area_of_rect()
// Defining the function
{
	printf("AREA OF RECTANGLE");
	int area,l,b;
	printf("Enter the length and breadth:\n");
	scanf("%d %d",&l,&b);
	area = l*b;
	printf("The area of %d and %d is: %d\n\n",l,b,area);
}