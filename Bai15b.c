#include<stdio.h>
#include<conio.h>
#include<string.h>

//declare function for Example 01
int swap_value(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	printf("Trong ham swap_blue: a = %d, b = %d\n", a, b);
}

//declare function for Example 02
int swap_reference(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Trong ham swap_reference: *a = %d, *b = %d\n", *a, *b);
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
	printf("After call function swap_value: x = %d, y = %d\n", x, y);
	
	/*
		Call by Reference: truyen bang tham chieu
		- Ban truyen dia chi (address) cua bien vao ham(thong qua con tro)
		- Ham co the truy cap va thay doi truc tiep bien goc
		Example 02: Call by Reference
	*/
	int x1 = 10, y1 = 20;
	swap_reference(&x1, &y1);
	printf("After call function swap_reference: x1 = %d, y1 = %d", x1, y1);
	//bien x1, y1 da bi thay doi - vi ham nhan dia chi, khong phai ban sao
	
	
	return 0;
}
