
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
#if 1
	//! 2 
	//!1 3
	TreeNode *root = create_node(2);
	root->left = create_node(1);
	root->right = create_node(3);
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
	//root = inverttree(root); 
	//show_tree(root);
	printf("\n");
	release_tree(root);
	return 0;
}
