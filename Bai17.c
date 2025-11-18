#include<stdio.h>
#include<conio.h>
#include<string.h>

//declare function input value - Passing Arrays to Functions
void inputArray(int arr[], int *size){
	printf("please enter value size of array: \n");
	scanf("%d", size);
	
	int i;
	for(i = 0; i < *size; i++){
		printf("please enter value at [%d]: ", i);
		scanf("%d", &arr[i]);
	}
}

//declare function print value - Passing Arrays to Functions
void printArray(int arr[], int size){
	int i;
	printf("the list number of array: \n");
	for(i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
}

//declare function sumArray - Passing Arrays to Functions
int sumArray(int arr[], int size){
	int i, sum = 0;
	for(i = 0; i < size; i++){
		sum += arr[i];
	}
	return sum;
}


int main(){	
	/*
		String variables and Constants
	*/
//	char str[10] = "WELL DONE"; //str is a characer array variable, hold maxium of 10 characters
//	//Pointer to strings
//	char *ptr = "WELLCOME";
//	//String I/O operations
	
	/*
		String I/O operations
	*/
//	char name[20]; //name is declared as a single dimensional character array
//	puts("Enter your name:"); //display a mesage
//	gets(name); //accept the input
//	puts("Hi there:");
//	puts(name); //display the input
//	//getch();
	
//	char word[10];
//	printf("Enter your name hospital: ");
//	scanf("%s", word);
//	printf("Your name hospital: %s\n", word);
	
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
//	char firstName[15];
//	char lastName[15];
//	//input value
//	printf("enter your firstname: \n");
//	scanf("%s", firstName);
//	printf("enter your lastname: \n");
//	scanf("%s", lastName);
//	strcat(firstName, lastName);
//	printf("%s\n", firstName);
	
	/*
		2. Comparing string: The 'strcmp()' function
	*/
//	char name1[15] = "Geena";
//	char name2[15] = "Dorothy";
//	char name3[15] = "Shania";
//	char name4[15] = "Geena";
//	int i;
//	i = strcmp(name1, name2);
//	printf("%s compared with %s returned %d\n", name1, name2, i);
//	i = strcmp(name1, name3);
//	printf("%s compared with %s returned %d\n", name1, name3, i);
//	i = strcmp(name1, name4);
//	printf("%s compared with %s returned %d\n", name1, name4, i);
//	if(strcmp(name1, name2) == 0){
//		printf("Strings are equal !\n");
//	}else{
//		printf("Strings are different !\n");
//	}
	
	/*
		3. location a character in string: The 'strchr()' function
	*/
//	char str1[15] = "New York";
//	char str2[15] = "Washington";
//	char chr = 'a';
//	char *loc;
	
	//TH1
//	loc = strchr(str1, chr); //check for the occurence of the character value hold by chr in the first city name
//	if(loc != NULL){
//		printf("%c occurs in %s\n", chr, str1);
//	}else{
//		printf("%c does not occur in %s\n", chr, str1);
//	}
//	//TH2
//	loc = strchr(str2, chr);
//	if(loc != NULL){
//		printf("%c occurs in %s\n", chr, str2);
//	}else{
//		printf("%c does not occur in %s\n", chr, str2);
//	}
	
	/*
		4. copying one string to another: The 'strcpy()' function
	*/
//	char hotelname1[15] = "Sea View";
//	char hotelname2[15] = "Sea Link";
//	printf("The old name hotel is: %s\n", hotelname1);
//	strcpy(hotelname1, hotelname2); //change the hotel from hotel2 to hotel1
//	printf("The new name hotel is: %s\n", hotelname1);
	
	/*
		5. calculating the length of a string: The 'strlen()' function
	*/
//	char compname[20] = "Microsoft";
//	int len, ctr;
//	len = strlen(compname);
//	for(ctr = 0; ctr < len; ctr++){
//		printf("%c * ", compname[ctr]);
//	}
	
//	char city01[15] = "HANOI";
//	char city02[15] = "HAIPHONG";
//	char city03[15] = "VINH";
//	int len1 = strlen(city01);
//	int len2 = strlen(city02);
//	int len3 = strlen(city03);
//	printf("%s city have string length: %d\n", city01, len1);
//	printf("%s city have string length: %d\n", city02, len2);
//	printf("%s city have string length: %d\n", city03, len3);
//	
//	char city[20];
//	printf("Please enter your name city: \n");
//	scanf("%s", city);
//	int len4 = strlen(city);
//	printf("%s city have string length: %d\n", city, len4);
	
	/*
		Passing Arrays to Functions
	*/
	int arr[100];
	int size;
	
	inputArray(arr, &size);
	printArray(arr, size);
	
	int result = sumArray(arr, size);
	printf("Sum of array: %d\n", result);


	/*
		Passing Arrays to Functions 02
	*/
	
	
	return 0;
}
