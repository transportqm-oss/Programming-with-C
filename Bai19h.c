#include <stdio.h>
#include <conio.h>
#include <string.h>

/*
	Write a C program to store the names and scores of 5 students in a structure array. 
	Sort the structure array in descending order of scores. Display the top 3 scores.
*/

/*
	Mang sau khi sort:
+-------------------------+
¦ Index ¦  Name   ¦ Score ¦
+-------+---------+-------¦
¦  [0]  ¦  Diana  ¦ 95.50 ¦   1st
¦  [1]  ¦   Bob   ¦ 92.00 ¦	  2nd
¦  [2]  ¦ Edward  ¦ 88.00 ¦	  3rd
¦  [3]  ¦  Alice  ¦ 85.50 ¦   no display
¦  [4]  ¦ Charlie ¦ 78.00 ¦   no display
+-------------------------+

i = 0: printf("1ST",  "Diana",   95.50)
i = 1: printf("2ND",  "Bob",     92.00)
i = 2: printf("3RD",  "Edward",  88.00)

*/

//define structure for student
typedef struct{
	char name[50];
	float score;
} Student;

//function to input student details
void inputStudents(Student *list, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("\n============== Student[%] ==============\n", i + 1);
		printf("Name  : ");
		scanf(" %[^\n]", list[i].name);
		printf("Score : ");
		scanf("%f", &list[i].score);
	}
}

//function to sort in descending order using Bubble Sort
void bubbleSortDescending(Student *list, int n){
	int i, j;
	Student temp;
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			//swap if current score is LESS than next (descending order)
			if(list[j].score < list[j + 1].score){
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

//function to display all students after sorting
void displayAll(Student *list, int n){
	printf("\n==========================================\n");
	printf("%-5s %-20s %-10s\n", "RANK", "NAME", "SCORE");
	printf("==========================================\n");
	
	int i;
	for(i = 0; i < n; i++){
		printf("%-5d %-20s %.2f\n", i + 1, list[i].name, list[i].score);
	}
	
	printf("==========================================\n");
}

//function to display top 3 students
void displayTop3(Student *list, int n){
	printf("\n==========================================\n");
	printf("           || TOP 3 STUDENTS ||           \n");
	printf("==========================================\n");
	
	char *medal[] = {"|| 1ST", "|| 2ND", "|| 3RD"};
	
	int i;
	for(i = 0; i < 3; i++){
		printf("%s %-20s %.2f\n", medal[i], list[i].name, list[i].score);
	}
	
	printf("==========================================\n");
}

int main(){
	//declare value number
	int n;
	printf("Enter value number of list Student: ");
	scanf("%d", &n);
	
	//check value
	if(n <= 0){
		printf("[WARNING]Value number of list Student must be greater than 0!\n");
		
		return 1;
	}
	
	//declare array
	Student students[n];
	
	printf("==========================================\n");
	printf("        STUDENT SCORE MANAGEMENT          \n");
	printf("==========================================\n");
	
	//call function
	inputStudents(students, n);
	
	//sort in descending order
	bubbleSortDescending(students, n);
	
	//display all students after sorting
	printf("\n=== All Students (Sorted by Score) ===");
	displayAll(students, n);
	
	//display top 3
	displayTop3(students, n);
	
	return 0;
}
