#include <stdio.h>
int main(){ 
    double num_1,num_2,num_3,largest=0;
    printf("Enter first number : ");
    scanf("%lf",&num_1);
    printf("Enter second number : ");
    scanf("%lf",&num_2);
    printf("Enter third number : ");
    scanf("%lf",&num_3);
    if(num_1>num_2 && num_1>num_3){
        printf("%.3lf is largest.",num_1);
    }
    else if(num_2>num_1 && num_2>num_3){
        printf("%.3lf is largest.",num_2);
    }
    else if(num_3>num_1 && num_3>num_2){
        printf("%.3lf is largest.",num_3);
    }
    else
    {
        printf("All are the same = %.3lf",num_1);
    }   
    return 0;
}