typedef struct node_st {

	void* element;
	struct node_st* next;
} Node;

Node* Push(Node* head, void* element);
