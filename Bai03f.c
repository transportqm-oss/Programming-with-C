#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	CO 02 LOAI HAM
	- Loai 01 (Pre-defined Functions): co san, thien ha viet san roi, cho minh xai. Tim dem ve xai.
		+ toLwe(ki tu) -> chu thuong
		+ sqrt(con so) -> can bac 2
		+ abs(con so) -> tri tuyet doi
		+ ...
		+ Dat nhung ham co san vao nhung ngan tu, hay con goi la thu vien <math.h>, <stdio.h>...
		+ Hau het la Ham loai 04, Re-use
	- Loai 02 (Customized Functions):
		+ getFactorial()
*/


int main() {
	//Minh hoa ham sqrt() bang cach khai bao thu vien <math.h>
	//double r = sqrt(100);
	printf("Can bac 2 cua %d = %.2lf\n", 100, sqrt(100));

	//Bai co ban re-use: tinh tong can 9 + can 25 + can 64
	double sum = sqrt(9) + sqrt(25) + sqrt(64); //3 + 5 + 8 = 16
	printf("Sum of can: %.2lf\n", sum);

	//Tinh tri tuyet doi -5 -> la 5
	//int r = abs(-5);
	//printf("Tri tuyet doi cua %d la: %d\n", -5, r);
	printf("Tri tuyet doi cua %d la: %d\n", -5, abs(-5));

	return 0;
}
