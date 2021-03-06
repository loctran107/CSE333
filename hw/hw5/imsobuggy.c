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

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// An arbitrary pointer to represent an element in the vector.
typedef void* element_t;

// An expandable array of element_ts.
typedef struct vector_st {
  size_t length;
  element_t *arry;
} *vector_t;

// On success, return vector_t with an initial length of n.
// On failure, returns NULL.  Assumes v != NULL.
vector_t Vector_Allocate(size_t n);

// Frees the memory allocated for the vector_t.  Assumes v != NULL.
void Vector_Free(vector_t v);

// Sets the nth element of v to be e.  Returns the previous nth element_t in
// prev. Freeing e is the responsibility of the user, not the vector_t.
// Returns true iff successful.  Assumes v != NULL.
bool Vector_Set(vector_t v, int index, element_t e, element_t *prev);

// Returns the element at the given index within v.  Assumes v != NULL.
element_t Vector_Get(vector_t v, int index);

// Returns the length of v.  Assumes v != NULL.
size_t Vector_Length(vector_t v);

//// Helper functions (assume not buggy)

// Returns a copy of arry with new length newLen.  If newLen < oldLen
// then the returned array is clipped.  If newLen > oldLen, then the
// resulting array will be padded with NULL elements.
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen);

// Print the elements in the vector on a line.
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


vector_t Vector_Allocate(size_t n) {
  vector_t v = (vector_t)malloc(sizeof(struct vector_st));
  v->arry = (element_t*)malloc(n*sizeof(element_t));
  if (v == NULL || v->arry == NULL)
    return NULL;

  return v;
}

void Vector_Free(vector_t v) {
  assert(v != NULL);
  free(v->arry);
  free(v);
}

bool Vector_Set(vector_t v, int index, element_t e, element_t *prev) {
  assert(v != NULL);
  assert(index >= 0);

  if (index >= v->length) {
    size_t newLength = index+1;

    v->arry = ResizeArray(v->arry, v->length, newLength);
    v->length = newLength;
  } else {
    prev = v->arry[index];
  }
  
  v->arry[index] = e;

  return true;
}

element_t Vector_Get(vector_t v, int index) {
  assert(v != NULL);
  assert(index >= 0);

  return v->arry[index];
}

size_t Vector_Length(vector_t v) {
  assert(v != NULL);
  return v->length;
}

static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen) {
  int i;
  size_t copyLen = oldLen > newLen ? newLen : oldLen;
  element_t *newArry;

  assert(arry != NULL);

  newArry = (element_t*)malloc(newLen*sizeof(element_t));

  if (newArry == NULL)
    return NULL; // malloc error!!!

  // Copy elements to new array
  for (i = 0; i < copyLen; ++i)
    newArry[i] = arry[i];  

  // Null initialize rest of new array.
  for (i = copyLen; i < newLen; ++i)
    newArry[i] = NULL;

  return newArry;
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
