#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

void processFile(char* directory, char* filename);
int main(int argc, char** argv) {
	
	/*Check to make sure we have a valid input*/
	if (argc != 2) {
		fprintf(stderr, "Error: You have entered more than 1 directory. Try again\n");
		exit(EXIT_FAILURE);
	}
	
	/*Open the directory*/
	DIR* directory;

	directory = opendir(argv[1]);
	if (directory == NULL) {
		fprintf(stderr, "This directory does not exist. Please try again");
		exit(EXIT_FAILURE);
	}
	
	char* search = ".txt";
 	struct dirent *dir;
	dir = readdir(directory);
	while (dir != NULL) {
		char* ret = strstr(dir->d_name, search);
		if (ret) {
			processFile(argv[1], dir->d_name);
		}
		dir = readdir(directory);
	}

	closedir(directory);
	return EXIT_SUCCESS;
}	

void processFile(char* directory, char* filename) {

	int len_dir = strlen(directory);
	int len_file = strlen(filename);

	//Merge the file name
	char* merge_filename = (char*) malloc(sizeof(char) * (len_dir + len_file + 2));
	if (merge_filename == NULL) {
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	snprintf(merge_filename, len_dir + len_file + 2, "%s/%s", directory, filename);
	
	//Open the file using O_RDONLY flag
	int fd = open(merge_filename, O_RDONLY);
	
	//Read from the file and write it to standard out
	char buf[SIZE];
	ssize_t len;

	printf("The content of %s is:\n", filename);
	do {
		len = read(fd, buf, SIZE);
		if (len == -1) {
			if (errno != EINTR) {
				close(fd);
				perror("I'm here");
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
					perror("I'm here 2");
					exit(EXIT_FAILURE);

				}
				continue;
			}
			total += wlen;
		} 
	} while (len != 0);
	printf("\n");
	//Clean up
	close(fd);
	free(merge_filename);
}

//Recommended solution of printing the file
//
/*void PrintFile(char* merged_filename) {
	
	//open up the file
	int fd = open(merged_filename, O_RDONLY);
	if (fd == -1) {
		perror("Couldn't find/open file");
		exit(EXIT_FAILURE);
	}
	
	//Loop through ,readin tge file 1024 byte
	//chuns at a time
	char buf[1024];
	while (1) {

		int res = read(fd, buf, 1024);
		if (res == 0) {

			//EOF
			break;
		} else if (res == -1 && errno != EINTR) {
			
			//Some kind of error
			perror("Read error");
			exit(EXIT_FAILURE);
		} else {

			//print out what we need
			if (fwrite(buf, res, 1, stdout) != 1) {
				fprintf(stderr, "fwrite failed!\n");
				exit(EXIT_FAILURE);
			}

		}
		 

	}
	close(fd);
}*/
