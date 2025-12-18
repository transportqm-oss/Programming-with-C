#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

//declara function: Convert a character array to upper case using functions
//void uppername(char name_arr[]){
//	int x;
//	for(x = 0; name_arr[x] != '\0'; x++){
//		if(name_arr[x] >= 97 && name_arr[x] <= 122){
//			name_arr[x] = name_arr[x] - 32;
//		}
//	}
//}

//declara function: Convert a character array to upper case using functions 01
//void uppername(char name_arr[]){
//	int x;
//	
//	for(x = 0; name_arr[x] != '\0'; x++){
//		name_arr[x] = toupper(name_arr[x]);
//	}
//}

//declara function: counter
//int countCharacter(char str[], char ch){
//	int count = 0;
//	int i;
//	
//	//check each character
//	for(i = 0; str[i] != '\0'; i++){
//		if(str[i] == ch){
//			count++;
//		}
//	}
//	
//	return count; //return the count to main()
//}

//declara function: addPrefix
void addPrefix(char name[5][50], char prefix[]);

void addPrefix(char name[5][50], char prefix[]){
	int i;
	char temp[50];
	
	for(i = 0; i < 5; i++){
		strcpy(temp, name[i]);		//save original name
		strcpy(name[i], prefix);    //copy prefix
		strcat(name[i], temp);      //add original name after prefix
	}
}

int main(){
	/*
		Sorting strings using library functions
	*/
//	int i, j;
//	char str_arr[5][20], str[20];
//	
//	for(i = 0; i < 5; i++){
//		printf("Enter string %d: ", i + 1);
//		scanf("%s", str_arr[i]);
//	}
//	
//	for(i = 0; i < 4; i++){
//		for(j = i + 1; j < 5; j++){
//			if(strlen(str_arr[i]) < strlen(str_arr[j])){
//				strcpy(str, str_arr[i]);
//				strcpy(str_arr[i], str_arr[j]);
//				strcpy(str_arr[j], str);
//			}
//		}
//	}
//	
//	printf("The strings in descending order of length are: \n");
//	for(i = 0; i < 5; i++){
//		printf("%s\n", str_arr[i]);
//	}
	
	/*
		Convert a character array to upper case using functions
	*/
//	int i;
//	char names[5][20];
//	
//	void uppername(char name_arr[]);
//	
//	for(i = 0; i < 5; i++){
//		printf("please enter string [%d]: ", i + 1);
//		scanf("%s", names[i]);
//	}
//	for(i = 0; i < 5; i++){
//		uppername(names[i]);
//		printf("New String [%d]: %s\n", i + 1, names[i]);
//	}

	/*
		Convert a character array to upper case using functions
		Using: library <ctype.h>
	*/
//	char names[5][20];
//	int i;
//	//input
//	for(i = 0; i < 5; i++){
//		printf("Enter string [%d]: ", i + 1);
//		scanf("%19s", names[i]);
//	}
//	//display list string after call function uppername
//	for(i = 0; i < 5; i++){
//		uppername(names[i]);
//		printf("New String [%d]: %s\n", i + 1, names[i]);
//	}

	/*
		Write a C program to display the number of times a specified character occurs in a string.
		Set a loop to perform the operation 5 times	
	*/
	//declare array and variable
//	char str[100];
//	char ch;
//	int i, result;
//	
//	//declara loop 05 times
//	for(i = 0; i < 5; i++){
//		printf("\n---- Operation %d ----\n", i + 1);
//		
//		//accept string
//		printf("Enter a string: ");
//		scanf("%s", str);
//		
//		//accept character
//		printf("Enter a character to search for: ");
//		scanf(" %c", &ch); //space before %c ignores new line
//		
//		//call the function
//		result = countCharacter(str, ch);
//		
//		//display the result
//		printf("The character '%c' appears  %d times in \"%s\".\n", ch, result, str);
//	}

	/*
		Write a C Program to accept 5 names and a prefix. Insert the prefix at the beginning of each
		name in the array. Display the modified names.
		Note: One prefix apply to all.
	*/
	//declara array and character
	char name[5][50];
	char prefix[20];
	int i;
	
	//input 05 names
	for(i = 0; i < 5; i++){
		printf("Enter name at [%d]: ", i + 1);
		scanf("%s", name[i]);
	}
	
	//input prefix
	printf("Enter prefix: ");
	scanf("%s", prefix);
	
	//call function
	addPrefix(name, prefix);
	
	//display modified names
	printf("\nNames after adding prefix: \n");
	for(i = 0; i < 5; i++){
		printf("%s\n", name[i]);
	}
	
	return 0;
}
