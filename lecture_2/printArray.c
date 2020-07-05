#include <stdio.h>

void printArray(int *array, int length) {

  int i;
  for (i = 0; i < length; i++) {
    printf("The %uth element is: %u\n", i, *(array + i));
  }
  printf("\n");
}
