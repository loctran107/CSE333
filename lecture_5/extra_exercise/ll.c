#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ll.h"

Node* Push(Node* head, int element) 
{
	Node* n = (Node*) malloc(sizeof(Node));
	assert(n != NULL);
	n->element = element;
	n->next = head;
	return n;
}

int numList(Node* list)
{
	//traverse the linked list
//	Node* temp = list; //defining a temporary Node pointer won't work (Figured out)
	int count = 0;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return count;
}

void printList(Node* list)
{
	while (list != NULL)
	{
		printf("%d ", list->element);
		list = list->next;
	}
	printf("\n");
}
