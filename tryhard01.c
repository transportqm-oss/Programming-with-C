#include<stdio.h>
#include<stdlib.h>

int main() {
	char fL;

	printf("Vui long nhap vao 01 ky tu: ");
	scanf("%c", &fL);

	printf("in ky tu vua nhap xong: %c\n", fL);

	fL += 32;

	printf("in ky tu sau khi chuyen trang thai: %c\n", fL);

	return 0;
}
