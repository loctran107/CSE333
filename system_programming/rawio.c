#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{

	char* buffer;
	int fd, size, count, i;

	if (argc != 3) {
		printf("usage: %s blocksize blockcount\n", argv[0]);
		exit(EXIT_SUCCESS);
	}

	fd = open("rawio.out", O_RDONLY | O_CREAT | O_TRUNC, 0600);
	size = atoi(argv[1]);
	count = atoi(argv[2]);

	buffer = (char*)  malloc(size);
	for (i = 0; i < count; i++) {
		write(fd, buffer, size);
	}

	close(fd);
	return EXIT_SUCCESS;

}
