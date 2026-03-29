#include <stdio.h>

extern int num;

void show()
{
    printf("%d", num);
}

int main()
{
    show();
    return 0;
}

int num = 300;
