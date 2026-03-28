#include<stdio.h>

float area();

int main()
{
    float A;
    A = area();
    printf("The area is %f", A);
    return 0;
}

float area()
{
    float r;
    printf("Enter radius of circle\n");
    scanf("%f", &r);
    return 3.14 * r * r;
}
