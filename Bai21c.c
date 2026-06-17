#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp1, *fp2;
	int ch1, ch2;
	long pos = 1;
	int diffCount = 0;

	/* c. Validate argc */
	if (argc != 3) {
		printf("Usage: %s <file1> <file2>\n", argv[0]);
		return 1;
	}

	/* d. Open files in read mode */
	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");

	if (fp1 == NULL) {
		printf("Cannot open file: %s\n", argv[1]);
		return 1;
	}

	if (fp2 == NULL) {
		printf("Cannot open file: %s\n", argv[2]);
		fclose(fp1);
		return 1;
	}

	printf("\nComparing files...\n\n");

	/* e. Read both files until EOF encountered */
//	while ((ch1 = fgetc(fp1)) != EOF &&
//	        (ch2 = fgetc(fp2)) != EOF) {
//		/* f. Check differences */
//		if (ch1 != ch2) {
//			printf("Position %ld : '%c' != '%c'\n",
//			       pos,
//			       ch1,
//			       ch2);
//
//			diffCount++;
//		}
//
//		pos++;
//	}

	while(1) {
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);

		if(ch1 == EOF || ch2 == EOF) {
			break;
		}

		if (ch1 != ch2) {
			printf("Position %ld : '%c' != '%c'\n",
			       pos,
			       ch1,
			       ch2);
			diffCount++;
		}

		pos++;
	}

	/* g. Handle remaining characters if one file ends first */

	while (ch1 != EOF) {
		printf("Position %ld : '%c' != EOF\n",
		       pos,
		       ch1);

		diffCount++;

		ch1 = fgetc(fp1);
		pos++;
	}

	while (ch2 != EOF) {
		printf("Position %ld : EOF != '%c'\n",
		       pos,
		       ch2);

		diffCount++;

		ch2 = fgetc(fp2);
		pos++;
	}

	/* h. Display result */
	printf("\n---------------------------------\n");

	if (diffCount == 0) {
		printf("The two files are identical.\n");
	} else {
		printf("Total differences found: %d\n",
		       diffCount);
	}

	/* i. Close files */
	fclose(fp1);
	fclose(fp2);

	return 0;
}
