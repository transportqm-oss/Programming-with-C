#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	FILE *source, *target;
	char word[100];
	char lower[100];

	/* Validate command line arguments */
	if (argc != 3) {
		printf("Usage: %s <source_file> <target_file>\n",
		       argv[0]);
		return 1;
	}

	/* Open source file */
	source = fopen(argv[1], "r");

	if (source == NULL) {
		printf("Cannot open source file.\n");
		return 1;
	}

	/* Open target file */
	target = fopen(argv[2], "w");

	if (target == NULL) {
		printf("Cannot create target file.\n");
		fclose(source);
		return 1;
	}

	/* Read words from source file */
	while (fscanf(source, "%99s", word) == 1) {
		strcpy(lower, word);
		int i;

		/* Convert to lowercase */
		for (i = 0; lower[i] != '\0'; i++) {
			lower[i] = tolower(lower[i]);
		}

		/* Skip a, an, the */
		if (strcmp(lower, "a") == 0 ||
		        strcmp(lower, "an") == 0 ||
		        strcmp(lower, "the") == 0) {
			continue;
		}

		fprintf(target, "%s ", word);
	}

	printf("Contents copied successfully.\n");
	printf("Words 'a', 'an', and 'the' removed.\n");

	fclose(source);
	fclose(target);

	return 0;
}

