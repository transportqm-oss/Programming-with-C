#include<stdio.h>
#include<string.h>
#include<conio.h>

//-----------------------------------------------------//
//declare function: inputList
void inputList(int arr[], int n){
	int i;
	
	for(i = 0; i < n; i++){
		printf("please enter value at [%d]: ", i + 1);
		scanf("%d", &arr[i]);
	}
}

//declare function: displayList
void displayList(int arr[], int n, char message[]){
	int i;
	
	printf("%s", message);
	for(i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}
}

//declare function: sortList
void sortList(int arr[], int n){
	int i, j, temp;
	
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//declare function: findMinMax
void findMinMax(int arr[], int n){
	int i;
	int min = arr[0];
	int max = arr[0];
	
	for(i = 0; i < n; i++){
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
	}
	
	printf("\nthe minium value is: %d\n", min);
	printf("the maxium value is: %d\n", max);
}

//-----------------------------------------------------//
//declara function: countVowel
int countVowel(char str[]){
	int i, count = 0;
	
	for(i = 0; str[i] != '\0'; i++){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
		|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
			count++;
		}
	}
	
	return count;
}

int main(){
	printf("-------------------!!!-------------------\n");
	/*
		input value for array, sort list array and find min max
	*/
	//declara size array, array
	int n;
	int arr[100];
	//input
	printf("please enter size of array: ");
	scanf("%d", &n);
	
	//call function: inputList
	inputList(arr, n);
	//call function: displayList
	displayList(arr, n, "\nthe list number before checking: \n");
	//call function: sortList
	sortList(arr, n);
	//call function: displayList
	displayList(arr, n, "\nthe list number after checking: \n");
	//call function: findMinMax
	findMinMax(arr, n);
	
	printf("-------------------!!!-------------------\n");
	/*
		input any word, count number vowel in word
	*/
	//declara array
	char word[10];
	//input
	printf("please enter a string: ");
	scanf("%s", word);
	
	//call function: countVowel
	int result = countVowel(word);
	
	//display result
	printf("the word is: %s\nHave counter number of vowel is: %d\n", word, result);
	
	printf("-------------------!!!-------------------\n");
	
	return 0;
}


