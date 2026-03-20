#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char name[50];
    int age;
    float score;
} Student;

/*INPUT LIST*/
void inputList(Student *list, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\n------- Student [%d] -------\n", i + 1);
        printf("Name  : ");
        scanf(" %[^\n]", list[i].name);
        printf("Age   : ");
        scanf("%d", &list[i].age);
        printf("Score : ");
        scanf("%f", &list[i].score);
    }
}

/*DISPLAY LIST*/
void displayList(Student *list, int n) {
    printf("\n%-20s %-6s %-5s\n", "Name", "Age", "Score");
    printf("----------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%-20s %-6d %.1f\n", list[i].name, list[i].age, list[i].score);
    }
}

/*INSERTION SORT - sap xep tang dan theo score*/
void insertionSort(Student *list, int n) {
    int i, j;
    Student key;

    for (i = 1; i < n; i++) {
        key = list[i];      // Luu phan tu hien tai
        j = i - 1;

        // Dich cac phan tu co score lon hon key sang phai
        while (j >= 0 && list[j].score > key.score) {
            list[j + 1] = list[j];
            j--;
        }

        // Chen key vao dung vi tri
        list[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Kiem tra dieu kien n <= 0
    if (n <= 0) {
        printf("[WARNING] Number of students must be greater than 0!\n");
        return 1;
    }
	
	// Goi ham
    Student list[n];

    inputList(list, n);

    // Kiem tra danh sach rong
    if (list == NULL) {
        printf("[WARNING] Student list is empty!\n");
        return 1;
    }

    printf("\n===== BEFORE SORT =====");
    displayList(list, n);

    insertionSort(list, n);

    printf("\n===== AFTER SORT (ascending score) =====");
    displayList(list, n);
		
    return 0;
}

/*
	SITE MAP
	
	i=1 -> n-1
  ¦
  ?
key = list[i]       <- luu phan tu can chen
j   = i - 1
  ¦
  ?
+----------------------------------+
¦ j >= 0 && list[j].score > key ?  ¦
+----------------------------------+
       ¦ YES                ¦ NO
       |                    |
list[j+1] = list[j]    list[j+1] = key  <- chen dung cho
j--                         ¦
       ¦                    |
       +---------->   i tiep theo
*/
