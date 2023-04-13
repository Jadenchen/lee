#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	TreeNode *root = create_node(3);
	root->left = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(2);
	show_tree(root);
	printf("good nodes %d \n", goodNodes(root)); 
	printf("\n");
	release_tree(root);
	return 0;
}
