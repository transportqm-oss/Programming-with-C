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
void uppername(char name_arr[]){
	int x;
	
	for(x = 0; name_arr[x] != '\0'; x++){
		name_arr[x] = toupper(name_arr[x]);
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
	char names[5][20];
	int i;
	//input
	for(i = 0; i < 5; i++){
		printf("Enter string [%d]: ", i + 1);
		scanf("%19s", names[i]);
	}
	//display list string after call function uppername
	for(i = 0; i < 5; i++){
		uppername(names[i]);
		printf("New String [%d]: %s\n", i + 1, names[i]);
	}
	
	return 0;
}
