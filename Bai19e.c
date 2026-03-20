#include <stdio.h>
#include<string.h>
#include<conio.h>

typedef struct{
	char fullname[50];
	int age;
	float kpi;
	double salary;
} Employee;

// ham in duong ke
void printLine(){
	printf("+------------------------------+--------+--------+------------+\n");
}

// ham nhap du lieu
void inputlist(Employee *list, int n){
	int i;
	
	for(i = 0; i < n; i++){
		printf("\n--------Employe at [%d]: --------\n", i + 1);
		printf("Fullname: ");
		scanf(" %[^\n]", list[i].fullname);
		printf("Age: ");
		scanf("%d", &list[i].age);
		printf("Kpi: ");
		scanf("%f", &list[i].kpi);
		printf("Salary: ");
		scanf("%lf", &list[i].salary);
	}
}

// ham hien thi bang
void displayTable(Employee *list, int n){
	int i;

	printLine();
	printf("| %-28s | %-6s | %-6s | %-10s |\n", "FULLNAME", "AGE", "KPI", "SALARY");
	printLine();

	for(i = 0; i < n; i++){
		printf("| %-28s | %-6d | %-6.1f | %-10.1lf |\n",
			list[i].fullname,
			list[i].age,
			list[i].kpi,
			list[i].salary);
	}

	printLine();
}

// ham tim max_salary
Employee *find_maxsalary(Employee *list, int n){
	if(list == NULL || n <= 0){
		printf("[ERROR] List employee is empty !!!\n");
	}
	
	Employee *max = &list[0];
	
	int i;
	for(i = 0; i < n; i++){
		if(list[i].salary > max->salary){
			max = &list[i];
		}
	}
	
	return max;
}

int main(){
//	int n = 2;
//
//	Employee emp[2] = {
//		{"Nguyen Van A", 25, 8.5, 1200},
//		{"Tran Thi B", 30, 9.0, 1500}
//	};

	int n;
	printf("Enter number of list employee: ");
	scanf("%d", &n);
	
	Employee emp[n];

	//call function
	inputlist(emp, n);
	displayTable(emp, n);

	Employee *max = find_maxsalary(emp, n);
	printf("\nEmployee have maximum salary is: %s | (%.1lf)\n", max->fullname, max->salary);

	return 0;
}
