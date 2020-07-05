#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

int main(int argc, char** argv)
{
	int i;
	Node* list = NULL;
	
	for (i = 0; i < 5; i++)
	{
		list = Push(list, i);
	}
	
	printf("There are %d elements in the list\n", numList(list));
	printList(list);

	return EXIT_SUCCESS;
}
