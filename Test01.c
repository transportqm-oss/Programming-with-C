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
	
	printf("%s\n", message);
	
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
	
	printf("\nthe miniumvalue is: %d\n", min);
	printf("the maxiumvalue is: %d\n", max);
}

//-----------------------------------------------------//
//declare function: countVowel
int countVowel(char str[]){
	int i, count = 0;
	
	for(i = 0; i < str[i] != '\0'; i++){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
		|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
			count++;
		}
	}
	
	return count;
}

//-----------------------------------------------------//
//declare function: inputMatrix
void inputMatrix(int row, int col, int matrix[row][col]){
	int i, j;
	
	printf("please enter value for the matrix: \n");
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
}

//declare function: sumMatrix
void sumMatrix(int row, int col, int A[row][col], int B[row][col], int Sum[row][col]){
	int *pA = &A[0][0];
	int *pB = &B[0][0];
	int *pS = &Sum[0][0];
	int total = row * col;
	
	int i;
	for(i = 0; i < total; i++){
		*(pS + i) = *(pA + i) + *(pB + i);
	}
}

//declare fuction: displayMatrix
void displayMatrix(int row, int col, int matrix[row][col]){
	int i, j;
	
	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

//-----------------------------------------------------//
//declare function: call by value
void swap_value(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	
	printf("The list value before call by value: a = %d, b = %d\n", a, b);
}

//-----------------------------------------------------//
//declare function: call by reference
void swap_reference(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	
	printf("The list value before call by valueL *a = %d, *b = %d\n", *a, *b);
}

int main(){
	printf("-------------------!!!-------------------\n");
	/*
		input value for array, sort list array and find min max
	*/
	//declare size of array and array
	int n;
	int arr[100];
	//input
	printf("please enter value size of array:");
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
	//declare array
	char word[10];
	//input
	printf("please enter a string: ");
	scanf("%s", word);
	
	//call function: countVowel
	int result = countVowel(word);
	
	//display result
	printf("the word is: %s\nHave number of vowel in word: %d\n", word, result);

	printf("-------------------!!!-------------------\n");
	/*
		input two 02 matrix and show result sum of two matrices
	*/
	//declare value for row and column
	int row, col;
	//input
	printf("please enter number for row and column: \n");
	scanf("%d %d", &row, &col);
	
	//declare two matrix
	int A[row][col], B[row][col], Sum[row][col];
	
	//input value for matrix
	printf("please enter value for Matrix A: \n");
	inputMatrix(row, col, A);
	
	printf("please enter value for Matrix B: \n");
	inputMatrix(row, col, B);
	
	//sum of two matrices
	sumMatrix(row, col, A, B, Sum);
	
	//display
	printf("\nResult (A + B): \n");
	displayMatrix(row, col, Sum);
	
	printf("-------------------!!!-------------------\n");
	/*
		Example: call by value
	*/
	//declare value
	int x1 = 10, y1 = 20;
	swap_value(x1, y1);
	printf("The list number after call by value: x1 = %d, y1 = %d\n", x1, y1);
	
	printf("-------------------!!!-------------------\n");
	/*
		Example: call by reference
	*/
	//declare value
	int x2 = 10, y2 = 20;
	swap_reference(&x2, &y2);
	printf("The list number after call by reference: x2 = %d, y2 = %d\n", x2, y2);
	
	printf("-------------------!!!-------------------\n");
	
	return 0;
}


