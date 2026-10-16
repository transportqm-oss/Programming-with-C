#include <stdio.h>
#include <stdlib.h>

/*
	+ Bai le, hieu kien thuc ly thuyet. Bai nay minh hoa khai niem scope cua 1 bien
	+ Bien nay o dau cung co the thay va so duoc
	+ Phan biet giua local va global
*/

int yob; //yob la bien toan cuc, global, ham nao cung so/sua duoc
//yob = 2002; //Khai bao kieu nay la SAI !!! Lenh nam trong ham, ham trong main(), noi bat da

/*
	DEFINE FUNCTION
*/
void printYob();
void printLastedYob();

int main() {
	printf("in main(), yob is %d\n", yob); //khi in ra value = 0 = RAC
	//yob = 2002;

	//Goi ham
	//printYob();
	//printLastedYob();
	//0 0 2010 2022 2022

	//Goi ham
	printLastedYob();
	printYob();
	//0 2022 2022 2010 2010

	//Ham goi xong, main() lam tiep, hoi xem yob la ???
	printf("in main(), after calling printYob() yob finally is %d\n", yob);

	return 0;
}

/*
	CALLL FUNCTION
*/

void printYob() {
	printf("in printYob(), yob is %d\n", yob);
	yob = 2010;
	printf("in printYob(), after updating yob, yob now is %d\n", yob);
}

void printLastedYob() {
	yob = 2022;
	printf("in printLastedYob(), after updating yob, yob now is %d\n", yob);
}
