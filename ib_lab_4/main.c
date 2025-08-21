/* 
Introduction to programming
IB course: arrays
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

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
                list_students(students, count);
                break;
            case 2:
                add_student(&students, &count);
                break;
            case 3:
                delete_student(students, &count);
                break;
            case 4:
                change_student(students, count);
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