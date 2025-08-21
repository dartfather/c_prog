#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

// List all students
void list_students(struct student_t *students, int count)
{
    if (count == 0)
    {
        printf("No students available.\n");
        return;
    }
    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Album no.: %d | Name: %s | Grade: %d\n",
               students[i].album, students[i].name, students[i].grade);
    }
}

// Add a new student
/* We are using double pointer to modify the students array*/
void add_student(struct student_t **students, int *count)
{
    *students = realloc(*students, (*count + 1) * sizeof(struct student_t));
    if (*students == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    struct student_t *new_student = &(*students)[*count];

    printf("Enter student album no.: ");
    scanf("%d", &new_student->album);
    getchar();

    printf("Enter student name: ");
    fgets(new_student->name, NAME_CHAR_LIMIT, stdin);
    new_student->name[strcspn(new_student->name, "\n")] = '\0'; // remove newline

    printf("Enter student grade: ");
    scanf("%d", &new_student->grade);

    (*count)++;
    printf("Student added successfully.\n");
}

// Delete a student by ID
void delete_student(struct student_t *students, int *count)
{
    if (*count == 0)
    {
        printf("No students to delete.\n");
        return;
    }

    int album_tmp;
    printf("Enter album no. of student to delete: ");
    scanf("%d", &album_tmp);

    int found = -1;
    for (int i = 0; i < *count; i++)
    {
        if (students[i].album == album_tmp)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Student with album no. %d not found.\n", album_tmp);
        return;
    }

    // Shift students left
    for (int i = found; i < *count - 1; i++)
    {
        students[i] = students[i + 1];
    }
    (*count)--;

    printf("Student deleted successfully.\n");
}

// Change student details by ID
void change_student(struct student_t *students, int count)
{
    if (count == 0)
    {
        printf("No students to change.\n");
        return;
    }

    int album_tmp;
    printf("Enter album no. of student to change: ");
    scanf("%d", &album_tmp);
    getchar();

    int found = -1;
    for (int i = 0; i < count; i++)
    {
        if (students[i].album == album_tmp)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Student with album no. %d not found.\n", album_tmp);
        return;
    }

    printf("Enter new name: ");
    fgets(students[found].name, NAME_CHAR_LIMIT, stdin);
    students[found].name[strcspn(students[found].name, "\n")] = '\0';

    printf("Enter new grade: ");
    scanf("%d", &students[found].grade);

    printf("Student details updated successfully.\n");
}
