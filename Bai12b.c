#include<stdio.h>
#include<conio.h>
#include<string.h>
void makePlural(char *word, char *plural){
	int len = strlen(word);
		
	//copy original word into plural
	strcpy(plural, word);
		
	//basic pluralization rule (just add 's')
	if (word[len - 1] == 'y' && !(word[len - 2] == 'a' || word[len - 2] == 'e' || word[len - 2] == 'i' || word[len - 2] == 'o' || word[len - 2] == 'u')) {
    //Replace 'y' with "ies"
    plural[len - 1] = '\0';
    strcat(plural, "ies");
    } else if (word[len - 1] == 's' || word[len - 1] == 'x' || (len >= 2 && word[len - 2] == 'c' && word[len - 1] == 'h') || (len >= 2 && word[len - 2] == 's' && word[len - 1] == 'h')) {
    // Words ending in s, x, ch, sh ? add "es"
    strcat(plural, "es");
    } else {
    // Default ? add "s"
    strcat(plural, "s");
    }
}

int main(){
	/*
		Write a	program	to accept a string and find out if it is a palindrome.
	*/
//	char str[100], cleaned[100];
//	int i, j = 0, len, isPalindrome;
//	
//	//Input String
//	printf("Enter a String: ");
//	fgets(str, sizeof(str), stdin);
//	
//	//Remove newline character if exits
//	str[strcspn(str, "\n")] = '\0';
//	
//	//Clean string: remove none-alphanumeric and make lowercase
//	for(i = 0; str[i] != '0'; i++){
//		if(isalnum((unsigned char)str[i])){
//			cleaned[j++] = tolower((unsigned char)str[i]);
//		}
//	}
//	cleaned[j] = '\0';
//	
//	//check palindrome
//	len = strlen(cleaned);
//    for (i = 0; i < len / 2; i++) {
//        if (cleaned[i] != cleaned[len - i - 1]) {
//            isPalindrome = 0;
//            break;
//        }
//    }
//    
//    // Output result
//    if (isPalindrome)
//        printf("The string is a palindrome.\n");
//    else
//        printf("The string is not a palindrome.\n");

	/*
		Write a program using pointer to strings that accepts the name of an animal and a bird and 
		returns the names in plural.
	*/
	char animal[50], bird[50];
	char animalPlural[60], birdPlural[60];
	
	//input names
	printf("Enter the name of an animal: ");
	scanf("%s", animal);
	
	printf("Enter the name of bird: ");
	scanf("%s", bird);
	
	//make plurals
	makePlural(animal, animalPlural);
	makePlural(bird, birdPlural);
	
	//Output results
	printf("Plural of %s is %s\n", animal, animalPlural);
	printf("Plural of %s is %s\n", bird, birdPlural);
	
	return 0;
}
