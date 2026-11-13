#include <stdio.h>
#include <stdlib.h>

/*
	Nhap 01 mang 10 con so. In ra con so nho nhat, lon nhat cua mang
	IPO
	I: can 10 con so, khai bao le, khai bao SI-MANG
	P: -5 10 100 -50 1000
		quet/nhin qua ca mang, [i] la bao nhieu, bien co, nguyen tac gia dinh, den khi SAI thi sua
	O: min, max -> 02 bien
*/

int main() {
//	int a[] = {-5, 10, 100, -50, 1000, 1, 2, -50, 1001, 1};
//	int min, max;
//	min = a[0]; //bien a[0] chua value -5, ten bien phuc tap hon
//	max = a[0];
//
//	for(int i = 1; i < 10; i++) {
//		if(a[i] < min) {
//			min = a[i]; //flag chi doi min khi min > ai do
//		}
//		if(a[i] > max) {
//			max = a[i]; //doi khi vi tri khi phat hien [i] > max
//		}
//	}
//
//	printf("The min value of this array: %d\n", min);
//	printf("The max value of this array: %d\n", max);

	int a[10];
	int min, max;

	printf("Input 10 numbers\n");
	for(int i = 0; i < 10; i++) {
		printf("Input number #%d: ", (i + 1));
		scanf("%d", &a[i]);
	}

	printf("You have just input the following numbers\n");
	for(int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}

	min = a[0]; //phai cho user nhap xong thi moi co a[i]
	for(int i = 1; i < 10; i++) {
		if(a[i] < min) {
			min = a[i];
		}
	}

	printf("\nThe min value of this array: %d\n", min);

	return 0;
}
