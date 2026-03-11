#include<stdio.h>
#include<conio.h>
#include<string.h>

/*DECLARE STRUCTURE*/
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

/*DECLARE FUNCTION*/
void displayStudent(struct Student *s){
	printf("Name   : %s\n", s->name);
	printf("Age    : %d\n", s->age);
	printf("Score  : %.2f\n", s->score);
}

void displayEmployee(struct Employee *e){
	printf("Fullname  : %s\n", e->fullname);
	printf("Age       : %d\n", e->age);
	printf("Kpi       : %.2f\n", e->kpi);
	printf("Salary    : %.2lf\n", e->salary);
}

int main(){
	struct Student st = {"Minh", 20, 8.5};
	struct Employee emp = {"Henry", 20, 8.5, 12000};
	
	//call function
	displayStudent(&st); //truyen dia chi
	printf("===================================\n");
	displayEmployee(&emp);
	
	return 0;
}
