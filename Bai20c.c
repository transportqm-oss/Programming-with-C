#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 100 // maximum limits

//a. define structure
typedef struct{
	int student_id;
	char name[50];
	char course[50];
	int year;
} Student;

//b. decalre prototype
void inputStudent(Student list[], int *n);
void displayByYear(Student list[], int n);
void searchByID(Student list[], int n);
void displayStudent(Student s);
void displayHeader();

//c. declare array global
Student students[MAX];
int total = 0; // so sinh vien hien tai do use nhap

int main(){
	int choice;
	
	do{
		printf("\n==========================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM         \n");
        printf("==========================================\n");
        printf("  Total students: %d\n", total);
        printf("------------------------------------------\n");
        printf("  1. Add Students\n");
        printf("  2. Display Students by enrollment year\n");
        printf("  3. Search Student by ID\n");
        printf("  4. Exit\n");
        printf("==========================================\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1:
        		inputStudent(students, &total);
        		break;
        	case 2:
        		displayByYear(students, total);
        		break;
        	case 3:
        		searchByID(students, total);
        		break;
        	case 4:
        		printf("\n  Goodbye!\n\n");
        		break;
        	default:
        		printf("\n  [!] Invalid choice. Enter 01 to 04.\n");
		}
	}while(choice != 4);
	
	return 0;
}

//helper: in header bang
void displayHeader(){
	printf("\n  %-6s %-22s %-25s %s\n", "ID", "Name", "Course", "Year");
	printf("  %-6s %-22s %-25s %s\n",
           "------", "----------------------",
           "-------------------------", "----");
}

//helper: print 01 student
void displayStudent(Student s){
	printf("  %-6d %-22s %-25s %d\n", s.student_id, s.name, s.course, s.year);
}

//declare function: call inputStudent
void inputStudent(Student list[], int *n){
	int count, i, j, duplicate;
	
	printf("\n  How many students do you want to enter? ");
	printf("\n  (Max %d): ", MAX);
	scanf("%d", &count);
	
	//check validate
	if(count <= 0 || count > MAX){
		printf("\n  [!] Invalid number. Must be between 1 and %d.\n", MAX);
		
		return;
	}
	
	for(i = 0; i < count; i++){
		printf("\n  ----------- Student [%d] -----------\n", i + 1);
		
		//input ID - kiem tra xem co trung ID hay khong
		int duplicate;
		do{
			duplicate = 0;
			printf("  Student ID: ");
			scanf("%d", &list[i].student_id);
			
			//kiem tra ID co bi trung hay ko
			int j;
			for(j = 0; j < i; j++){
				if(list[j].student_id == list[i].student_id){
					printf("  [!] ID %d already exists. Please enter a different ID.\n", list[i].student_id);
					duplicate = 1;
					break;
				}
			}
		}while(duplicate);
		
		printf("  Name       : ");
        scanf(" %[^\n]", list[i].name);
		
		printf("  Course     : ");
        scanf(" %[^\n]", list[i].course);
		
		//input year and check validate
		do {
            printf("  Year       : ");
            scanf("%d", &list[i].year);
            if (list[i].year < 1900 || list[i].year > 2100)
                printf("  [!] Invalid year. Please enter again.\n");
        } while (list[i].year < 1900 || list[i].year > 2100);
	}
	
	*n = count; //cap nhap tong so sinh vien
	printf("\n  [|||] %d student(s) added successfully!\n", count);
}

//declare function: call displayByYear
void displayByYear(Student list[], int n) {
    // kiem tra danh sach
    if (n == 0) {
        printf("\n  [!] No student data. Please add students first.\n");
        return;
    }

    int year, found, i;
    char again;

    do {
        printf("\n  Enter enrollment year to search: ");
        scanf("%d", &year);

        found = 0;
        displayHeader();

        for (i = 0; i < n; i++) {
            if (list[i].year == year) {
                displayStudent(list[i]);
                found++;
            }
        }

        if (found == 0)
            printf("  [!] No students found for year %d.\n", year);
        else
            printf("\n  Total: %d student(s) found.\n", found);

        printf("\n  Search another year? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');
}

//declare function:
void searchByID(Student list[], int n) {
    // Ki?m tra danh sách tr?ng
    if (n == 0) {
        printf("\n  [!] No student data. Please add students first.\n");
        return;
    }

    int id, found, i;
    char again;

    do {
        printf("\n  Enter Student ID to search: ");
        scanf("%d", &id);

        found = 0;
        for (i = 0; i < n; i++) {
            if (list[i].student_id == id) {
                displayHeader();
                displayStudent(list[i]);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("  [!] Student ID %d not found.\n", id);

        printf("\n  Search another ID? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');
}
