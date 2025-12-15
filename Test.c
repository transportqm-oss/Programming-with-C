#include<stdio.h>
#include<conio.h>
#include<string.h>

//declara function: inputList
void inputList(int arr[], int n){
	int i; //temp value to compare in for loop
	for(i = 0; i < n; i++){
		printf("please enter value at [%d]: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	//display list number before checking
	printf("the list number before checking: \n");
	for(i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}
}

//declara function: selected sort value
void selectedList(int arr[], int n){
	//declara temp value
	int i;
	int arr02[n], k;
	int j, temp;
	
	//input
	for(k = 0; k < n; k++){
		arr02[k] = arr[k];
	}
	
	//selected sort
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			if(arr02[i] > arr02[j]){
				temp = arr02[i];
				arr02[i] = arr02[j];
				arr02[j] = temp;
			}
		}
	}
	
	//display the list number after checking
	printf("the list number after checking: \n");
	for(i = 0; i < n; i++){
		printf("%d\n", arr02[i]);
	}
}

//declara function: findMinMax
void findMinMax(int arr[], int n){
	//declara min, max
	int i;
	int min = arr[0];
	int max = arr[0];
	
	//find Min, Max
	for(i = 0; i < n; i++){
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
	}
	
	//display
	printf("the minium value is: %d\n", min);
	printf("the maxium value is: %d\n", max);
}

//declara function: countCharacter
void countCharacter(char word[], char *ptr){
	//declara temp value
	int w, count = 0;
	
	//assign pointer to array
	ptr = &word[0];
	
	//counter character
	for(w = 0; w < strlen(word); w++){
		if((*ptr == 'a') || (*ptr == 'e') || (*ptr == 'i') || (*ptr == 'o') || (*ptr == 'u')
		|| (*ptr == 'A') || (*ptr == 'E') || (*ptr == 'I') || (*ptr == 'O') || (*ptr == 'U')){
			count++;
		}
		ptr++;
	}
	
	//display
	printf("the word is: %s\nHave counter number of vowels: %d\n", word, count);
}

/*
	declara function: inputMatrix, displayMatrix, sumofMatrix
*/
	//declara function: inputMatrix
	void inputMatrix(int row, int col, int matrix[row][col]){
		//temp value
		int i, j;
		//input
		printf("please enter value for Matrix: \n");
		for(i = 0; i < row; i++){
			for(j = 0; j < col; j++){
				scanf("%d", &matrix[i][j]); 
			}
		}
	}
	//declara function: sum of two matrix
	void sumofMatrix(int row, int col, int A[row][col], int B[row][col], int Sum[row][col]){
		//declara pointer
		int *pA = &A[0][0];
		int *pB = &B[0][0];
		int *pS = &Sum[0][0];
		
		int total = row * col;
		
		//sum of two matrix
		int i;
		for(i = 0; i < total; i++){
			*(pS + i) = *(pA + i) + *(pB + i);
		}
	}
	//declara function: displayMatrix
	void displayMatrix(int row, int col, int matrix[row][col]){
		//temp value
		int i, j;
		//display
		for(i = 0; i < row; i++){
			for(j = 0; j < col; j++){
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}

//declara function: call by value
int swap_value(int a, int b){
	int temp = a;
	a = b;
	b = temp;
	
	printf("the value before call by value: a = %d, b = %d\n", a, b);
}

//declara function: call by reference
int swap_reference(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	
	printf("the value before call by reference: *a = %d, *b = %d\n", *a, *b);
}

//declara function: call by nestedd
int add(int a, int b){
	return a + b;
}

int square(int n){
	return n * n;
}

int main(){
	printf("=============================================\n");
	//declara array
	int arr[100], n;
	
	//input size of array
	printf("please enter size of array: ");
	scanf("%d", &n);
	
	//call function: inputList
	inputList(arr, n);
	//call function: selectedList
	selectedList(arr, n);
	//call function: findMinMax
	findMinMax(arr, n); 
	
	printf("=============================================\n");

	//declara any word
	char word[10], *ptr;
	
	//input
	printf("please any word: ");
	scanf("%s", word);
	
	//call function: countCharacter
	countCharacter(word, ptr);
	
	printf("=============================================\n");

	//declara row, col
	int row, col;
	//input value of row and column
	printf("please enter value for row and column: \n");
	scanf("%d %d", &row, &col);
	
	//declara matrix
	int A[row][col], B[row][col], Sum[row][col];
	
	//input value for matrix
	printf("enter value for matrix A: \n");
	inputMatrix(row, col, A);
	
	printf("enter value for matrix B: \n");
	inputMatrix(row, col, B);
	
	//sum of two matrix
	sumofMatrix(row, col, A, B, Sum);
	
	//display result
	printf("result of A + B: \n");
	displayMatrix(row, col, Sum);
	
	printf("=============================================\n");
	
	int x1 = 10, y1 = 20;
	swap_value(x1, y1);
	printf("the value after call by value: x1 = %d, y1 = %d\n", x1, y1);
	
	printf("=============================================\n");
	
	int x2 = 10, y2 = 20;
	swap_reference(&x2, &y2);
	printf("the value after call by reference: x2 = %d, y2 = %d\n", x2, y2);
	
	printf("=============================================\n");
	
	int x3, y3;
	printf("please enter value for x3, y3: ");
	scanf("%d %d", &x3, &y3);
	
	int total = square(add(x3, y3));
	
	printf("the total of x3, y3: %d\n", total);
	
	printf("=============================================\n");
		
	return 0;
}
