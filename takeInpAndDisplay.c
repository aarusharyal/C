#include<stdio.h>
int main()
{
	char name[20];
	int rollno;
	long int contactno;
	printf( "Enter your name\n");
	scanf ("%s",&name);
	printf("Enter your roll no\n");
	scanf("%d", &rollno);
	printf("Enter contact number\n");
	scanf("%d",&contactno);
	printf("Name is %s \n",name);
	printf("Rollno is %d\n",rollno);
	printf("Contact number is %d",contactno);
 	return 0;
}