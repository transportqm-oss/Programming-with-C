#include<stdio.h>
#include<string.h>
#include<conio.h>

/*
	Write a C program to store 5 lengths in a structure array. The lengths should be in the form 
	of yards, feet and inches. Sort and display the lengths.
*/

/*
	#include / #define
        |
	typedef struct { yards, feet, inches }  Length
        |
	function prototypes
        |
	main() -> menu loop -> call function
        |
	inputLengths()      -> input 5 length
        |
	displayLengths()    -> display length
        |
	convertToInches()   -> convert inches to compare
        |
	sortLengths()       -> sort value
*/

#define MAX 5 //value number limit = 5

//a. Define structure
typedef struct{
	int yards;
	int feet;
	int inches;
} Length;

//b. Declare prototype
void inputLength(Length list[], int n);
void displayLength(Length list[], int n);
int convertToInches(Length e);
void sortLengths(Length list[], int n);
void displayHeader();

int main(){
	Length lengths[MAX];
	int choice;
	
	do{
		printf("\n==========================================\n");
        printf("         LENGTH MANAGEMENT SYSTEM        \n");
        printf("==========================================\n");
        printf("  1. Enter lengths\n");
        printf("  2. Display lengths (unsorted)\n");
        printf("  3. Sort and display lengths\n");
        printf("  4. Exit\n");
        printf("==========================================\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1:
        		inputLength(lengths, MAX);
        		break;
        	case 2:
        		printf("\n  --- Original List ---");
        		displayLength(lengths, MAX);
        		break;
        	case 3:
        		sortLengths(lengths, MAX);
                printf("\n  --- Sorted List (Ascending) ---");
                displayLength(lengths, MAX);
        		break;
        	case 4:
        		printf("\n  Goodbye!\n\n");
        		break;
        	default:
        		printf("\n  [!] Invalid choice. Enter 01 to 04.\n");
		}
	} while(choice != 4);
	
	return 0;
}

//Helper: display Header
void displayHeader(){
	printf("\n  %-6s %-10s %-10s %-10s %-15s\n", "NO.", "YARDS", "FEET", "INCHES", "TOTAL(inches)");
	printf("  %-6s %-10s %-10s %-10s %-15s\n",
           "------", "----------", "----------",
           "----------", "---------------");
}

//c. declare function:  convertToInches()
int convertToInches(Length e){
	return (e.yards * 36) + (e.feet * 12) + e.inches;
}

//d. declare function: inputLength()
void inputLength(Length list[], int n){
	int i;
	
	printf("\n  Enter %d lengths (yards, feet, inches): \n", n);
	
	for(i = 0; i < n; i++){
		printf("\n  --- Length [%d] ---\n", i + 1);
		
		//input yards
		do{
			printf("  Yards  : ");
			scanf("%d", &list[i].yards);
			if(list[i].yards < 0){
				printf("  [!] Yards cannot be negative.\n");
			}
		} while(list[i].yards < 0);
		
		//input feet (0 - 2, because 03 feet = 1 yard)
		do{
			printf("  Feet   : ");
			scanf("%d", &list[i].feet);
			if(list[i].feet < 0 || list[i].feet > 2){
				printf("  [!] Feet must be between 0 and 2.\n");
			}
		} while(list[i].feet < 0 || list[i].feet > 2);
		
		//input inches (0 - 11, because 12 inches = 1 foot)
		do{
			printf("  Inches : ");
			scanf("%d", &list[i].inches);
			if(list[i].inches < 0 || list[i].inches > 11){
				printf("  [!] Inches must be between 0 and 11.\n");
			}
		} while(list[i].inches < 0 || list[i].inches > 11);
	}
	
	printf("\n  [OK] %d lengths entered successfully!\n.", n);
}

//e. declare function: displayLength()
void displayLength(Length list[], int n){
	int i;
	
	displayHeader();
	
	for(i = 0; i < n; i++){
		printf("  %-6d %-10d %-10d %-10d %-15d\n",
			i + 1,
			list[i].yards,
			list[i].feet,
			list[i].inches,
			convertToInches(list[i])
		);
	}
}

//f. declare function: sortLength()
void sortLengths(Length list[], int n){
	int i, j;
	Length temp;
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(convertToInches(list[j]) > convertToInches(list[j + 1])){
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
