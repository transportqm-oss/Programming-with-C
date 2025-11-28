#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
	/*
		Sorting strings using library functions
	*/
	int i, j;
	char str_arr[5][20], str[20];
	
	for(i = 0; i < 5; i++){
		printf("Enter string %d: ", i + 1);
		scanf("%s", str_arr[i]);
	}
	
	for(i = 0; i < 4; i++){
		for(j = i + 1; j < 5; j++){
			if(strlen(str_arr[i]) < strlen(str_arr[j])){
				strcpy(str, str_arr[i]);
				strcpy(str_arr[i], str_arr[j]);
				strcpy(str_arr[j], str);
			}
		}
	}
	
	printf("The strings in descending order of length are: \n");
	for(i = 0; i < 5; i++){
		printf("%s\n", str_arr[i]);
	}
	
	/*
		Convert a character array to upper case using functions
	*/
	
	return 0;
}
