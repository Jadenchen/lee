#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	int *result = NULL;
	int returnSize = 0;
#if 1
	//!  3
	//! 3 
	//!4 2
	TreeNode *root = create_node(3);
	root->left = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(2);
#else
	//! 2
	//!   4 
	//!  10 8 
	//!    4

	TreeNode *root = create_node(2);
	root->right = create_node(4);
	root->right->left = create_node(10);
	root->right->right = create_node(8);
	root->right->right->left = create_node(4);
#endif
	show_tree(root);
	printf("\n");
	result = preorder_save(root, &returnSize);
	for (int i = 0; i < returnSize; i++) 
		printf("%d ", result[i]);
	printf("\n");
	release_tree(root);
	return 0;
}
