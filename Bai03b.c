#include <stdio.h>
#include <stdlib.h>

/*
	BAI 01: Viet ham tinh tong tu 1 den 100
*/
int sumIntegerList();

int main() {
	int result;

	result = sumIntegerList();

	printf("The sum of list integer form 01 to 100: %d\n", result);

	return 0;
}

//Declare Function for BAI 01
int sumIntegerList() {
	int sum = 0;

	for(int i = 1; i <= 100; i++) {
		sum += i; //sum = sum + i
	}

	return sum;
}
