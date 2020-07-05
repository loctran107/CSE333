#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{

	int fd;
	if ((fd = open("foo", O_WRONLY | O_CREAT, 0777)) < 0) {
		printf("The error occur is %d\n", errno);
		perror("foo");
		exit(EXIT_FAILURE);

	}
	write(fd, "hello world\n", 11);
	close(fd);
	return EXIT_SUCCESS;

}
