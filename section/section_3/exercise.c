#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 1024
int main(int argc, char** argv) {
	
	/*1. Check to make sure we have a valid command line arguments */

	if (argc != 2) {
		perror("Please enter only 1 file");
		exit(EXIT_FAILURE);
	}

	/* 2. Open the file, use O_RDONLY flag */
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Read file failed");
		exit(EXIT_FAILURE);
	}

	char buf[BUF_SIZE];
	ssize_t len;

	do {
		len = read(fd, buf, BUF_SIZE);
		if (len == -1) {
			if (errno != EINTR) {
				close(fd);
				perror(NULL);
				exit(EXIT_FAILURE);

			}
			continue;
		}

		size_t total = 0;
		ssize_t wlen;
		while (total < len) {
			wlen = write(1, buf + total, len - total);
			if (wlen == -1) {
				if (errno != EINTR) {
					close(fd);
					perror(NULL);
					exit(EXIT_FAILURE);
				}
				continue;
			}
			total += wlen;

		}

	} while (len != 0);
	
	/* Clean up*/
	close(fd);
	return EXIT_SUCCESS;

}
