#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
	/*
		String variables and Constants
	*/
	char str[10] = "WELL DONE"; //str is a characer array variable, hold maxium of 10 characters
	//Pointer to strings
	char *ptr = "WELLCOME";
	//String I/O operations
	
	/*
		String I/O operations
	*/
	char name[20]; //name is declared as a single dimensional character array
	puts("Enter your name:"); //display a mesage
	gets(name); //accept the input
	puts("Hi there:");
	puts(name); //display the input
	//getch();
	
	char word[10];
	printf("Enter your name hospital: ");
	scanf("%s", word);
	printf("Your name hospital: %s", word);

	return 0;
}
