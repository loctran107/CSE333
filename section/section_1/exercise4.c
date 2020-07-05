#include <stdio.h>
#include <stdlib.h>

void prefix_sum(int* input, int* output, int length);
void printArray(int* array, int length);
int main(int argc, char** argv) {

	int array[4] = {1, 2, 3, 4};
	int output[4];
	prefix_sum(array, output, 4);
	printArray(output, 4);

}

void prefix_sum(int* input, int* output, int length) {


	//assume length of both array are the same
	int i;
	int sum = 0;
	for (i = 0; i < length; i++) {
		sum += *(input + i);
		*(output + i) = sum;	
	}
}

void printArray(int* array, int length) {

	for (int i = 0; i < length; i++) {
		printf("%d ", *(array + i));
	}
	printf("\n");

}
