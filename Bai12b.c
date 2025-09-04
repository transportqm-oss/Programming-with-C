#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
	/*
		Write a	program	to accept a string and find out if it is a palindrome.
	*/
	char str[100], cleaned[100];
	int i, j = 0, len, isPalindrome;
	
	//Input String
	printf("Enter a String: ");
	fgets(str, sizeof(str), stdin);
	
	//Remove newline character if exits
	str[strcspn(str, "\n")] = '\0';
	
	//Clean string: remove none-alphanumeric and make lowercase
	for(i = 0; str[i] != '0'; i++){
		if(isalnum((unsigned char)str[i])){
			cleaned[j++] = tolower((unsigned char)str[i]);
		}
	}
	cleaned[j] = '\0';
	
	//check palindrome
	len = strlen(cleaned);
    for (i = 0; i < len / 2; i++) {
        if (cleaned[i] != cleaned[len - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }
    
    // Output result
    if (isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
	
	return 0;
}
