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
	
	return 0;
}

