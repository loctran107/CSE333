#include <stdio.h>
#include <stdlib.h>

void reverse(__uint32_t *array, int length);
void printArray(__uint32_t *array, int length);
int main(int argc, char** argv) {

	//random array
	__uint32_t testArray[6] = {1, 2, 3, 4, 5, 6};
	printArray(testArray, 6);	
	//do the reversing
	reverse(testArray, 6);
	printArray(testArray, 6);
	return EXIT_SUCCESS;
}


void reverse(__uint32_t* array, int length) {

	__uint32_t i;
	for (i = 0; i < length / 2; i++) {
		__uint32_t temp = *(array + i);
		*(array + i) = *(array + (length - i - 1));
		*(array + (length - i - 1)) = temp;
	}


}

void printArray(__uint32_t* array, int length) {

	__uint32_t i;
	for (i = 0; i < length; i++) {
		printf("The %uth element is: %u\n", i, *(array + i));
	}
	printf("\n");


}
