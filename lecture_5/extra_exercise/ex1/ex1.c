#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ll.h"

int main(int argc, char** argv)
{
	//Linked list
	Node* list = NULL;
	Node* list1 = NULL;
	Node* list2 = NULL;
	Node* list3 = NULL;

	
	//Create test strings	
	char* string1 = "Hello";
	char* string2 = "Nice to meet you";
	char* string3 = "Donavan Tran";
	
	//Push the strings into respective list
	list1 = push(list1, string1);
	list1 = push(list1, string2);

	list2 = push(list2, string2);
	list2 = push(list2, string3);

	list3 = push(list3, string3);
	list3 = push(list3, string1);



	//create list of linkedlist
	list = push(list, list1);
	list = push(list, list2);
	list = push(list, list3);
	
	
	//iterate the list of linkedlist
	//Create a temp node
	Node* temp = list;
	int count = 0;
	while (temp != NULL) {
		Node* embed = (Node*) temp->element;
		int embedcount = 0;

		printf("Main list[%d]:\n", count++);

		//travers the embedded list
		while (embed != NULL) {
			printf("embed[%d]: '%s'\n", embedcount++, (char*) embed->element);
			embed = embed->next;
		}	
		temp = temp->next;
		printf("I'm still here");
	}
	
	printf("I'm here before free");
	//Free up everything
	while (list != NULL) {
		Node* embed = (Node*) pop(list, &list);
		printf("I'm here");
		while (embed != NULL) {
			char* to_free = (char*) pop(embed, &embed);
			free(to_free);
		}
	}
	return EXIT_SUCCESS;

}
