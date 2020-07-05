#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_st {
	int element;
	struct node_st* next;

} Node;

//Always push to the first node of the list
Node* Push(Node* head, int e) 
{
	Node* n = (Node*) malloc(sizeof(Node));
	assert(n != NULL);
	n->element = e;
	n->next = head;
	return n;
}

int main(int argc, char** argv) 
{
	Node* list = NULL;
	list = Push(list, 1);
	list = Push(list, 2);
	return 0;


}
