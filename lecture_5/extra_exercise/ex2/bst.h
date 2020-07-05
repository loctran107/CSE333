typedef struct tree_st {

	int value;
	struct tree_st* left;
	struct tree_st* right;
} TreeNode;

void insert(TreeNode* root, int value);
void lookup(TreeNode* root, int value);
void deletion(TreeNode* root, int value);

