#include<stdio.h> 
int main(){ 
int x,y,z;
// Initializing the variables x,y and z
printf("enter the first number"); 	
//Asking the user for the first number.
scanf("%d",&x); 					
//Putting the user input in the address of variable x.
printf("enter the second number");	
//Asking the user for the second number.
scanf("%d",&y); 					
//Putting the user input in the address of variable y.
z=x+y;								
//Pefroming add operation and storing the value in the variable z.
printf("sum of two numbers is :%d",z);
//Displaying the final result on the terminal.
 return 0;

 }
