#include <stdio.h>
#include <stdlib.h>

/*
	De bai: muon luu 10 cot diem cua mon hoc
*/

int main() {
	float c1, c2, c3, c4, c5, c6, c7, c8, c9, c10; //khai bao le, mat thoi gian, ton suc nhung de thao tac

	float c[10]; //giong cach tren la co duoc 10 value, cuc nhanh, muon bao nhieu thi thay value trong [ ]

	c1 = 10.0;	//bien le
	c[0] = 10.0; //bien kieu mang

	printf("Bien le: %.2f %.2f %.2f\n", c1, c2, c3);

	printf("Bien mang: %.2f %.2f %.2f\n", c[0], c[1], c[2]);

	//Moi bien trong mang, tinh tu 0, duoc goi la 01 phan tu, ELEMENT
	//muon nhap gia tri cho bien thuong/bien mang/phan tu cua mang
	printf("Input 2 grades (0...10): ");
	scanf("%f", &c2); //bien thuong
	scanf("%f", &c[1]); //bien mang, la 01 bien float

	printf("After inputing two grades, the current grades: \n");

	printf("Bien le: %.2f %.2f %.2f\n", c1, c2, c3);
	printf("Bien mang: %.2f %.2f %.2f\n", c[0], c[1], c[2]);

	//neu user muon nhap het 10 bien le, 10 bien si-mang
//	scanf("%f %f %f %f %f %f", &c1, &c2, &c3, &c4, &c5, &c6); //input rat mat thoi gian
//	scanf("%f", &c[i]); //i chay tu 0...i

	return 0;
}
