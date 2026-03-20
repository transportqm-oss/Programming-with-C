#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
	int id;
	char fullname[50];
	int age;
	float kpi;
	double salary;
} Employee;

//================= UI =================//
void printLine(){
	printf("+----+------------------------------+--------+--------+------------+\n");
}

void displayTable(Employee *list, int n){
	int i;

	printLine();
	printf("| %-2s | %-28s | %-6s | %-6s | %-10s |\n", "ID", "FULLNAME", "AGE", "KPI", "SALARY");
	printLine();

	for(i = 0; i < n; i++){
		printf("| %-2d | %-28s | %-6d | %-6.1f | %-10.1lf |\n",
			list[i].id,
			list[i].fullname,
			list[i].age,
			list[i].kpi,
			list[i].salary);
	}

	printLine();
}

//================= INPUT =================//
void addEmployee(Employee *list, int *n){
	printf("\n--- Add Employee ---\n");

	printf("ID: ");
	scanf("%d", &list[*n].id);

	printf("Fullname: ");
	scanf(" %[^\n]", list[*n].fullname);

	printf("Age: ");
	scanf("%d", &list[*n].age);

	printf("KPI: ");
	scanf("%f", &list[*n].kpi);

	printf("Salary: ");
	scanf("%lf", &list[*n].salary);

	(*n)++;
}

//================= SEARCH =================//
void searchByName(Employee *list, int n){
	char key[50];
	int found = 0;

	printf("\nEnter name to search: ");
	scanf(" %[^\n]", key);
	
	int i;
	for(i = 0; i < n; i++){
		if(strstr(list[i].fullname, key) != NULL){
			if(!found){
				printf("\n--- Found ---\n");
				printLine();
				printf("| %-2s | %-28s | %-6s | %-6s | %-10s |\n", "ID", "FULLNAME", "AGE", "KPI", "SALARY");
				printLine();
			}
			printf("| %-2d | %-28s | %-6d | %-6.1f | %-10.1lf |\n",
				list[i].id,
				list[i].fullname,
				list[i].age,
				list[i].kpi,
				list[i].salary);
			found = 1;
		}
	}

	if(!found){
		printf("No employee found!\n");
	}else{
		printLine();
	}
}

//================= SORT =================//
void sortBySalary(Employee *list, int n){
	int i, j;
	Employee temp;

	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(list[i].salary > list[j].salary){
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}

	printf("\nSorted by salary (ascending).\n");
}

//================= DELETE =================//
void deleteById(Employee *list, int *n){
	int id, i, j;
	printf("\nEnter ID to delete: ");
	scanf("%d", &id);

	for(i = 0; i < *n; i++){
		if(list[i].id == id){
			for(j = i; j < *n - 1; j++){
				list[j] = list[j+1];
			}
			(*n)--;
			printf("Deleted successfully!\n");
			return;
		}
	}

	printf("ID not found!\n");
}

//================= MENU =================//
void menu(){
	printf("\n========= EMPLOYEE MANAGEMENT =========\n");
	printf("1. Add Employee\n");
	printf("2. Display List\n");
	printf("3. Search by Name\n");
	printf("4. Sort by Salary\n");
	printf("5. Delete by ID\n");
	printf("0. Exit\n");
	printf("Choose: ");
}

//================= MAIN =================//
int main(){
	Employee list[MAX];
	int n = 0;
	int choice;

	do{
		menu();
		scanf("%d", &choice);

		switch(choice){
			case 1:
				addEmployee(list, &n);
				break;
			case 2:
				if(n == 0) printf("List is empty!\n");
				else displayTable(list, n);
				break;
			case 3:
				searchByName(list, n);
				break;
			case 4:
				sortBySalary(list, n);
				break;
			case 5:
				deleteById(list, &n);
				break;
			case 0:
				printf("Exit program.\n");
				break;
			default:
				printf("Invalid choice!\n");
		}

	}while(choice != 0);

	return 0;
}
