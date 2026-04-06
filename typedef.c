#include <stdio.h>

typedef struct {
    char name[50];
    int rollno;
    float marks;
} Student;

int main() {
    Student s1;

    printf("Enter name, roll number, and marks: ");
    scanf("%s %d %f", s1.name, &s1.rollno, &s1.marks);

    printf("\nStudent Details:\n");
    printf("ROLLNO: %d\n", s1.rollno);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}
