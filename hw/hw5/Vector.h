#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef _VECTOR_H_
#define _VECTOR_H_


// An arbitrary pointer to represent an element in the vector
typedef void* element_t;

// An expandable array of element_ts
typedef struct vector_st {
	size_t length;
	element_t* arry;
} *vector_t;

// On success, return vector_t with an initial length of n.
// On failure, returns NULL. Assumes v != NULL
vector_t Vector_Allocate(size_t n);

// Frees the memory allocated for the vector_t. Assumes v != NULL
void Vector_Free(vector_t v);

// Sets the nth element of v to be e. Returns the previous nth element_t 
// in prev. Freeing e is the responsibility of the user, not the vector_t.
// Returns true if successful. Assumes v != NULL
bool Vector_Set(vector_t v, int index, element_t e, element_t *prev);

// Returns the element at the given inded within v. Assumes v != NULL
element_t Vector_Get(vector_t v, int index);

// Returns the length of v. Assumes v != NULL
size_t Vector_Length(vector_t v);


// Returns a copy of the arry with new length newLen. If newLen < oldLen,
// then the returned array is clipped. if newLen > oldLen, then the resulting
// array will be padded with NULL elements.
static element_t *ResizeArray(element_t *arry, size_t oldLen, size_t newLen);


#endif //_VECTOR_H_
