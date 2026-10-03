#include <stdio.h>
#include <stdlib.h>

/*
	BAI 02: Viet app theo cac yeu cau sau:	FACTORIAL = Giai Thua
	1! + 2! + 3! + 4! + ............ + n! (n > 1)
	Tinh tong cac giai thua
	n! = 1.2.3.4...n
	IPO:
	I: khong co n sao biet tinh den may giai thua, biet can phai nhoi bao nhieu oc buu
	P: da vua lam o V2
	O: tuy n may ket qua sum la may

*/

int getFactorial(int n); //V4 - soai ca - re_use!!!

int main() {
//	printf("5! = %d\n", getFactorial(5));
//	//getFactorial(5);
//
//	//re_use bat dau
//	//tinh tong cua cac giai thua duoc nhap vao
//	int sum = getFactorial(1) + getFactorial(2) + getFactorial(3) + getFactorial(4) + getFactorial(5);
//	printf("Sum of factorial chain from 1 to 5! = %d\n", sum);

	int n;
	int sum = 0;

	printf("Input an integer >= 2 to get the sum of a factorial: ");
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		sum = sum + getFactorial(i); //Kiem thu phan mem: n = 6; 720 + 153 = 873
	}

	printf("Sum of factorial chain from 1 to %d! = %d\n", n, sum);

	return 0;
}

int getFactorial(int n) {
	int acc = 1;

	if(n == 0 || n == 1) {
		return 1;
	}

	for(int i = 2; i <= n; i++) {
		acc *= i;
	}

	return acc;
}

//HAM LOAI 04 - VERSION 01
/*
	int getFactorial(int n) {
	int acc = 1;

	if(n == 0 || n == 1) {
		return 1;
	}

	for(int i = 2; i <= n; i++) {
		acc *= i;
	}

	//printf("%d! = %d", n, acc); //cau lenh in khong xu li trong ham co return, khong nen vi anh huong re-use

	return acc;
}
*/

//HAM LOAI 04 - VERSION 02
/*
	int getFactorial(int n) {
	int acc = 1;

	if(n == 0 || n == 1) {
		return 1;
	}

	for(int i = 2; i <= n; i++) {
		acc *= i;
	}

	return acc;
}
*/
