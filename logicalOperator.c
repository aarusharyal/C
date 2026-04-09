#include<stdio.h>
#include<conio.h>

void main()
{
    int num1 = 50, num2 = 100;
    int AND, OR, XOR;

    AND = num1 & num2;
    OR = num1 | num2;
    XOR = num1 ^ num2;

    printf("AND => %d\n", AND);
    printf("OR => %d\n", OR);
    printf("XOR => %d\n", XOR);

    getch();
}
