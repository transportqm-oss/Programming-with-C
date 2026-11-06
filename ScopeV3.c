#include <stdio.h>
#include <stdlib.h>

/*
	Declare global variable
*/
int yob; //global variable, gan gia tri luc khai bao hoac gan sau deu duoc

//yob = 2002; //Khong duoc khai bao kieu nay, phai nam trong 01 ham nao do

void printYob();
void printCurrentYob(); //prototype

int main() {
	printYob(); //ham cua ban xem nhu 01 lenh printf() scanf()
	printCurrentYob(); //in nam sinh moi nhat xem sao

	printf("Your yob in main: %d\n", yob);

	return 0;
}

void printYob() {
	yob = 2002; //global variable ham co quyen xai !!!
	printf("Your yob: %d\n", yob);
}

void printCurrentYob() {
	yob = 2003; //tui cung co quyen xai global variable
	printf("Your current yob: %d\n", yob);
}
