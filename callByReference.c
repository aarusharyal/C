#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int a = 10, b = 20;
    printf("Before function call the values of a is %d and b is %d\n", a, b);

    swap(&a, &b);

    printf("After function call the values of a is %d and b is %d\n", a, b);
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
