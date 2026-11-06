#include <stdio.h>
#include <stdlib.h>

/*
	Khao sat RAM duoc cap cho mang
*/

int main() {
	float c[10]; //co 10 bien

	//kiem tra address cua 10 bien nay
	/*
	printf("The address of c[0] is %u\n", &c[0]);
	printf("The address of c[1] is %u\n", &c[1]);
	printf("The address of c[2] is %u\n", &c[2]);
	printf("The address of c[3] is %u\n", &c[3]);
	printf("The address of c[4] is %u\n", &c[4]);
	*/

	printf("The address of all of elements in the array: \n");;
	for(int i = 0; i < 10; i++) {
		printf("The address of c[%d] is %u\n", i, &c[i]);
	}

	/*
		[i] i chay tu 0... cuoi mang
		[index chi so phan tu/thu tu/bien thu may !!!]
		Ten mang rat dac biet, no chua value chinh la dia chi cua bien dau mang
		%u: unsigned so nguyen khong dau , tuc la so +
		%d: so nguyen co dau, tuc la so + va -
	*/

	printf("The value of c is %d\n", c); //in gia tri cua 01 bien thi dung % da khai bao, value tra ve la dia chi cua bien dau tien trong mang

	return 0;
}
