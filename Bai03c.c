#include <stdio.h>
#include <stdlib.h>

/*
	Viet doan code theo style ham tinh binh phuong cua 01 con so
	IPO
	I: 01 con so x
	P: x * x
	O: y = x * x
*/

int fVersion04(int x); //100% tuong thich ham toan hoc: y = f(x) = x^2
//y	f			x	   //chi con thieu phan binh phuong
                       //lat hoi o duoi ta lam not

int main() {
	//xai ham co tra ve gia tri, van goi ten ra
	//int result = fVersion04(5);
	//printf("Result: %d\n", result);

	//printf("Result: %d\n", fVersion04(10));

	//ban muon linh hoat value dau vao, thi phai nhap vao tu ban phm
	int n;
	printf("Input a number to get ^2: ");
	scanf("%d", &n);
	//bien n duoc pass-chuyen cho ham == TRUYEN THAI Y
	printf("Result: %d\n", fVersion04(n));

	return 0;
}

int fVersion04(int x) {
	//coi nhu x da co roi, quy uoc ham nhan vao x, cu gia bao x se co sau
	//cu xu ly tren x, tuong duong voi tuong lai se xu li tren value that
	//xu li tren cong thuc ching la xu li tren value that sau nay
	//KHI XAI HAM THI PHAI DUA X VAO, Y CHANG XAI MAY SAY SINH TO

	//int y = x * x; //may dua x, tao binh phuong, nhan ket qua di
	//return y; //nem ket qua

	return x * x; //can value de gan cho ten ham, 02 con so nhan voi nhau la 01 value
}
