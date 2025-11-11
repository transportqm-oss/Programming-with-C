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
	printf("Your name hospital: %s\n", word);
	
	/*
		String function
		1. concatenating string
		2. comparing string
		3. location a character in string
		4. copying one string to another
		5. calculating the length of a string
	*/
	/*
		1. Concatenating string: The 'strcat()' function
		strcat(str1, str2);
		
	*/
	char firstName[15];
	char lastName[15];
	//input value
	printf("enter your firstname: \n");
	scanf("%s", firstName);
	printf("enter your lastname: \n");
	scanf("%s", lastName);
	strcat(firstName, lastName);
	printf("%s\n", firstName);
	/*
		2. Comparing string: The 'strcmp()' function
	*/
	char name1[15] = "Geena";
	char name2[15] = "Dorothy";
	char name3[15] = "Shania";
	char name4[15] = "Geena";
	int i;
	i = strcmp(name1, name2);
	printf("%s compared with %s returned %d\n", name1, name2, i);
	i = strcmp(name1, name3);
	printf("%s compared with %s returned %d\n", name1, name3, i);
	i = strcmp(name1, name4);
	printf("%s compared with %s returned %d\n", name1, name4, i);
	if(strcmp(name1, name2) == 0){
		printf("Strings are equal !\n");
	}else{
		printf("Strings are different !\n");
	}
	/*
		3. location a character in string: The 'strchr()' function
	*/

	return 0;
}
