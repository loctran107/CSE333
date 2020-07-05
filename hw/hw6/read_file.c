#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	FILE *fp;
	int c;

	fp = fopen("file.txt", "r");
	while (1) {
		c = fgetc(fp);
		if (feof(fp)) {
			break;
		}
		printf("%c", c);
	}
	fclose(fp);
	return EXIT_SUCCESS;
} 
