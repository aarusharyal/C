#include <stdio.h>
#include <string.h>
// Define structure for student
struct student
{
    int ID;             // Student ID
    char name[50];       // Student name
    int age;             // Student age
    char clas[10];        // Class name
    int symbol;          // Symbol number
    char section[10];     // Section (A/B/etc)
};
int main()
{
    int i, j;
    int n = 10; // Total number of students
    // Initialize student records
    struct student students[10] = {
        {1, "John Liver", 18, "A", 12345, "A"},
        {2, "John Chor", 19, "B", 23456, "B"},
        {3, "John Haryy", 20, "C", 34567, "A"},
        {4, "John Supper", 21, "D", 45678, "B"},
        {5, "John Shah", 22, "E", 56789, "A"},
        {6, "John Sancho", 23, "F", 67890, "B"},
        {7, "John Jaado", 24, "G", 78901, "A"},
        {8, "John Taalo", 25, "H", 89012, "B"},
        {9, "John Sins", 26, "I", 90123, "A"},
        {10, "John Cena", 27, "J", 10123, "B"}
    };
    struct student temp; // Temporary variable for swapping
    // Sort students by section
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(students[j].section, students[j + 1].section) > 0)
            {
                // Swap students
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    // Display sorted students
    printf("Sorted by section:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].ID);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Class: %s\n", students[i].clas);
        printf("Symbol Number: %d\n", students[i].symbol);
        printf("Section: %s\n\n", students[i].section);
    }
    // Ask user if they want to delete a record
    char d;
    printf("Press 'd' to delete an entry (other key to exit): ");
    scanf(" %c", &d); // Space before %c removes leftover newline
    if (d == 'd')
    {
        int index;
        printf("Enter the index to be deleted (0-%d): ", n - 1);
        scanf("%d", &index);
        // Check valid index
        if (index >= 0 && index < n)
        {
            // Shift elements left to delete
            for (i = index; i < n - 1; i++)
            {
                students[i] = students[i + 1];
            }
            n--;
			// Reduce student count
            // Print after deletion
            printf("\nAfter deletion:\n\n");
            for (i = 0; i < n; i++)
            {
                printf("Student %d:\n", i + 1);
                printf("ID: %d\n", students[i].ID);
                printf("Name: %s\n", students[i].name);
                printf("Age: %d\n", students[i].age);
                printf("Class: %s\n", students[i].clas);
                printf("Symbol Number: %d\n", students[i].symbol);
                printf("Section: %s\n\n", students[i].section);
            }
        }
        else
        {
            printf("Invalid index. No student deleted.\n");
        }
    }
    else
    {
        printf("Exiting without deletion.\n");
    }
    return 0;
}