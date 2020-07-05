#include <stdlib.h>
#include <assert.h>
#include "ll.h"

Node* Push(Node* head, void* element) 
{
	Node* n = (Node*) malloc(sizeof(Node));
	assert(n != NULL);
	n->element = element;
	n->next = head;
	return n;
}

