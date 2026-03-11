#include<stdio.h>
#include<conio.h>
#include<string.h>

/*DECLARE TYPEDEF STRUCTURE*/
typedef struct{
	char name[20];
	int age;
	float score;
} Student;

/*DECLARE FUNCTION*/
void inputlist(Student *list, int n){
	int i;
	
	for(i = 0; i < n; i++){
		printf("\n----------Student at [%d]: ----------\n", i + 1);
		printf("Name: ");
		scanf(" %[^\n]", list[i].name);
		printf("Age: ");
		scanf("%d", &list[i].age);
		printf("Score: ");
		scanf("%f", &list[i].score);
	}
}

void displaylist(Student *list, int n){
	printf("\n|%-10s | %-6s | %-5s\n", "NAME", "AGE", "SCORE");
	
	int i;
	for(i = 0; i < n; i++){
		printf("|%-10s | %-6d | %.1f\n", list[i].name, list[i].age, list[i].score);
	}
}

Student *find_maxscore(Student *list, int n){
	Student *max = &list[0];
	
	int i;
	for(i = 0; i < n; i++){
		if(list[i].score > max->score){
			max = &list[i];
		}
	}
	
	return max;
}

int main(){
	//declare value
	int n;
	printf("please enter number of list student: ");
	scanf("%d", &n);
	
	//declare array - VLA - khai bao mang kich thuoc dong
	Student st[n];
	
	//call function
	inputlist(st, n);
	displaylist(st, n);
	
	Student *maxscore = find_maxscore(st, n);
	printf("\nThe Student have score maximum in class: %s | %.2lf\n", maxscore->name, maxscore->score);
	
	return 0;
}
