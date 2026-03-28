#include<stdio.h>

void area(float r);

int main()
{
    float r;
    printf("Enter radius of circle: ");
    scanf("%f", &r);
    area(r);
    return 0;
}

void area(float r)
{
    float A;
    A = 3.14 * r * r;
    printf("Area is %f", A);
}
