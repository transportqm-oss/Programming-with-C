#include <stdio.h>
#include <stdlib.h>

/*
	BAI 01: Viet ham tinh tong tu 1 den 100
*/
int sumIntegerList();

/*
	BAI 02: Viet app theo cac yeu cau sau:	FACTORIAL = Giai Thua
	1! + 2! + 3! + 4! + 5! + 6! + 7! + 8!
	1! + 2! + 3! + 4! + ............ + n! (n > 1)
	Tinh tong cac giai thua
	n! = 1.2.3.4...n
	Phuc tap cua bai toan:
	- Tinh n! giai thua!!! -> bai toan oc buu nhoi thit -> 01 vong for de nhoi
	- Bai nay thi lai co nhieu giai thua cong nhau -> 01 vong nhoi cac giai thua
	- 02 vong for long nhau neu chua cung tay viet code
*/
void getFactorialV1();
void getFactorialV2(int n);
int getFactorialV3();
int getFactorialV4(int n); //ham loai 04, y = f(x) = x^2...

/*
	BAI 03: Hay in ra cac nguyen to trong toan tu 1...1000
	1..............1000 (2 3 5 7 1 13 17 19 23 29...
*/

/*
	BAI 04: Hay in ra 1000 so nguyen to dau tien tinh tu 2....
*/

int main() {
	//BAI 01
//	int result;
//
//	result = sumIntegerList();
//
//	printf("The sum of list integer form 01 to 100: %d\n", result);

	//BAI 02
//	getFactorialV1();
//	getFactorialV2(6); //1.2.3.4.5.6 =270
//	int result = getFactorialV3(); //Ham tra ve lue, khai bao bien result de nhan value
//	printf("Result: %d\n", result);
//	printf("Result: %d\n", getFactorialV3()); //day la value acc ngam trong do, in acc la hien than qua ten ham

	getFactorialV4(5); //Ngam tra ve 120, khong in, neu in khong re-use duoc tot nhat
	printf("Result: %d\n", getFactorialV4(5));

	return 0;
}

//Declare Function for BAI 01
int sumIntegerList() {
	int sum = 0;

	for(int i = 1; i <= 100; i++) {
		sum += i; //sum = sum + i
	}

	return sum;
}

//Declare Function for BAI 02
//Ham loai 01
void getFactorialV1() {
	int n, acc = 1;
	//0 danh cho tong don, tich thi ban dau te nhat la 1. Sau do 1 nhan voi ai cung khong anh huong

	printf("Input a number (>= 0) to get the factorial: ");
	scanf("%d", &n);
	//co kha nang nhap lung tung, se cap nhap tinh nang validation
	if(n == 0 || n == 1) {
		acc = 1;
	} else {
		for(int i = 2; i <= n; i++) {
			acc *= i; //acc = acc * i;
		}
	}

	//return acc; do ham nay khong return, thi phai in ra !!1
	printf("%d! = %d\n", n, acc);
}

//Ham loai 02
void getFactorialV2(int n) {
	int acc = 1;
	//0 danh cho tong don, tich thi ban dau te nhat la 1. Sau do 1 nhan voi ai cung khong anh huong

	//co kha nang nhap lung tung, se cap nhap tinh nang validation
	if(n == 0 || n == 1) {
		acc = 1;
	} else {
		for(int i = 2; i <= n; i++) {
			acc *= i; //acc = acc * i;
		}
	}

	//return acc; do ham nay khong return, thi phai in ra !!1
	printf("%d! = %d\n", n, acc);
}

//Ham loai 03
int getFactorialV3() {
	int n, acc = 1;

	printf("Input a number (>= 0) to get the factorial: ");
	scanf("%d", &n);
	//co kha nang nhap lung tung, se cap nhap tinh nang validation
	if(n == 0 || n == 1) {
		acc = 1;
	} else {
		for(int i = 2; i <= n; i++) {
			acc *= i; //acc = acc * i;
		}
	}

	//return acc; //Do ham khong return, thi phai in ra!!! -> VIET THE NAY THI KHONG RA DUOC VALUE

	//return acc; do ham nay khong return, thi phai in ra!!!
	printf("%d! = %d\n", n, acc); //Khong nen IN khi ham rea ve gia tri !!!
	return acc;
}

//Ham loai 04
int getFactorialV4(int n) {
	int acc = 1;

	if(n == 0 || n == 1) {
		acc = 1;
	} else {
		for(int i = 2; i <= n; i++) {
			acc *= i; //acc = acc * i;
		}
	}

	//printf("%d! = %d\n", n, acc); //Khong nen IN khi ham rea ve gia tri !!!
	return acc;
}
