#include<stdio.h>
#include<conio.h>
#include<string.h>

/*
	#include / #define
        |
	typedef struct Date     -> month, day, year
        |
	typedef struct Employee -> id, name, salary, Date joined
        |
	prototypes
        |
	global array + total
        |
	main() -> menu loop
        |
	inputEmployees()   -> input info employee
        |
	increaseSalary()   -> increase the salaries by rule
		|
		|	Salary Range <= 2000 ~ 15%
		|	Salary Range > 2000 and <= 5000 ~ 10%
		|	Salary Range > 5000 ~ no increase
        |
	display10Years()   -> display all employee complete 10 years with the companay
        |
	displayHeader()    -> helper print Header
        |
	displayEmployee()  -> helper display 01 employee
*/

#define MAX 100

//a. Define structure: DATE (nested)
typedef struct {
	int month;
	int day;
	int year;
} Date;

//b. Define structure: EMPLOYEE
typedef struct {
	int emp_id;
	char name[50];
	float salary;
	Date joined;	// nested structure
} Employee;

//c. Declare prototype
void inputEmployees(Employee list[], int *n);
void increaseSalary(Employee list[], int n);
void display10Years(Employee list[], int n);
void displayHeader();
void displayEmployee(Employee e);

//d. Declare Global array + total
Employee employees[MAX];
int total = 0;

int main() {
	int choice;

	do {
		printf("\n==========================================\n");
		printf("       EMPLOYEE MANAGEMENT SYSTEM        \n");
		printf("==========================================\n");
		printf("  Total employees: %d\n", total);
		printf("------------------------------------------\n");
		printf("  1. Add employees\n");
		printf("  2. Increase salaries\n");
		printf("  3. Display employees with 10+ years\n");
		printf("  4. Exit\n");
		printf("==========================================\n");
		printf("  Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				inputEmployees(employees, &total);
				break;
			case 2:
				increaseSalary(employees, total);
				break;
			case 3:
				display10Years(employees, total);
				break;
			case 4:
				printf("\n  Goodbye!\n\n");
				break;
			default:
				printf("  [!] Invalid choice. Enter 01 to 04.\n");
		}
	} while(choice != 4);

	return 0;
}

//Helper: display Header
void displayHeader() {
	printf("\n  %-6s %-20s %-10s %-15s\n", "ID", "Name", "Salary", "Date Joined");
	printf("  %-6s %-20s %-10s %-15s\n",
	       "------", "--------------------",
	       "----------", "---------------");
}

//Helper: display 01 employee
void displayEmployee(Employee e) {
	printf("  %-6d %-20s %-10.2f %02d/%02d/%04d\n",
	       e.emp_id,
	       e.name,
	       e.salary,
	       e.joined.month,
	       e.joined.day,
	       e.joined.year
	      );
}

//e. Declare function: inputEmployees()
void inputEmployees(Employee list[], int *n) {
	int count;
	int i, j, duplicate;

	printf("\n  How many employees to enter? ");
	printf("Max %d: ", MAX);
	scanf("%d", &count);

	if(count <= 0 || count > MAX) {
		printf("\n  [!] Invalid. Must be betweeb 01 and %d.\n", MAX);
		return;
	}

	for(i = 0; i < count; i++) {
		printf("\n  -------- Employee [%d] --------\n", i + 1);

		//input ID + check validate
		do {
			duplicate = 0;
			printf("  Employee ID: ");
			scanf("%d", &list[i].emp_id);

			for(j = 0; j < i; j++) {
				if(list[j].emp_id == list[i].emp_id) {
					printf("  [!] ID %d already exists. Enter another.\n", list[i].emp_id);

					duplicate = 1;
					break;
				}
			}
		} while(duplicate);

		//input NAME
		printf("  Name        : ");
		scanf(" %[^\n]", list[i].name);

		//input SALARY + check validate
		do {
			printf("  Salary      : ");
			scanf("%f", &list[i].salary);
			if(list[i].salary < 0) {
				printf("  [!] Salary cannot be negative.\n");
			}
		} while(list[i].salary < 0);

		//input DATE of joining + check validate
		do {
			printf("  Join Month  : ");
			scanf("%d", &list[i].joined.month);
			if(list[i].joined.month < 1 || list[i].joined.month > 12) {
				printf("  [!] Month must be between 01 and 12.\n");
			}
		} while(list[i].joined.month < 1 || list[i].joined.month > 12);

		do {
			printf("  Join Day    : ");
			scanf("%d", &list[i].joined.day);
			if(list[i].joined.day < 1 || list[i].joined.day > 31) {
				printf("  [!] Day must be between 01 and 31.\n");
			}
		} while(list[i].joined.day < 1 || list[i].joined.day > 31);

		do {
			printf("  Join Year   : ");
			scanf("%d", &list[i].joined.year);
			if(list[i].joined.year < 1900 || list[i].joined.year > 2100) {
				printf("  [!] Invalid year.\n");
			}
		} while(list[i].joined.year < 1900 || list[i].joined.year > 2100);
	}

	*n = count;
	printf("\n  [OK] %d employee(s) added successfully !\n.", count);
}

//f. Declare function: increaseSalary()
void increaseSalary(Employee list[], int n) {
	int i;
	float increase;

	if(n == 0) {
		printf("\n  [!] No employee data. Please add employees first.\n");

		return;
	}

	printf("\n Applying salary increase...\n");
	displayHeader();

	for(i - 0; i < n; i++) {
		if(list[i].salary <= 2000) {
			increase = list[i].salary * 0.15f; //tang 15%
		} else if(list[i].salary <= 5000) {
			increase = list[i].salary * 0.10f; //tang 10%
		} else {
			increase = 0; //khong tang
		}

		list[i].salary += increase;
		displayEmployee(list[i]);
	}

	printf("\n  [OK] Salary update completed!\n");
}

//g. Declare function: display10Years()
void display10Years(Employee list[], int n) {
	int i, found;
	int currentYear = 2025; // nam hien tai

	if(n == 0) {
		printf("\n  [!] No employee data. Please add employee first.\n");

		return;
	}

	found = 0;
	printf("\n  Employee who completed 10 years: \n");
	displayHeader();

	for(i = 0; i < n; i++) {
		//tinh so nam lam viec
		int yearWorked = currentYear - list[i].joined.year;

		if(yearWorked >= 10) {
			displayEmployee(list[i]);
			found++;
		}
	}

	if(found == 0) {
		printf("  [!] No employees have completed 10 years.\n");
	} else {
		printf("\n  Total: %d employee(s) found.\n", found);
	}
}
