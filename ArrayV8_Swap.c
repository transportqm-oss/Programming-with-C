#include <stdio.h>
#include <stdlib.h>

/*
	Hoan doi gia tri cua 02 bien cho nhau
*/

int main() {
	int a = 23;
	int b = 100;
	int tmp; //t, tmp, temp, temporary - bien tam, bien trung gian
	printf("Before swapping: a = %d, b = %d\n", a, b);

	tmp = a; //cat lai 23 truoc khi gan a bang 100
	a = b; // a lay 100 cua b
	b = tmp; // b lay gia tri cua a dang nam o t la 23

	printf("After swapping: a = %d, b = %d\n", a, b);

	return 0;
}
