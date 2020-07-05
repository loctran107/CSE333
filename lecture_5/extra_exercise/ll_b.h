typedef struct node_st {

	struct node_st* list;	
	struct node_st* next;
} Node;

Node* Push(Node* head, Node* element);
//void printList(Node* list);
//int numList(Node* list);

