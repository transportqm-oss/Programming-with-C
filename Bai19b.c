#include<stdio.h>
#include<conio.h>
#include<string.h>

/*ARRAY OF STRUCTURES*/
struct Student{
	char name[20];
	int age;
	float score;
};

struct Employee{
	char fullname[50];
	int age;
	float kpi;
	double salary;
};

int main(){
	int n, i;
	
	printf("Please enter number of list employee: ");
	scanf("%d", &n);
	
//	printf("Enter number of students: ");
//	scanf("%d", &n);
	
	//declare array of structure
//	struct Student s[n];
	struct Employee emp[n];
	
	//Input data
	for(i = 0; i < n; i++){
		printf("Employee at [%d]:\n", i + 1);
		
		printf("Fullname: ");
		scanf("%s", emp[i].fullname);
		printf("Age: ");
		scanf("%d", &emp[i].age);
		printf("Kpi: ");
		scanf("%f", &emp[i].kpi);
		printf("Salaray: ");
		scanf("%lf", &emp[i].salary);
	}
//	for(i = 0; i < n; i++){
//		printf("Student [%d] \n", i + 1);
//		
//		printf("Name: ");
//		scanf("%s", s[i].name);
//		
//		printf("Age: ");
//		scanf("%d", &s[i].age);
//		
//		printf("Score: ");
//		scanf("%f", &s[i].score);
//	}
	
	//Output data
	printf("\n------------- Employee List -------------\n");
	for(i = 0; i < n; i++){
		printf("\nEmployee at [%d]:\n", i + 1);
		printf("Fullname    : %s\n", emp[i].fullname);
		printf("Age         : %d\n", emp[i].age);
		printf("KPI         : %f\n", emp[i].kpi);
		printf("Salary      : %ld\n", emp[i].salary);
	}
//	printf("\n------------- Student List -------------\n");	
//	for(i = 0; i < n; i++){
//		printf("\nStudent [%d] \n", i + 1);
//		printf("Name  : %s\n", s[i].name);
//		printf("Age   : %d\n", s[i].age);
//		printf("Score : %f\n", s[i].score);
//	}
	
	return 0;
}
