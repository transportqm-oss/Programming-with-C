#include <stdio.h>
#include <stdlib.h>

/*
	Ky thuat khai bao mang va gan luon gia tri
	int a = 10;
*/

int main() {
	/*
		cho 06 diem, ma lai co 10 bien
		gan value ngay cho 06 phan tu dau cua mang
		[0] = 1; [5] = 8;
		bien con lai value DEFAULT = 0; khong gan gia tri RAC lung tung
		MANG GIONG NHU TAP HOP/DAY VALUE O TOAN HOC PHO THONG!!!
	*/
	float c[10] = {1, 1, 2, 3, 5, 8};
	printf("Your ten grades\n");
	for(int i = 0; i < 10; i++) {
		printf("Grade [%d] = %.2f\n", i, c[i]);
	}

	/*
		Cau lenh nay khong noi ro co bao nhieu bien duoc cap.
		Gan san value cho 01 so bien. Mang se tu dong duoc cap so bien
		Tuy theo so luong value duoc gan, bai nay chinh la mang [5]
	*/
	float col[] = {2, 4, 6, 8, 10};

	//float a[]; //khai bao kieu nay se bi canh bao vi khong noi ro bao nhieu bien
	//phai noi ro so bien can xin

	return 0;
}
