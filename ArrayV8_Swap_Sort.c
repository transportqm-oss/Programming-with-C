#include <stdio.h>
#include <stdlib.h>

/*
	Cho 01 mang co 10 phan tu, 10 bien co value
	Tim con so nho nhat trong mang, dua no len dau mang
*/

int main() {
	/*
		Version 01
	*/
//	int a[] = {-5, 10, 100, -50, 100, -1001, 1};
//	int min = a[0];
//	int pos = 0; //mac dinh nho nhat la thang dau tien
//	int t;
//	for(int i = 1; i < 7; i++) {
//		if(a[i] < min) {
//			//co ai do o vi tri i < min
//			//min phai doi vai cho thang a[i]
//			min = a[i];
//			pos = i; //vi tri i thay a[i] < min, min moi
//		}
//	}
//
//	if(pos > 0) {
//		//min nam o lung chung cua mang, hoan doi
//		t = a[0];
//		a[0] = a[pos]; //pos la noi tim thay min
//		a[pos] = t; //a[0] ngay xua
//	}
//
//	printf("After swapping, the array now is\n");
//	for(int i = 0; i < 7; i++) {
//		printf("%d ", a[i]);
//	}

	/*
		Version 02
	*/
	int a[] = {-5, -10, 100, -50, 100, -1001, 1};

	int t;

	for(int i = 1; i < 7; i++) {
		if(a[0] > a[i]) {
			t = a[0]; //cat a 0 di
			a[0] = a[i]; //tao dau day lay value nho nhon
			a[i] = t; //a 0 cu
		}
	}

	printf("After swapping, the array now is\n");
	for(int i = 0; i < 7; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}
