#include<stdio.h>
#include<conio.h>
#include<string.h>

//declare function for Example 01
void swap_value(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	printf("Value before call swap_value: a = %d, b = %d\n", a, b);
}

//declare function for Example 02
void swap_reference(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Value before call swap_reference: *a = %d, *b = %d\n", *a, *b);
}

//declare function for Example 03
int square(int n){
	return n * n;
}

int add(int a, int b){
	return a + b;
}

//declare function for Example 04 + Example 04(extension)
int add01(int a, int b){
	return a + b;
}
int multiply(int a, int b){
	return a * b;
}
// Ham nhan con tro ham lam tham so
void calculate(int x, int y, int(*operation)(int, int)){
	printf("Ket qua la: %d\n", operation(x, y));
}

//declare function for Example 04(extension01)
int add02(int a, int b){
	return a + b;
}
int sub02(int a, int b){
	return a - b;
}
int mul02(int a, int b){
	return a * b;
}
int divide(int a, int b){
	return b!= 0 ? a / b : 0;
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
	printf("Value after call swap_value: x = %d, y = %d\n", x, y);
	
	/*
		Call by Reference: truyen bang tham chieu
		- Ban truyen dia chi (address) cua bien vao ham(thong qua con tro)
		- Ham co the truy cap va thay doi truc tiep bien goc
		Example 02: Call by Reference
	*/
	int x1 = 10, y1 = 20;
	swap_reference(&x1, &y1);
	printf("Value after call swap_reference: x1 = %d, y1 = %d\n", x1, y1);
	
	/*
		Call by Nesting of Function
		- Goi mot ham ben trong loi goi cua ham khac
		- Ket qua tra ve cua ham duoc dung la tham so cho ham khac
	*/
	int n1, n2;
	printf("insert n1: ");
	scanf("%d", &n1);
	printf("insert n2: ");
	scanf("%d", &n2);
	int result;
	result = square(add(n1, n2));
	printf("Result: %d\n", result);
	
	/*
		Call Pointers to Functions (con tro ham):
		- La mot bien con tro dung de luu dia chi cua mot ham trong C
		- Sau do ta co the goi ham thong qua con tro nay nhu goi ham binh thuong
		+ Trong C, moi ham deu co mot dia chi trong bo nho
		+ Con tro ham giup ta luu dia chi do vao mot bien
		+ Nho vay, ta co the goi ham thong qua con tro, truyen ham lam doi so cho ham khac, hoac chay
		- Syntax :
			return_type(*pointer_name)(paremeter_type)
			+ return_type: kieu du lieu tra ve cua ham
			+ *pointer_name: ten con tro ham
			+ parameter_type: danh sach kieu tham so cua ham
	*/
	/*
		Example 04: call pointer to function
	*/
	// Khai bao con tro ham den ham co dang int(int, int)
	int (*ptr)(int, int);
	// Gan dia chi cua ham add01 cho con tro (*ptr)
	ptr = add01; // hoac ptr = &add01;
	// Goi ham thong qua con tro
	int result01 = ptr(2, 3); // tuong duong voi add01(2, 3)
	// In ket qua
	printf("Result01: %d\n", result01);
	
	/*
		Example 04: call Pointer to Function (extension)
	*/
	calculate(4, 5, add01);	// truyen ham add01
	calculate(4, 5, multiply); // truyen ham multiply
	
	/*
		Example 04: call Pointer to Function (extension01)
	*/
	int choice, x3, y3;
	int(*operation[4])(int, int) = {add02, sub02, mul02, divide};
	
	printf("Nhap 02 so: ");
	scanf("%d %d", &x3, &y3);
	
	printf("Chon phep tinh (0: +; 1: -; 2: *; 3: /): ");
	scanf("%d", &choice);
	
	if(choice >= 0 && choice < 4){
		printf("Ket qua la: %d\n", operation[choice](x3, y3));
	}else{
		printf("Lua chon khong hop le\n");
	}
	
	return 0;
}
