#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void copyAndSort(int64_t* array, int64_t* sortedArray, int length);
void printArray(int64_t* array, int length);
void sort(int64_t* array, int64_t* sortedArray, int i);

int main(int argc, char** argv) {

	//testArray
 	int64_t testArray[11] = {3, 2, -5, 8, 17, 6, 1, 7, 8, -8, 6};
//	int testArray[3] = {3, 1, 4};
	int64_t sortedArray[11];
	copyAndSort(testArray, sortedArray, 11);
	return EXIT_SUCCESS;

}


/* Assume the length of the two inputs arrays 
 * are the same
 */
//Normal implementation of insertion sort
/*void copyAndSort(int64_t* array, int64_t* sortedArray, int length) {
	
	int64_t i;
	*sortedArray = *array; //copy the first element of array into sortedArray
	//Copy and sort the element
	for (i = 1; i < length; i++) {
		*(sortedArray + i) = *(array + i);
		int64_t bound_check = i;
		while ((bound_check > 0) && (*(sortedArray + bound_check) < *(sortedArray + bound_check - 1))) {

			//swapping
			int64_t temp = *(sortedArray + bound_check);
			*(sortedArray + bound_check) = *(sortedArray + bound_check- 1);
			*(sortedArray + bound_check - 1) = temp;
			bound_check--;
		}
	}
	
	for (i = 0; i < length; i++) {
		printf("%ld ", *(sortedArray + i));
	}
	printf("\n");
}*/

//A better solution
void copyAndSort(int64_t *array, int64_t* sortedArray, int length) {

	int64_t i, j, key;
	*sortedArray = *array;
	for (i = 1; i < length; i++) {
		
		//extract the key
		key = *(array + i);
		j = i - 1;

		while (j >= 0 && *(sortedArray + j) > key) {
			*(sortedArray + j + 1) = *(sortedArray + j);
			j--;
		}
		*(sortedArray + j + 1) = key;
	}
	
	printArray(sortedArray, 11);
}

void printArray(int64_t* array, int length) {

	int64_t i;
	for (i = 0; i < length; i++) {

		printf("%ld ", *(array + i));

	}
	printf("\n");

}
//Sample solution (elegant)
/*void copyAndSort(int64_t* array, int64_t* sortedArray, int length) {

	int64_t i, key, j;
	for (i = 1; i < length; i++) {
		key = *(array + i);
		j = i - 1;
		
		*Move elements of arr[0..i-1], that are 
		  greater than key, to one position ahead
		  of their current position
	//	while (j >= 0 && *(array + j) > key) {
	//		*(array + j + 1) = *(array + j);
	//		j--;
	//	}
	//	*(array + j + 1) = key;
		
//	}
	//printArray
}*/

/* Recursion insertion sort in progress*/
/*void copyAndSort(int* array, int* sortedArray, int length) {
	int i;
	*sortedArray = *array;
	for (i = 1; i < length; i++) {
		sort(array + i, sortedArray + i - 1, i);
	}
	printArray(sortedArray, length);
	
}	

void sort(int* array, int * sortedArray, int i) {

	if (*array < *sortedArray) {
		*(sortedArray + 1) = *sortedArray;
		*sortedArray = *array;
		if (i > 1) {
			sort(array - 1, sortedArray - 1, i - 1);
		}
	} else {
		*(sortedArray + 1) = *array;
	}
}*/


