#include<stdio.h>

int main()
{
    int a, b;
    char ch;

    printf("Enter two numbers\n");
    scanf("%d%d", &a, &b);

    printf("Enter any character\n");
    scanf(" %c", &ch);  // notice the space before %c to handle newline

    switch(ch)
    {
        case '+':
            printf("Addition is %d", a + b);
            break;
        case '-':
            printf("Subtraction is %d", a - b);
            break;
        case '*':
            printf("Multiplication is %d", a * b);
            break;
        case '%':
            printf("Modulo division is %d", a % b);
            break;
        default:
            printf("Wrong Choice");
    }

    return 0;
}
