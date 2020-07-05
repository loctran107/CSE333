#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void insert(TreeNode* node, int value) 
{
	if (node == NULL) {
		node = (TreeNode*) malloc(sizeof(TreeNode));
		node->value = value;
	} else if (node->value >= value) {
		//search right of the tree
		insert(node->right, value);
	} else {
		insert(node->left, value);
	}
}


