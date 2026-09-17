#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {
	/*
		+ BAI 01
		+ Tinh tong cua day so tu 1...100
		+ Input: da du du lieu dau vao, khong can bien
		+ P(Thuat toan = process):
		1+2+3+4+5+...+100 = sum
		+ Ouput: tong cua tat ca, in du lieu, xuat cau thong bao
	*/

	//int sum = 0; // VIP quan trong, neu khong bang 0 he thong se lay rac cong tiep vao du lieu
//	int acc = 0; // accumulation - tich luy, gom gop, cong don
//
//	printf("This program will show the sum of 100 first intergers (1...100)\n");
//
//	for(int i = 1; i <= 100; i++) {
//		acc += i; // sum += i; sum = sum + i
//	}
//
//	printf("The sum is %d\n", acc);

	/*
		+ BAI 02
		+ Tinh tong cua day so tu 1...n
		+ Input: chua co du lieu dau vao, khai bao bien int n
		+ P(Thuat toan = process):
		1+2+3+4+5+...+100 = sum
		+ Ouput: tong cua tat ca, in du lieu, xuat cau thong bao
	*/

//	int n, acc = 0;
//
//	printf("This program will show the sum of 100 first intergers (1...n)\n");
//
//	do {
//		printf("Please input n > 1: ");
//		scanf("%d", &n);
//
//		if(n <= 1) {
//			printf("Do you know to input an integer > 1?\n");
//		} else {
//			for(int i = 1; i <= n; i++) {
//				acc += i;
//			}
//
//			printf("The sum is %d\n", acc);
//		}
//	} while(n <= 1);

	/*
		+ BAI 03
		+ In ra cac so tu nhien tu 1...100
		+ Input: da co du lieu dau vao (la day so tu 1 den 100)
		+ P:
		+ O:
	*/

//	printf("The list of 100 first integers (1...100)\n");
//
//	printf("Using standard FOR\n");
//	for(int i = 1; i <= 100; i++) {
//		printf("%d ", i);
//	}
//
//	printf("\n\nUsing FOR remode.\n");
//	int count = 1;
//	for(;;) {
//		printf("%d ", count);
//		count++;
//		if(count == 101) {
//			break;
//		}
//	}
//
//	printf("\n\nUsing FOR remode 01.\n");
//	int cnt = 1;
//	do {
//		printf("%d ", cnt);
//		cnt++;
//	} while(cnt <= 100);
//
//	printf("\n\nUsing FOR remode 02.\n");
//	int cnt01 = 1;
//	do {
//		printf("%d ", cnt01);
//		cnt01++;
//
//		if(cnt01 == 101) {
//			break;
//		}
//	} while(69 < 96);
//
//	printf("\n\nUsing WHILE remode 01\n");
//	int cnt02 = 1;
//	while(cnt02 <= 101) {
//		printf("%d ", cnt02);
//		cnt02++;
//	}
//
//	printf("\n\nUsing WHILE remode 02\n");
//	int cnt03 = 1;
//	while(1 == 1) {
//		printf("%d ", cnt03);
//		cnt03++;
//
//		if(cnt03 == 101) {
//			break;
//		}
//	}

	/*
		+ BAI 04
		+ Tinh tong cac so tu 1...100 va in ra ket qua. 5050
		+ Input: da co du lieu dau vao (la day so tu 1 den 100)
		+ P:
		+ O:
	*/

	int sum = 0;
	printf("This program will show/compute the sum of 100 first integers.\n");
	for(int i = 1; i <= 100; i++) {
		sum += i;
	}

	printf("Sum (FOR): %d\n", sum);

	//Tinh tong dung do-while
	sum = 0;
	int count = 1;
	do {
		sum += count;
		count++;
	} while(count < 101);
	printf("Sum (FOR): %d\n", sum);

	return 0;
}
