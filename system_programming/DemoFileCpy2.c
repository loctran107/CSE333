//trivila file copy program using standard I/O library

#include <stdio.h>
#include <stdlib.h>

#define BSIZE 16384

int main() 
{

	FILE *fin, *fout; /*input and output handles*/
	char buf[BSIZE];
	int count;

	if ((fin = fopen("foo", "r")) == NULL) {
		fprintf(stderr, "foo");
		exit(EXIT_FAILURE);
	}

	if ((fout = fopen("bar", "w")) == NULL) {
		fprintf(stderr, "bar");
		exit(EXIT_FAILURE);
	}

	while ((count = fread(buf, 1, BSIZE, fin)) > 0) {
		fwrite(buf, 1, count, fout);
	
	}

	fclose(fin);
	fclose(fout);
	return EXIT_SUCCESS;
}
