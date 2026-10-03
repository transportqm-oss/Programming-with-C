#include <stdio.h>
#include <stdlib.h>

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

int getFactorialV4(int n); //ham loai 04, y = f(x) = x^2...

int main() {
	printf("0! = %d\n", getFactorialV4(0)); //May la 01 value, xai luon, khoi can gan bien

	printf("6! = %d\n", getFactorialV4(6));

	return 0;
}

//Ham loai 04
int getFactorialV4(int n) {
	int acc = 1;

	//return 69; //test case, bi chan ngay lap tuc, khong quan tam cac phan con lai

	if(n == 0 || n == 1) {
		return 1; //biet ngay 0! = 1! = 1, thoat chuong trinh
	}

	for(int i = 2; i <= n; i++) {
		acc *= i; //acc = acc * i;
	}

	//printf("%d! = %d\n", n, acc); //Khong nen IN khi ham rea ve gia tri !!!
	return acc;

	printf("Cau lenh test xem lenh return co toi duoc dong printf nay khong!!!\n");
	//Cau lenh nay the hien CPU khong cham toi duoc, do lenh RETURN da dung o tren
}

/*
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
*/

/*
int getFactorialV4(int n) {
	int acc = 1;

	//return 69; //test case, bi chan ngay lap tuc, khong quan tam cac phan con lai

	if(n == 0 || n == 1) {
		return 1; //biet ngay 0! = 1! = 1, thoat chuong trinh
	} else {
		for(int i = 2; i <= n; i++) {
			acc *= i; //acc = acc * i;
		}

		//printf("%d! = %d\n", n, acc); //Khong nen IN khi ham rea ve gia tri !!!
		return acc;
	}

	printf("Cau lenh test xem lenh return co toi duoc dong printf nay khong!!!\n");
	//Cau lenh nay the hien CPU khong cham toi duoc, do lenh RETURN da dung o tren
}
*/
