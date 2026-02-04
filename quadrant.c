#include <stdio.h>
int main(){
	int x,y;
	printf("Enter the number:");
	// Asking the user for two Number (x,y)
	scanf("%d,%d",&x,&y);
	// Storing the numbers in the variables x and y
	if (x>0 && y>0)
	// Condition for first quadrant
	{
		printf("The point (%d,%d) are in first quadrant",x,y);
	}
	else if (x<0 && y>0)
	// Condition for second quadrant
	{
		printf("The point (%d,%d) are in second quadrant",x,y);
	}
	else if (x<0 && y<0)
	// Condition for third quadrant
	{
		printf("The point (%d,%d) are in third quadrant",x,y);
	}
	else if (x>0 && y<0)
	// Condition for fourth quadrant
	{
		printf("The point (%d,%d) are in fourth quadrant",x,y);
	}
	else if(x==0 &&y==0)
	// Condition for origin
	{
		printf("The point (%d,%d) are in origin",x,y);
	}
	return 0;
}