#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {

	FILE *fp;
	
	fp = fopen("file.txt", "w+");
	fputs("This is the tutorialspoint.com", fp);

	fseek(fp, -8, SEEK_END);
	char c = fgetc(fp);
	printf("%c\n", c);

	fclose(fp);

	return EXIT_SUCCESS;

}
