#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>


// khai bao 01 bien toan cuc
int count = 0;
// ham increase minh hoa cho bien toan cuc
int increase(){
	count++; //gia tri nay co the duoc truy cap tu moi ham
}

// ham co 2 tham so: a va b
int add(int a, int b){
	return a + b;
}

int main(){
	/*
		Syntax of a function:
		type_specifier function_name (arguments)
		{
			body of the function
			return statement
		}
	*/
	
	/*
		Function Prototypes:
		char abc();
			or
		char acb(int x, int y);
	*/
	
	/*
		Function Prototype definition:
		type function_name(type parm_name1, tyep parm_name2,...., type_nameN);
	*/
	
	/*
		Declare Local Variable:
		Void b1k1(void)
		{
			char ch;
			ch = 'a';
			.
			.
		}
		Void b1k2(void)
		{
			char ch;
			ch = 'b';
			.
			.
		}
		Void b1k3(void)
		{
			int t;
			t = 1;
			if(t > 5)
			{
				char ch;
				.
				.
			}
			.
			.
		}
	*/
	
	/*
		void b1k1(void)
		{
			int len;
			len = 1;
			char ch; //This will cause an error
			ch = 'a';
			.
			.
		}
	*/
	
	/*
		Formal Parameter
		b1k1(char ch, int i)
		{
			if(i>5)
				ch = 'a';
			else
				i = i + 1;
			return;
		}
	*/
	
	/*
		Syntax for Storage Classes
			storage_specifier type var_name
	*/
	
	/*
		Example 01: Define parameter and argument
	*/
	int x = 5;
	int y = 10;
	int result = add(x, y);	// x va y la doi so, duoc tham chieu tuong ung voi a va b
	printf("Sumf of number: %d\n", result);
	
	/*
		Example 02: Define Global variable
	*/
	printf("First value of global variable: %d\n", count);
	increase();
	printf("Second value of global variable: %d\n", count);
	
	/*
		Define: Exterm Variable
		int count = 10; // dinh nghia bien, trinh bien dich se tao vung bo nho thuc su cho bien
		extern int count; // khai bao bien, chi bao rang bien nay da duoc dinh nghia o 01 noi khac
	*/
	
	/*
		Example 02: Compare automatic variable with static variable in C
	*/
	incre();
	incre();
	incre();
	
	incre01();
	incre01();
	incre01();
	
	/*
		Example 03: Call by Value
	*/
	int n1, n2, n3;
	n1 = n2 = n3 = 0;
	
	printf("Enter 1st integer: \n");
	scanf("%d", &n1);
	printf("Enter 2nd integer: \n");
	scanf("%d", &n2);
	
	n3 = adder(n1, n2);
	
	printf("n1 & n2 in main() are: %d, %d\n", n1, n2);
	printf("n3 in main() is: %d", n3);
	//n3 gives the addtion of n1 and n2
	
	return 0;
}

int adder(int n1, int n2){
	int n3;
	n3 = n1 + n2;
	n1 *= n1;
	n2 += 5;
	printf("n1 & n2 within adder function are: %d, %d\n", n1, n2);
	printf("n3 within adder function is: %d\n", n3);
	return (n3);
}

int incre(){
	char var = 65; // var is automatic variable
	printf("The character stored in var is: %c\n", var++);
}

int incre01(){
	static char var = 65; // var is static variable
	printf("The character stored in var is: %c\n", var++);
}

