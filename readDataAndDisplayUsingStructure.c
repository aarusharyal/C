#include<stdio.h>

struct student
{
    char name[20];
    int rollno;
    float marks[6];
    float average;
};

int main()
{
    struct student s;
    int i;
    float sum = 0;

    printf("Enter name of student\n");
    scanf("%s", s.name);

    printf("Enter roll no of student\n");
    scanf("%d", &s.rollno);

    printf("Enter marks of student in six subjects\n");
    for(i = 0; i < 6; i++)
    {
        printf("Subject %d:\t", i + 1);
        scanf("%f", &s.marks[i]);
        sum = sum + s.marks[i];
    }

    s.average = sum / 6;

    printf("\n------ Student Details ------\n");
    printf("Name: %s\n", s.name);
    printf("Roll no: %d\n", s.rollno);
    printf("Average marks: %f\n", s.average);

    return 0;
}
