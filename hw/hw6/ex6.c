#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define READBUFFERSIZE 128 //always define certain size of buffer

//Buggy solution
/*int main(int argc, char** argv) {

	FILE *fin;
      	char readbuf[READBUFFERSIZE];
	int len;
	// Take the filenames from command line argument
	// print error message if exceed 1 argument
	if (argc > 1) {
		fprintf(stderr, "Please only enter a file\n");
		return EXIT_FAILURE;
	}
		
	//Open the input file
	fin = fopen(argv[1], "rb"); //"rb" -> read, binary mode
	if (fin == NULL) {
		fprintf(stderr, "Please enter a valid file\n"); //this prints message error
		perror("fopen for read failed"); //this prints what error is
		return EXIT_FAILURE;
	}

	
	//Open the output file
	fseek(fin, 0, SEEK_END);
	
	len = ftell(fin); //the number of bytes in the file
	int count = 1;
	while (fread(readbuf, 1, len, fin) > 0) {
		printf("%c", readbuf);
		fseek(fin, -1 * count, SEEK_END);
		count++;
	}	
	
}*/

//beter solution
int main(int argc, char** argv) {
	
	FILE* f;
	size_t size;
	char* c; //string

	//Handle corner-case data
	if (argc != 2) {
		fprintf(stderr, "Please only enter a file\n");
		return EXIT_FAILURE;

	}

	//Open the file
	f = fopen(argv[1], "rb");
	if (f == NULL) {
		fprintf(stderr, "%s --", argv[1]);
		perror("fopen failed --");
		return EXIT_FAILURE;

	}

	//Seek to EOF, and check file sizre
	fseek(f, 0, SEEK_END);
	size = ftell(f);

	//seek to last legitimate char (1 before EOF \0")
	fseek(f, -1, SEEK_CUR);

	//loop backwards to print the file
	for (int i = size; i > 0; i--) {
		fread(&c, sizeof(char), 1, f);
		printf("%c", (char) c); //cast from string to char, the print
		fseek(f, -2, SEEK_CUR); //double back to next character
	}

	fclose(f); //close file
	return EXIT_SUCCESS;


}
