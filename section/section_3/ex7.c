#include <sys/types.h>
#include <dirent.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

	if (argc != 2) {
		fprintf(stderr, "Please enter only one argument");
		exit(EXIT_FAILURE);
	}

	//Open the directory using opendir
	//May include errno condition but yeah...
	DIR* dir = opendir(argv[1]);
	if (dir == NULL) {
		perror("Open directory failed");
		exit(EXIT_FAILURE);
	}

	//Parse through the directory and print our filesname
	//use readdir and struct dirent 
	struct dirent* entry = readdir(dir);
	while (entry != NULL) {
		printf("%s\n", entry->d_name);
		entry = readdir(dir);
	}

	closedir(dir);
	

	return EXIT_SUCCESS;

}

