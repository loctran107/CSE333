#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
int main(int argc, char** argv)
{
	Node* list = NULL;
	char* hi = "hello";
	char* bye = "goodbye";
	
	list = Push(list, (void*) hi);
	list = Push(list, (void*) bye);
	printf("payload: '%s'\n", (char*) ((list->next)->element));
	return 0;
}
