#include <stdio.h>
#include <stdlib.h>

/*
	Nhap tu ban phim mang 10 so nguyen bat ki.
	Kiem tra xem con so 10 co xuat hien trong mang khong
*/

int main() {
	int n[10];
	int pos = -1; //bien nay vua dong vai tro la bien flag, vua luu vi tri

	printf("Please input 10 numbers\n");
	for(int i = 0; i < 10; i++) {
		printf("Input number #%d: ", (i + 1));
		scanf("%d", &n[i]); // &n[i] ~~ int yob &yob
	}

	//in mang
	printf("You have just input the following numbers\n");
	for(int i = 0; i < 10; i++) {
		printf("%d\t", n[i]);
	}
	printf("\n");

	//tim xem number 10 co xuat hien khong
	for(int i = 0; i < 10; i++) {
		if(n[i] == 10) {
			pos = i; //poss luu vi tri tu 0...9 neu thay
			break;
		}
	}

	if(pos == -1) {
		printf("10 not found\n");
	} else {
		printf("10 found at the postion of %d\n", (pos + 1));
	}

	return 0;
}
