/* 
Introduction to programming
IB course: arrays
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_CHAR_LIMIT 50

// Student structure
struct student_t {
    int album;
    char name[NAME_CHAR_LIMIT];
    int course_id;
    int grade;
};

// Function prototypes
void listStudents(struct student_t *students, int count);
void addStudent(struct student_t **students, int *count);
void deleteStudent(struct student_t *students, int *count);
void changeStudent(struct student_t *students, int count);

int main() {
    struct student_t *students = NULL;
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Management Menu =====\n");
        printf("1. List all students\n");
        printf("2. Add new student\n");
        printf("3. Delete student\n");
        printf("4. Change student\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                listStudents(students, count);
                break;
            case 2:
                addStudent(&students, &count);
                break;
            case 3:
                deleteStudent(students, &count);
                break;
            case 4:
                changeStudent(students, count);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    free(students);
    return 0;
}

// List all students
void listStudents(struct student_t *students, int count) {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++) {
        printf("Album no.: %d | Name: %s | Grade: %d\n",
               students[i].album, students[i].name, students[i].grade);
    }
}

// Add a new student
void addStudent(struct student_t **students, int *count) {
    *students = realloc(*students, (*count + 1) * sizeof(struct student_t));
    if (*students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    struct student_t *newStudent = &(*students)[*count];

    printf("Enter student album no.: ");
    scanf("%d", &newStudent->album);
    getchar();

    printf("Enter student name: ");
    fgets(newStudent->name, NAME_CHAR_LIMIT, stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = '\0'; // remove newline

    printf("Enter student grade: ");
    scanf("%d", &newStudent->grade);

    (*count)++;
    printf("Student added successfully.\n");
}

// Delete a student by ID
void deleteStudent(struct student_t *students, int *count) {
    if (*count == 0) {
        printf("No students to delete.\n");
        return;
    }

    int album_tmp;
    printf("Enter album no. of student to delete: ");
    scanf("%d", &album_tmp);

    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (students[i].album == album_tmp) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Student with album no. %d not found.\n", album_tmp);
        return;
    }

    // Shift students left
    for (int i = found; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;

    printf("Student deleted successfully.\n");
}

// Change student details by ID
void changeStudent(struct student_t *students, int count) {
    if (count == 0) {
        printf("No students to change.\n");
        return;
    }

    int album_tmp;
    printf("Enter album no. of student to change: ");
    scanf("%d", &album_tmp);
    getchar();

    int found = -1;
    for (int i = 0; i < count; i++) {
        if (students[i].album == album_tmp) {
            found = i;
            break;
        }
    }

    if (found == -1) {
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
