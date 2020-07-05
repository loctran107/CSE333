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

#include "Vector.h"

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
