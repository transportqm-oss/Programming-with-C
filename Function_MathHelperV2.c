#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const float PI = 3.14; //bien toan cuc, global variable, bat cu ham nao cung su dung duoc

//Tu duy viet ham bai MathHelper
//IPO:
//I: choice = user chon gi thi moi tinh tiep duoc

//Define function: printMenu()
void printMenu();

//Define function: computeDiskArea()
void computeDiskArea();

int main() {
	int choice; //su lua chon option

	//CHUA BANG 05 THI KHONG CHO THOAT, CON DUNG THI CON LAM, NEU KHAC 5 THI CON LAM
	do {
		printMenu();
		printf("Please choose 1..5: ");
		scanf("%d", &choice);

		switch(choice) { //if choice la may thi lam gi ???
			case 1:
				computeDiskArea();
				break;
			case 2:
				printf("You choose to compute the rectangle area\n");
				break;
			case 3:
				printf("You choose to compute the triangle area\n");
				break;
			case 4:
				printf("You choose to compute the circle area\n");
				break;
			case 5:
				printf("Bye bye. See you next time\n");
				break;
			default:
				printf("Your choice is valid. Please re-choice. Thank you !!!\n");
		}

	} while(choice != 5); //chua chon 5 ha, lam tiep di, in menu

	return 0;
}

//Call function: printMenu()
void printMenu() {
	printf("\n*===================================================*\n");
	printf("* Welcome to Math Helper program.                   *\n");
	printf("* Choose the following functions to play with:      *\n");
	printf("* 1. Compute the disk area.                         *\n");
	printf("* 2. Compute the rectangle area.                    *\n");
	printf("* 3. Compute the triangle area.                     *\n");
	printf("* 4. Compute the circle area.                       *\n");
	//...
	printf("* 5. Quit.                                          *\n");
}

//Call function: computeDiskArea()
void computeDiskArea() {
	float radius, area;
	printf("You choose to compute the disk area\n");
	printf("Please input a radius(>0): ");
	scanf("%f", &radius);
	//area = 3.14 * radius * radius;
	//area = 3.14 * pow(radius, 2); //ham tinh dien tich bang thu vien math.h
	//area = PI * pow(radius, 2);
	//printf("The disk with r = %.2f has the area of %.2f\n", radius, area);
	printf("The disk with r = %.2f has the area of %.2f\n", radius, (PI * pow(radius, 2)));
}
