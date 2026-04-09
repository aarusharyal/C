#include <stdio.h>

int sum(int a, int b);

int main()
{
    int a, b, r;
    printf("Enter two numbers\n");
    scanf("%d%d", &a, &b);

    r = sum(a, b);
    printf("Sum is %d", r);

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}
