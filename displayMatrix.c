#include<stdio.h>
#include<conio.h>

void display(int zix[2][2]);

void main()
{
    int matrix[2][2], i, j;
    printf("Input matrix elements\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    display(matrix);
    getch();
}

void display(int zix[2][2])
{
    int i, j;
    printf("The matrix is\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf(" %d", zix[i][j]);
        }
        printf("\n");
    }
}
