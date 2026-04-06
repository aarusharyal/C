#include<stdio.h>

int getlength(char[]);

int main()
{
    char s[100];
    printf("Enter a string: ");
    gets(s);   // unsafe, but used here for simplicity
    printf("Length of string is %d\n", getlength(s));
    return 0;
}

int getlength(char str[])
{
    int i, length = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
