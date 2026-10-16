#include <stdio.h>
#include <stdlib.h>

/*
	+ Hieu cach dua/truyen gia tri /dau vao cho ham
*/

void f(int x);

int main() {
	f(5); //5 gan vao x o ham, goi la x ham = 5, pass cho ham

	int n = 10; //dung chuan scanf()
	f(n);

	return 0;
}

void f(int x) {
	int y = x * x;
	printf("y = f(%d) = %d\n", x, y); //y = f(5) = 25
	//return y; //dep y cung duoc, return x * x; //dinh luat bac cau value
}
