#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr, n, i;
    printf("Enter number of elements\n");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    if(ptr == NULL)
    {
        printf("Allocation fails");
        exit(0);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d", ptr + i);
        }

        printf("The elements are \n");
        for(i = 0; i < n; i++)
        {
            printf("%d\t", *(ptr + i));
        }

        free(ptr);
    }
    return 0;
}
