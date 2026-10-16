#include <stdio.h>
#include <stdlib.h>

/*
	+ Minh co xai do nha nguoi khac duoc khong
	+ Anh co nhin thay em khong
*/

int yob = 2002;

void printYob();
void printLastedYob();
void seeNothing();

int main() {
	seeNothing();

	printf("in main(), your yob is: %d\n", yob); //value lan luot la: 2010, 2002

	return 0;
}

void printYob() {
	int age = 2022 - yob; //hop le vi yob la bien global
	//age la bien local
	printf("Your age is: %d\n", age); //Lenh nay hop le
}

void printLastedYob() {
	//int age;
	//printf("Your age is: %d\n", age); //Lenh nay se bao loi vi dang xai bien cua ham khac
}

void seeNothing() {
	int yob = 2010; //bien local trung ten voi bien global, uu tien o gan, uu tien nguoi nha
	printf("in seeNothing(), your yob is: %d\n", yob);
}
