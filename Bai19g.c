#include <stdio.h>
#include <conio.h>
#include <string.h>

//define structure for inventory item
typedef struct{
	int itemNumber;
	char name[50];
	float rate;
	int quantity;
} Item;

//define function
void inputItems(Item *list, int n){
	int i;
	for(i = 0; i < n; i++){
		printf("\n============= Item[%d] =============\n", i + 1);
		printf("Item Number : ");
		scanf("%d", &list[i].itemNumber);
		printf("Item Name   : ");
		scanf(" %[^\n]", list[i].name);
		printf("Rate        : ");
		scanf("%f", &list[i].rate);
		printf("Quantity    : ");
		scanf("%d", &list[i].quantity);
	}
}

//function to display item name and total price + grand total
void displayItems(Item *list, int n){
	float grandTotal = 0;
	float totalPrice;
	
	printf("\n=====================================================\n");
	printf("%-5s %-20s %-10s %-10s %-12s\n", "NO", "ITEM NAME", "RATE", "QUANTITY", "TOTAL PRICE");
	printf("=====================================================\n");
	
	int i;
	for(i = 0; i < n; i++){
		totalPrice = list[i].rate * list[i].quantity;
		grandTotal += totalPrice;
		
		printf("%-5d %-20s %-10.2f %-10d %-12.2f\n",
			list[i].itemNumber,
			list[i].name,
			list[i].rate,
			list[i].quantity,
			totalPrice);
	}
	
	printf("=====================================================\n");
	printf("%-46s %.2f\n", "GRAND TOTAL VALUE OF INVENTORY:", grandTotal);
	printf("=====================================================\n");
}


int main(){
	//declare value
	int n = 5;
	
	//declare array of 5 items
	Item inventory[n];
	
	printf("=================================\n");
	printf("   INVENTORY MANAGEMENT SYSTEM   \n");
	printf("=================================\n");
	
	//declare function: Input item details
	inputItems(inventory, n);
	
	//display results
	printf("\n============= INVENTORY REPORT =============\n");
	displayItems(inventory, n);
	
	return 0;
}

