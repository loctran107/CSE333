/*
 * Copyright ©2020 Hal Perkins.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Spring Quarter 2020 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "Vector.h"

// Print the elements in the vectors on a line
static void PrintIntVector(vector_t v);

#define N 10 // Test vector length.
int main(int argc, char *argv[]) {
  int i;
  
  vector_t v = Vector_Allocate(4);

  if (v == NULL)
    return EXIT_FAILURE;

  for (i = 0; i < N; ++i) { // Place some elements in the vector.
    int *x = (int*)malloc(sizeof(int));
    element_t old;
    Vector_Set(v, i, x, &old);
  }

  PrintIntVector(v);

  return EXIT_SUCCESS;
}

static void PrintIntVector(vector_t v) {
  int i;
  size_t length;

  assert(v != NULL);

  length = Vector_Length(v);

  if (length > 0) {
    printf("[%d", *((int*)Vector_Get(v, 0)));
    for (i = 1; i < Vector_Length(v); ++i)
      printf(",%d", *((int*)Vector_Get(v, i)));
    printf("]\n");
  }
}
