#include<stdio.h>
#include<conio.h>
#include<string.h>

/*Declare structure*/
//struct Student{
//	char name[20];
//	int age;
//	float score;
//};

struct Employee{
	char fullname[50];
	int age;
	float kpi;
	double salary;
};

int main(){
	//declare structure and pointer structure
	struct Employee e;
	struct Employee *emp;
	
	//assign pointer to structure array
	emp = &e;

	//input data
	printf("Enter your fullname: ");
	scanf("%s", emp->fullname);;
	printf("Enter your age: ");
	scanf("%d", &emp->age);
	printf("Enter your kpi: ");
	scanf("%f", &emp->kpi);
	printf("Enter your salary: ");
	scanf("%lf", &emp->salary);
	
	//output data
	printf("\nList Employee Information: \n");
	printf("Your fullname    : %s\n", emp->fullname);
	printf("Your age         : %d\n", emp->age);
	printf("Your kpi         : %f\n", emp->kpi);
	printf("Your salary      : %.2lf\n", emp->salary);
	
//	struct Student s; 		//bien structure
//	struct Student *ptr;	//con tro structure	
//	
//	//gan dia chi
//	ptr = &s;
//	
//	//nhap du lieu thong qua con tro
//	printf("Enter name: ");
//	scanf("%s", ptr->name);
//	
//	printf("Enter age: ");
//	scanf("%d", &ptr->age);
//	
//	printf("Enter score: ");
//	scanf("%f", &ptr->score);
//	
//	//xuat du lieu
//	printf("\nStudent Information: \n");
//	printf("Name      : %s\n", ptr->name);
//	printf("Age       : %d\n", ptr->age);
//	printf("Score     : %.2f\n", ptr->score);
	
	return 0;
}
