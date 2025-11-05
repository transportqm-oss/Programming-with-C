#include<stdio.h>
#include<conio.h>
#include<string.h>


//declare function for example 01
italy(){
	printf("I'm in Italy.\n");
}
brazil(){
	printf("I'm in Brazil.\n");
}
argentina(){
	printf("I'm in Argentina.\n");
}

//declare function for example 02
int calculatesum(int x, int y, int z){
	int d;
	d = x + y + z;
	return d;
}

//declare function for example 03
int square(int n){
	return n * n;
}

//declare function for example 04
int factorial(int n){
	int fact = 1;
	int x;
	for(x = 1; x < n; x++){
		fact *= x; // fact = fact * i : lay gia tri hien tai cua fact, nhan voi bien i, sau do gan lai vao fact
	}
	
	return fact;
}

int main(){
	/*
		Example: function 01
	*/
	printf("I'm in main: \n");
	italy();
	brazil();
	argentina();
	
	/*
		Example: function 02
	*/
	int a, b, c, sum;
	printf("Enter any three numbers: \n");
	scanf("%d %d %d", &a, &b, &c);
	sum = calculatesum(a, b, c);
	printf("Sum = %d\n", sum);
	
	/*
		Example: function 03
		Write a C program accept a number and square the number with the help of a function
		a. Declare a function
		b. Accept the number
		c. Pass the number to the function and return the square of that number
	*/
	int i;
	printf("please enter number: ");
	scanf("%d", &i);
	int result = square(i);
	printf("Square of number is: %d\n", result);
	
	/*
		Write a C program to calculate the factorial of an integer.
	*/
	int num;
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	if(num < 0){
		printf("Factorial is not defined for negative number. \n");
	}else{
		int result01 = factorial(num);
		printf("Factorial of %d is: %d\n", num, result01);
	}
	
	return 0;
}

