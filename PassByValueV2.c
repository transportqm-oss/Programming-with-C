#include <stdio.h>
#include <stdlib.h>

/*
	+ Hieu cach dua/truyen gia tri /dau vao cho ham
*/

void f(int x);

int main() {
	//f(5); //5 gan vao x o ham, goi la x ham = 5, pass cho ham

	int x = 10; //dung chuan scanf()
	//Hoi nhan x main() o dau
	printf("in main() x address is %u and value is %d\n", &x, x);
	f(x);
	printf("after calling f(), in main() x address is %u and value is %d\n", &x, x);

	return 0;
}

void f(int x) {
	printf("in f() x address is %u and value is %d\n", &x, x);
	x = 25; //eo choi x = 10 dua xuong, chu dong doi x = gia tri moi
	int y = x * x;
	printf("y = f(%d) = %d\n", x, y); //y = f(5) = 25
	printf("after updating x; in f() x address is %u and value is %d\n", &x, x);
	//return y; //dep y cung duoc, return x * x; //dinh luat bac cau value
}
