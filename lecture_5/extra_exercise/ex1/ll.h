typedef struct node_st {

	void* element; //can be a list or whatever	
	struct node_st* next;
} Node;

Node* push(Node* head, void* element);
void* pop(Node* old_head, Node** new_head);
unsigned int numList(Node* list);

