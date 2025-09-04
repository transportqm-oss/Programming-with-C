#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
	/*
		Counting the number of vowels in a string using pointers
	*/
//	//declare a character pointer variable
//	char *ptr;
//	//declare a character array and accept value for the same
//	char word[10];
//	printf("Enter a word: \n");
//	scanf("%s", word);
//	//assign the character pointer to the string
//	ptr = &word[0];
//	//traverse through the characters in the word to find out whether they are vowels or not.
//	//In case a vowel is found, increment the count of vowels
//	int i, vowcnt = 0;
//	for(i = 0; i < strlen(word); i++){
//		if((*ptr == 'a') || (*ptr == 'e') || (*ptr == 'i') || (*ptr == 'o') || (*ptr == 'u')
//		|| (*ptr == 'A') || (*ptr == 'E') || (*ptr == 'I') || (*ptr == 'O') || (*ptr == 'U')){
//			vowcnt++;
//		}
//		ptr++;
//	}
//	//dislay the word and the number of vowels in the world
//	printf("The word is: %s \nThe number of vowels in the word is: %d", word, vowcnt);

	/*
		Sort an array in alphabetical order using pointers
	*/
//	char *ptr[5];
//    int i;
//    int j;
//    char cpyptr1[5][10],cpyptr2[5][10];
//    char *temp;
//    for (i=0;i<5;i++)
//    {
//        printf("\n Enter a string :");
//        scanf("%s",cpyptr1[i]);
//        ptr[i]=cpyptr1[i];
//    }
//    for (i=0;i<5;i++)
//        strcpy(cpyptr2[i],cpyptr1[i]);
//    for(i=0;i<4;i++)
//    {
//        for(j=i+1;j<5;j++)
//        {
//            if (strcmp(ptr[i],ptr[j])>0)
//            {
//                temp=ptr[i];
//                ptr[i]=ptr[j];
//                ptr[j]=temp;
//            }
//    	}
//	}
//	
//	printf("\n The Original list is ");
//    for(i=0;i<5;i++)
//    printf("\n%s",cpyptr2[i]);
//    printf("\n The Sorted list is ");
//    for(i=0;i<5;i++)
//    printf("\n%s",ptr[i]);

	/*
		Write C program to concatenate two strings using pointers
	*/
//	//declare three strings
//	char str1[100], str2[50];
//	char *p1, *p2;
//	
//	//input two strings
//	printf("Enter first string: ");
//	scanf("%s", str1);
//	printf("Enter second string: ");
//	scanf("%s", str2);
//	
//	//intilize pointers
//	p1 = str1;
//	p2 = str2;
//	
//	//Move p1 to the end of str1
//	while(*p1 != '\0'){
//		p1++;
//	}
//	
//	//Copy str2 into str1
//	while(*p2 != '\0'){
//		*p1 = *p2;
//		p1++;
//		p2++;
//	}
//	*p1 = '\0'; //terminate the concatened string
//	
//	//Output result
//	printf("Concatened string: %s\n", str1);
	
	return 0;
}
