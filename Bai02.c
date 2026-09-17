#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int i, n;
	float score;

	do {
		printf("Enter number of list student: ");
		scanf("%d", &n);

		if(n <= 0) {
			printf("Number of list student must be greater than 0!\n");
		}

	} while(n <= 0);

	for(i = 1; i <= n; i++) {
		do {
			printf("Input score of student %d: ", i);
			scanf("%f", &score);

			if(score < 0 || score > 10) {
				printf("Score must be between 0 - 10 !\n");
			}

		} while(score < 0 || score > 10);

		if(score >= 8.5) {
			printf("A - GIOI - EXCELLENT.\n");
		} else if(score >= 7.0) {
			printf("B - KHA - GOOD.\n");
		} else if(score >= 5.5) {
			printf("C - TRUNG BINH - AVERAGE.\n");
		} else if(score >= 4.0) {
			printf("D - TRUNG BINH YEU - BELOW AVERAGE.\n");
		} else {
			printf("F - KEM - POOR.\n");
		}
	}

	return 0;
}
