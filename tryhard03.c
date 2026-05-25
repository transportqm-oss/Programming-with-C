#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 10

//a. Define	the	structure to store the student details.
typedef struct{
	int student_id;
	char name[50];
	char course[50];
	int year;
} Student;

//Declare void prototype to compiler know void prototype is active before call void.
void displayByYear(Student list[], int n);
void searchByID(Student list[], int n);
void displayStudent(Student s);

//b. Declare and initialize the structure with details of 10 students.
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

int main(){
	int choice;
	
	do{
		//c. Display Menu
		printf("\n========================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM        \n");
        printf("========================================\n");
        printf("  1. Display Students by enrollment year\n");
        printf("  2. Search y ID\n");
        printf("  3. Exit\n");
        printf("========================================\n");
        printf("  Enter your choice: ");
        
        //d. Accept choice and call function
        scanf("%d", &choice);
        
        switch(choice){
        	case 1:
        		displayByYear(students, MAX);
        		break;
        	case 2:
        		searchByID(students, MAX);
        		break;
        	case 3:
        		printf("\n  Goodbye!\n");
        		break;
        	default:
        		printf("\n  [!] Invalid choice.\n");
		}
	}while(choice != 3);
	
	return 0;
}

//Helper: print one student's details
void displayStudent(Student s){
	printf("  %-6d %-22s %-25s %d\n", s.student_id, s.name, s.course, s.year);
}

//e. Declare void displayByYear()
void displayByYear(Student list[], int n){
	int year, found, i;
	char again;
	
	do{
		printf("\n Enter enrollment year to search: ");
		scanf("%d", &year);
		
		found = 0;
		printf("\n  %-6s %-22s %-25s %s\n", "ID", "Name", "Course", "Year");
		printf("  %s\n", "-----------------------------------------------------------");
		
		for(i = 0; i < n; i++){
			if(list[i].year == year){
				displayStudent(list[i]);
				found++;
			}
		}
		
		if(found == 0)
			printf("  [!] No students found for year %d.\n", year);
		else
			printf("\n  Total: %d student(s) found.\n");
			
		printf("\n Search another year? (y/n): ");
		scanf(" %c", &again);
	}while(again == 'y' || again == 'Y');
}

//f. Declare void searchByID()
void searchByID(Student list[], int n){
	int id, found, i;
	char again;
	
	do{
		printf("\n Enter Student ID to search: ");
		scanf("%d", &id);
		
		found = 0;
		for(i = 0; i < n; i++){
			if(list[i].student_id = id){
				printf("\n %-6s %-22s %-25s %s\n", "ID", "Name", "Course", "Year");
				printf("  %s\n", "-----------------------------------------------------------");
				displayStudent(list[i]);
				found = 1;
				break;
			}
		}
		
		if(!found){
			printf("  [!] Student ID %d not found.\n", id);
		}
		
		printf("\n Search another ID? (y/n): ");
		scanf(" %c", &again);
	}while(again == 'y' || again == 'Y');
}
