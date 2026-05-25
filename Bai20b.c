#include<stdio.h>
#include<string.h>
#include<conio.h>

#define MAX 10

/*
	Write a C Program to store student data in a structure. The data should include student ID, 
	name, course registered for, and year of joining. Write a function to display the details of 
	students enrolled in a specified academic year.	Write another function to locate and display the	
    details	of a student based on a specified student ID. To do this:
    a. Define the structure to store the student details.
    b. Declare and initialize the structure with details of 10 students.
    c. Set a loop to display a menu for the operations to be performed.
    d. Accept the menu choice and invoke appropriate functions with the structure array as parameter.
    e. In the function to display students for a year, accept the year. Set a loop to check each 
       student’s enrollment year, and display if it matches. At the end, allow the user to specify 
       another year.
    f. In the function to locate student details, accept the student ID. Set a loop to check each 
       student’s ID, and display if it matches. At the end, allow the user to specify another student ID.
*/

// a. Define the structure
typedef struct {
    int student_id;
    char name[50];
    char course[50];
    int year;
} Student;

// Function prototypes
void displayByYear(Student list[], int n);
void searchByID(Student list[], int n);
void displayStudent(Student s);

// -----------------------------------------------
// b. Declare and initialize 10 students
// -----------------------------------------------
Student students[MAX] = {
    {101, "Alice Johnson",   "Computer Science",    2021},
    {102, "Bob Martinez",    "Information Tech",    2020},
    {103, "Clara Lee",       "Software Engineering",2022},
    {104, "David Kim",       "Computer Science",    2021},
    {105, "Emma Brown",      "Cybersecurity",       2023},
    {106, "Frank Wilson",    "Data Science",        2020},
    {107, "Grace Chen",      "Information Tech",    2022},
    {108, "Henry Taylor",    "Software Engineering",2021},
    {109, "Isla Davis",      "Computer Science",    2023},
    {110, "James White",     "Data Science",        2020}
};

// -----------------------------------------------
// Helper: print one student's details
// -----------------------------------------------
void displayStudent(Student s) {
    printf("  %-6d %-22s %-25s %d\n",
           s.student_id, s.name, s.course, s.year);
}

// -----------------------------------------------
// e. Display students by enrollment year
// -----------------------------------------------
void displayByYear(Student list[], int n) {
    int year, found, i;
    char again;

    do {
        printf("\n  Enter enrollment year to search: ");
        scanf("%d", &year);

        found = 0;
        printf("\n  %-6s %-22s %-25s %s\n",
               "ID", "Name", "Course", "Year");
        printf("  %-6s %-22s %-25s %s\n",
               "------", "----------------------",
               "-------------------------", "----");

        for (i = 0; i < n; i++) {
            if (list[i].year == year) {
                displayStudent(list[i]);
                found++;
            }
        }

        if (found == 0)
            printf("  [!] No students found for year %d.\n", year);
        else
            printf("\n  Total students found: %d\n", found);

        printf("\n  Search another year? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');
}

// -----------------------------------------------
// f. Search student by ID
// -----------------------------------------------
void searchByID(Student list[], int n) {
    int id, found, i;
    char again;

    do {
        printf("\n  Enter Student ID to search: ");
        scanf("%d", &id);

        found = 0;
        for (i = 0; i < n; i++) {
            if (list[i].student_id == id) {
                printf("\n  %-6s %-22s %-25s %s\n",
                       "ID", "Name", "Course", "Year");
                printf("  %-6s %-22s %-25s %s\n",
                       "------", "----------------------",
                       "-------------------------", "----");
                displayStudent(list[i]);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("  [!] Student with ID %d not found.\n", id);

        printf("\n  Search another ID? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');
}

// -----------------------------------------------
// c & d. Main menu loop
// -----------------------------------------------
int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM        \n");
        printf("========================================\n");
        printf("  1. Display students by enrollment year\n");
        printf("  2. Search student by ID\n");
        printf("  3. Exit\n");
        printf("========================================\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayByYear(students, MAX);
                break;
            case 2:
                searchByID(students, MAX);
                break;
            case 3:
                printf("\n  Exiting program. Goodbye!\n\n");
                break;
            default:
                printf("\n  [!] Invalid choice. Please enter 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}
