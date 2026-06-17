#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//declare prototype
void inputAndSave(char filename[], int seriesNum);
void sortFile(char filename[]);
void mergeAndSort(char file1[], char file2[], char fileOut[]);
void displayFile(char filename[]);
void bubbleSort(int arr[], int n);

int main() {
	int choice;

	//declare value
	char file1[] = "series1.txt";
	char file2[] = "series2.txt";
	char merged[] = "merged.txt";

	do {
		printf("\n==========================================\n");
		printf("         FILE SERIES MANAGER             \n");
		printf("==========================================\n");
		printf("  1. Enter Series 01 (save to %s)\n", file1);
		printf("  2. Enter Series 02 (save to %s)\n", file2);
		printf("  3. Sort both files\n");
		printf("  4. Merge, sort, and save to %s\n", merged);
		printf("  5. Display merged file\n");
		printf("  6. Exit\n");
		printf("==========================================\n");
		printf("  Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				inputAndSave(file1, 1);
				break;
			case 2:
				inputAndSave(file2, 2);
				break;
			case 3:
				sortFile(file1);
				sortFile(file2);
				printf("\n  Sort contens: \n");
				displayFile(file1);
				displayFile(file2);
				break;
			case 4:
				mergeAndSort(file1, file2, merged);
				break;
			case 5:
				displayFile(merged);
				break;
			case 6:
				printf("\n  Goodbye!\n\n");
				break;
			default:
				printf("\n  [!] Invalid choice. Enter 01 to 06.\n");
		}
	} while(choice != 6);

	return 0;
}

//Helper: function Bubble Sort
void bubbleSort(int arr[], int n) {
	int i, j, temp;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//Declare function: input and save value
void inputAndSave(char filename[], int seriesNum) {
	FILE *fp;
	int count, i, num;

	//input value
	printf("\n How many numbers in Series %d? ", seriesNum);
	scanf("%d", &count);

	if(count <= 0 || count > MAX) {
		printf("  [!] Invalid. Must be between 1 and %d.\n", MAX);
		return;
	}

	//open file and overwrite it
	fp = fopen(filename, "w");
	if(fp == NULL) {
		printf("  [!] Cannot open file %s.\n", filename);
		return;
	}

	//ghi so luong phan tu vao dong dau file
	fprintf(fp, "%d\n", count);

	//nhap va ghi tung so vao file
	printf("  Enter %d numbers: \n", count);
	for(i = 0; i < count; i++) {
		printf("  [%d]: ", i + 1);
		scanf("%d", &num);
		fprintf(fp, "%d\n", num);
	}

	fclose(fp);
	printf("  [OK] Series %d saved to '%s'.\n", seriesNum, filename);
}

//Declare function: doc file, sort, ghi lai file
void sortFile(char filename[]) {
	FILE *fp;
	int arr[MAX], count, i;

	//mo file de doc
	fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("  [!] Cannot open file %s.\n", filename);
		return;
	}

	//doc so luong phan tu o dong dau
	fscanf(fp, "%d", &count);

	//doc tung so vao mang
	for(i = 0; i < count; i++) {
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);

	//sort mang
	bubbleSort(arr, count);

	//ghi lai file voi mang da sort
	fp = fopen(filename, "w");
	if(fp == NULL) {
		printf("  [!] Cannot open file %s.\n", filename);
		return;
	}

	fprintf(fp, "%d\n", count);
	for(i = 0; i < count; i++) {
		fprintf(fp, "%d\n", arr[i]);
	}
	fclose(fp);

	printf("  [OK] File '%s' sorted successfully.\n", filename);
}

//Declare function: merge 02 file, sort and save vao file moi
void mergeAndSort(char file1[], char file2[], char fileOut[]) {
	FILE *fp1, *fp2, *fpOut;
	int arr[MAX * 2];
	int count1, count2, totalCount, i;

	//doc file 1
	fp1 = fopen(file1, "r");
	if(fp1 == NULL) {
		printf("  [!] Cannot open file %s\n", file1);
		return;
	}
	fscanf(fp1, "%d", &count1);
	for(i = 0; i < count1; i++) {
		fscanf(fp1, "%d", &arr[i]);
	}
	fclose(fp1);

	//doc file 2 -> noi tiep vao arr sau file 1
	fp2 = fopen(file2, "r");
	if(fp2 == NULL) {
		printf("  [!] Cannot open file %s.\n", file2);
		return;
	}
	fscanf(fp2, "%d", &count2);
	for(i = 0; i < count2; i++) {
		fscanf(fp2, "%d", &arr[count1 + i]);
	}
	fclose(fp2);

	//tinh tong so phan tu
	totalCount = count1 + count2;

	//sort mang da merge
	bubbleSort(arr, totalCount);

	//ghi vao file moi
	fpOut = fopen(fileOut, "w");
	if(fpOut == NULL) {
		printf("  [!] Cannot open file %s.\n", fileOut);
		return;
	}
	fprintf(fpOut, "%d\n", totalCount);
	for(i = 0; i < totalCount; i++) {
		fprintf(fpOut, "%d\n", arr[i]);
	}
	fclose(fpOut);

	printf("  [OK] Merged and sorted into: '%s'.\n", fileOut);
}

//Declare function: doc va hien thi noi dung file
void displayFile(char filename[]) {
	FILE *fp;
	int count, num, i;

	fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("  [!] Cannot open file %s.\n", filename);
		return;
	}

	fscanf(fp, "%d", &count);

	printf("\n Contents of '%s' (%d numbers): \n", filename, count);
	printf("  ");
	for(i = 0; i < count; i++) {
		fscanf(fp, "%d", &num);
		printf("%d ", num);
	}
	printf("\n");
	fclose(fp);
}

