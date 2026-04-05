#include <stdio.h>

int main()
{
    auto int i = 10;
    printf("%d\n", i);

    {
        auto int i = 20;
        printf("%d\n", i);
    }

    printf("%d\n", i);
    return 0;
}
