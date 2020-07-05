typedef struct node_st {

	int element;	
	struct node_st* next;
} Node;

Node* Push(Node* head, int element);
void printList(Node* list);
int numList(Node* list);

