#include <stdio.h>
int main(){
	int i,j,k;
	printf("Enter the required number: \n");
	//Asking the user for the number
	scanf("%d",&i);
	//storing the number in the variabe i
	if(i<0){
		printf("Enter a positive number");
	}
	else
	{
	for (j=1; j<=10; j++)
		// initializing a for loop
		{
			k=j*i;
			//carrying out the multiplication operation
			printf("%d*%d=%d\n",i,j,k);
			
		}
	}
	return 0;
}