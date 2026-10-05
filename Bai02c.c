#include <stdio.h>
#include <stdlib.h>

//Define function
int getFactorial(int n);

int main() {
	int n;
	printf("Enter number: ");
	scanf("%d", &n);

	if(n <= 0) {
		printf("Error: Number must be greater than 0!\n");
		return 1;
	}

	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += getFactorial(i);
	}

	printf("The sum of factorial 01 to %d is: %d\n", n, sum);

	return 0;
}

//Call function
int getFactorial(int n) {
	int result = 1;

	for(int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}
