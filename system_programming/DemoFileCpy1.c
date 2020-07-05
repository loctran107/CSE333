//trivila file copy program using POSIX I/O library

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BSIZE 16384

int main() 
{

	int fin, fout; /*input and output handles*/
	char buf[BSIZE];
	int count;

	if ((fin = open("foo", O_RDONLY)) < 0) {
		perror("foo");
		exit(EXIT_FAILURE);
	}

	if ((fout = open("bar", O_WRONLY | O_CREAT, 0644)) < 0) {
		perror("bar");
		exit(EXIT_FAILURE);
	}

	while ((count = read(fin, buf, BSIZE)) > 0) {
		printf("count is: %d\n", count);
		write(fout, buf, count);

	}

	close(fin);
	close(fout);
	return EXIT_SUCCESS;
}
