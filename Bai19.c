/*PREPROCESSING*/
#include <stdio.h>
#include <string.h>

//// define structure globally
//struct strucintcal {
//    char name[20];
//    int numb;
//    float amt;
//};
//
//// function prototype
//void intcal(struct strucintcal abc);
//
//int main() {
//    struct strucintcal xyz;
//
//    printf("Enter customer name: ");
//    scanf("%19s", xyz.name);
//
//    printf("Enter customer number: ");
//    scanf("%d", &xyz.numb);
//
//    printf("Enter principal amount: ");
//    scanf("%f", &xyz.amt);
//
//    intcal(xyz);   // pass structure to function
//    return 0;
//}
//
//void intcal(struct strucintcal abc) {
//    float si;
//    float rate = 5.5;
//    float yrs = 2.5;
//
//    si = (abc.amt * rate * yrs) / 100;
//
//    printf("\nCustomer name   : %s", abc.name);
//    printf("\nCustomer number : %d", abc.numb);
//    printf("\nAmount          : %.2f", abc.amt);
//    printf("\nInterest        : %.2f", si);
//}

/*STRUCTURE DEFINITION*/
struct InfoStudent{
	char name[20];
	int age;
	float score;
};

struct Employee{
	char firstname[20];
	char lastname[20];
	int age;
	double salary;
};

/*DECLARE FUNCTION PROTOTYPE*/
void callInfo(struct InfoStudent info);

void callEmp(struct Employee emp);

int main(){
	//declare structure
	struct InfoStudent info;
	struct Employee emp;
	
	//input value for student
	printf("please enter student name: \n");
	scanf("%s", &info.name);
	printf("please enter student age: \n");
	scanf("%d", &info.age);
	printf("please enter student score: \n");
	scanf("%f", &info.score);
	//input value for employee
	printf("please enter first name: \n");
	scanf("%s", &emp.firstname);
	printf("please enter last name: \n");
	scanf("%s", &emp.lastname);
	printf("please enter employee's age: \n");
	scanf("%d", &emp.age);
	printf("please enter employee's salary: \n");
	scanf("%lf", &emp.salary);
	
	//pass structure [InfoStudent] to function [callInfo]
	callInfo(info);
	callEmp(emp);
	
	return 0;
}

/*DECLARE FUNCTION TO USE*/
void callInfo(struct InfoStudent info){
	printf("Student name: %s\n", info.name);
	printf("Student age: %d\n", info.age);
	printf("Student score: %.2f\n", info.score);
}

void callEmp(struct Employee emp){
	printf("Your first name: %s\n", emp.firstname);
	printf("Your last name: %s\n", emp.lastname);
	printf("your age: %d\n", emp.age);
	printf("Your salary: %lf\n", emp.salary);
}

