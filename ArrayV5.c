#include <stdio.h>
#include <stdlib.h>

/*
	Nhap 01 mang 10 con so tu ban phim. Kiem tra xem so 10 co xuat hien hay khong
	Neu co xuat hien trong mang thi in ra
	I: 10 bien
	P: loi tung bien ra hoi value, kiem tra xem co == 10 hay khong, co thi ket luan
	O: in ra co hay khong
*/

int main() {
	//Khai bao mang int a[] co 10 value
	int a[] = {10, 6, -1000, 100, 50, 70, 6, 6, -1, 10};

	//Khai bao bien de ap dung "Ky thuat 03"
	int found = 0;

	//Khai bao bien da ap dung "Ky thuat 04"
	int position;

	/*
		Ky thuat 01
	*/
//	//duyet mang, quet tu dau den cuoi
//	for(int i = 0; i < 10; i++) {
//		if(a[i] == 10) {
//			printf("Hey, found 10 at position of %d\n", i);
//		} else {
//			printf("Hey, 10 not found in the array !!!\n");
//		}
//	}

	/*
		Ky thuat 02
	*/
//	for(int i = 0; i < 10; i++) {
//		if(a[i] == 10) {
//			printf("Hey, found 10 at position of %d\n", i);
//			break;
//		}
//	}

	/*
		Ky thuat 03 : su dung FLAG
	*/
//	for(int i = 0; i < 10; i++) {
//		if(a[i] == 10) {
//			found = 1; //neu tim thay value = 10 thi flag, dung chuong trinh
//			break;
//		}
//	}
//	//Kiem tra flag de in ket qua
//	if(found == 0) {
//		printf("10 not found !!!\n");
//	} else {
//		printf("10 found !!!\n");
//	}

	/*
		Ky thuat 04: su dung FLAG (nang cao)
	*/
	for(int i = 0; i < 10; i++) {
		if(a[i] == 10) {
			found = 1; //neu tim thay value = 10 thi flag, dung chuong trinh
			position = i; //moi lan tim thay value = 10 thi cat lai vi tri tim thay
			//break; //tim vi tri xuat hien cuoi cung neu bo khai bao break
		}
	}
	//	//Kiem tra flag de in ket qua
	if(found == 0) {
		printf("10 not found !!!\n");
	} else {
		printf("10 found at the position of %d!!!\n", (position + 1));
	}

	return 0;
}
