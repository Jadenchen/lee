#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	TreeNode *root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = NULL;
	root->left->right = create_node(5);
	root->right->left = NULL;
	root->right->right = create_node(4);
	show_tree(head);
	release_tree(head);
	return 0;
}
