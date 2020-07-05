#include <stdlib.h> //for malloc() and free()
#include <stdio.h> //for NULL
#include <assert.h> //for assert()
#include "ll.h"

Node* push(Node* head, void* element) 
{
	Node* n = (Node*) malloc(sizeof(Node));
	assert(n != NULL);
	n->element = element;
	n->next = head;
	return n;
	
}

void* pop(Node* old_head, Node** new_head)
{
	void* temp;
	//edge-case: Attempt to pop from
	//an empty list returns NULL
	if (old_head == NULL) {
		return NULL;
	}

	//When there is something in the list, save it
	//in a temp variable to return later
	temp = old_head->element;
	
	//set the new head of the list
	*new_head = old_head->next;

	//Free up the old_head. Warning: before that,
	//make sure to set the old_head fields to NULL 
	//in the event of the pointer bugs occur
	old_head->element = NULL;
	old_head->next = NULL;
	free(old_head);

	//return the paylaod we previously stashed in temp
	return temp;
}


//Remember to use unsigned int when necessary
unsigned int numList(Node* list)
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

