#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
	/*
		syntax pointer variable:	
		-> type *name;
		-> 
	*/
//	int var = 500, *ptr_var; /*var is declared as an integer and ptr_var as a pointer pointing to an integer*/
//	ptr_var = &var; 
//	/*stores address of var in ptr_var*/
//	/*Prints value of variable (var) and address where var is stored*/
//	printf("The value %d is stored at address: %u\n", var, &var);
//	/*prints value stored in ptr variable (ptr_var) and address where ptr_var is stored*/
//	printf("The value %u is stored at address: %u\n", ptr_var, &ptr_var);
//	/*Prints value of variable (var) and address where var is stored, using pointer to variable*/
//	printf("The value %d is stored at address: %u\n", *ptr_var, ptr_var);

	/*
		Concept pointer basic
	*/
//	int var = 10; //khai bao bien nguyen va gan gia tri 10
//	int *ptr; //khai bao mot con tro
//	
//	ptr = &var; // gan dia chia cua 'var' vao con tro 'ptr'
//	
//	printf("Gia tri cua bien var: %d\n", var);
//	printf("Dia chi cua bien var: %p\n", &var);
//	printf("Gia tri cua mot con tro ptr: %p\n", ptr);
//	printf("Gia tri tai dia chi ma con tro ptr tro toi: %d\n", *ptr);

	/*
		pointer and single-dimensional array
	*/
//	static int ary[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int i;
//	for(i = 0; i < 10; i++){
//		printf("\n i = %d, ary[i] = %d, *(ary + i) = %d", i, ary[i], *(ary + i));
//		printf("&ary]i = %X, ary + i = %X", &ary[i], ary + i);
//	}
	
	return 0;
}
