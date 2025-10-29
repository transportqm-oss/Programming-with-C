#include<stdio.h>
#include<conio.h>
#include<string.h>

//declare function for Example 01
void swap_value(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	printf("Swap_value before call have: a = %d, b = %d\n", a, b);
}

//declare function for Example 02
void swap_reference(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Swap_reference before call have: *a = %d, *b = %d\n", *a, *b);
}
//declare function for Example 03
int square(int n){
	return n * n;
}

int add(int a, int b){
	return a + b;
}

int main(){
	/*
		Call by Value: truyen bang gia tri
		- Khi goi ham, mot ban sao cua gia tri bien duoc truyen vao ham
		- Ham chi lam viec voi ban sao, khong anh huong den bien goc
		Example 01: Call by Value
	*/
	int x = 10, y = 20;
	swap_value(x, y);
	printf("After swap_value have: x = %d, y = %d\n", x, y);	
	
	/*
		Call by Reference: truyen bang tham chieu
		- Ban truyen dia chi (address) cua bien vao ham(thong qua con tro)
		- Ham co the truy cap va thay doi truc tiep bien goc
		Example 02: Call by Reference
	*/
	int x1 = 10, y1 = 20;
	swap_reference(&x1, &y1);
	printf("After swap_reference have: x1 = %d, y1 = %d\n", x1, y1);
	//bien x1, y1 da bi thay doi - vi ham nhan dia chi, khong phai ban sao
	
	/*
		Call by Nesting of Function
		- Goi mot ham ben trong loi goi cua ham khac
		- Ket qua tra ve cua ham duoc dung la tham so cho ham khac
	*/
	int n1 = 2, n2 = 3;
	int result;
	result = square(add(n1, n2));
	printf("Ket qua la: %d\n", result);
	// Goi long nhau: square(add(2, 3))
	
	
	return 0;
}
