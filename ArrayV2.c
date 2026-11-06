#include <stdio.h>
#include <stdlib.h>

/*
	Luu 10 cot diem cua mon C
*/

int main() {
	float c[10]; //co 10 bien float [0...]
	//scanf("%f", &c[0]); //tiep tuc thay 0, bang 1, 2...
	printf("Please input 10 grades of the C class (0...10)\n");
	for(int i = 0; i < 10; i++) {
		printf("Input grade[%d]: ", (i + 1)); //ky thuat nhap lua dao chi so mang
		scanf("%f", &c[i]);
	}

	printf("Here is your grades: \n");
	for(int i = 0; i < 10; i++) {
		printf("%.2f\t", c[i]); //bien float ten phuc tap
	}

	return 0;
}
