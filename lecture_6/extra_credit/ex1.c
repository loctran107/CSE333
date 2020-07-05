#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50 //maximum buffer
#define CHAR_BUFFER 10

void printArray(int* array, int size);
int main(int argc, char** argv) {
	
	int i, j;
	char buf[MAX]; //string bufer

	//Get buffer input
	printf("Input something: ");
	fgets(buf, MAX, stdin);

	//printf("%c\n", buf[1]);
	//convert string buffer into array
	int array[MAX];
	i = 0;
	j = -1;
	while (i < strlen(buf)) {

		char num[strlen(buf)];
		while (buf[i] != ' ' && buf[i] != '\0') {
			num[i] = buf[i];
			i++;
		}
		num[i] = '\0';
		j++;
		array[j] = atoi(num);
	}
	
	printArray(array, j + 1);	
	return EXIT_SUCCESS;
}

void printArray(int* array, int size) {

	int i;
	for (i = 0; i < size; i++) {
		printf("The %dth element is: %d\n", i, *(array + i));

	}
}
