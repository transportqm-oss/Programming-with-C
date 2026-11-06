#include <stdio.h>
#include <stdlib.h>

/*
	Nhap tu ban phim mang 10 so nguyen bat ki.
	Co bao nhieu so chan
	Tinh tong cac so le
	5 10 15 20 25 30 35 40
	I: can mang
	P: duyet mang, [i] co chan khong, neu co thi count++
	O: so chan, count
*/

int main() {
	int n[10], evenCount = 0, sumOdd = 0;

	printf("Please input 10 numbers\n");
	for(int i = 0; i < 10; i++) {
		printf("Input number #%d: ", (i + 1));
		scanf("%d", &n[i]); // &n[i] ~~ int yob &yob
	}

	//in mang
	printf("You have just input the following numbers\n");
	for(int i = 0; i < 10; i++) {
		printf("%d\t", n[i]);
	}
	printf("\n");

	//quet mang, cung luc lam nhieu viec, dem so chan, tinh tong le
	for(int i = 0; i < 10; i++) {
		if(n[i] % 2 == 0) {
			evenCount++; //gap 01 thang chan ++ lien
		} else {
			sumOdd += n[i];
		}
	}

	printf("There is/are %d even number(s) in this array\n", evenCount);
	printf("The sum of odd number(s) in this array is: %d\n", sumOdd);

	return 0;
}
