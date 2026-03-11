/*
 * Chuong trình: Qu?n lý danh sách sinh viên
 * Tác gi?: Ví d? minh h?a
 * Ngày: 26/12/2025
 * Mô t?: Thêm, hi?n th?, tìm ki?m, s?p x?p, luu/d?c file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define FILENAME "students.dat"

// C?u trúc Sinh viên
typedef struct {
    int id;                     // Mã sinh viên
    char name[MAX_NAME];        // H? tên
    float gpa;                  // Ði?m trung bình
} Student;

// Bi?n toàn c?c
Student *students = NULL;       // M?ng d?ng luu danh sách
int count = 0;                  // S? lu?ng sinh viên hi?n t?i
int capacity = 0;               // Dung lu?ng hi?n t?i c?a m?ng

// Nguyên m?u hàm
void addStudent();
void displayStudents();
void searchStudent();
void sortStudents();
void saveToFile();
void loadFromFile();
void resizeArray();
int compareByGPA(const void *a, const void *b);

int main() {
    loadFromFile();  // Ð?c d? li?u t? file khi kh?i d?ng

    int choice;
    do {
        printf("\n=== QUAN LY SINH VIEN ===\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Tim kiem theo ma so\n");
        printf("4. Sap xep theo diem TB\n");
        printf("5. Luu vao file\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: sortStudents(); break;
            case 5: saveToFile(); printf("Da luu thanh cong!\n"); break;
            case 0: saveToFile(); printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    free(students);  // Gi?i phóng b? nh?
    return 0;
}

// Thêm sinh viên m?i
void addStudent() {
    if (count == capacity) {
        resizeArray();
    }

    Student s;
    printf("Nhap ma sinh vien: ");
    scanf("%d", &s.id);

    // Ki?m tra trùng ID
    int i;
    for (i = 0; i < count; i++) {
        if (students[i].id == s.id) {
            printf("Ma sinh vien da ton tai!\n");
            return;
        }
    }

    printf("Nhap ho ten: ");
    getchar(); // Xóa b? d?m newline
    fgets(s.name, MAX_NAME, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Xóa ký t? \n

    printf("Nhap diem trung binh: ");
    scanf("%f", &s.gpa);

    students[count] = s;
    count++;
    printf("Them thanh cong!\n");
}

// tang kich thuoc mang dong
void resizeArray() {
    capacity = capacity == 0 ? 10 : capacity * 2;
    students = (Student *)realloc(students, capacity * sizeof(Student));
    if (students == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
}

// Hi?n th? danh sách
void displayStudents() {
    if (count == 0) {
        printf("Danh sach rong!\n");
        return;
    }

    printf("\n%-8s %-30s %s\n", "Ma SV", "Ho ten", "Diem TB");
    printf("------------------------------------------------\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("%-8d %-30s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Tìm ki?m theo mã sinh viên
void searchStudent() {
    int id;
    printf("Nhap ma sinh vien can tim: ");
    scanf("%d", &id);

	int i;
    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Tim thay:\n");
            printf("Ma SV: %d | Ho ten: %s | Diem TB: %.2f\n",
                   students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ma %d\n", id);
}

// S?p x?p theo di?m TB gi?m d?n
void sortStudents() {
    if (count <= 1) {
        printf("Khong can sap xep!\n");
        return;
    }
    qsort(students, count, sizeof(Student), compareByGPA);
    printf("Da sap xep theo diem TB giam dan!\n");
}

int compareByGPA(const void *a, const void *b) {
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;
    if (s1->gpa > s2->gpa) return -1;
    if (s1->gpa < s2->gpa) return 1;
    return 0;
}

// Luu vào file (d?ng binary)
void saveToFile() {
    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        printf("Loi mo file de ghi!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(students, sizeof(Student), count, fp);
    fclose(fp);
}

// Ð?c t? file
void loadFromFile() {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        return; // File chua t?n t?i ? danh sách r?ng
    }
    fread(&count, sizeof(int), 1, fp);
    if (count > 0) {
        capacity = count;
        students = (Student *)malloc(capacity * sizeof(Student));
        fread(students, sizeof(Student), count, fp);
    }
    fclose(fp);
}
