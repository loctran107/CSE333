#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
	
	char *src, *dst;
	int fin, fout;
	size_t size;
	
	fin = open("foo", O_RDONLY);
	if (fin < 0) {
		perror("foo");
		exit(EXIT_FAILURE);
	}

	/*Get the size of the file. We use this to specify the size of the two mappings*/

	size = lseek(fin, 0, SEEK_END);
	
	src = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fin, 0);

	if (src == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	fout = open("bar", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	
	if (fout < 0) {
		perror("bar");
		exit(EXIT_FAILURE);

	}

	if (ftruncate(fout, size) == -1) {
		perror("ftruncate");
		exit(EXIT_FAILURE);
	}

	dst = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fout, 0);
	if (dst == MAP_FAILED) {
		perror("mmap");
		exit(EXIT_FAILURE);
	}

	memcpy(dst, src, size); /*Copy bytes between mappings*/
	if (msync(dst, size, MS_SYNC) == -1) {
		perror("msync");
		exit(EXIT_FAILURE);

	}

	return EXIT_SUCCESS;
}
