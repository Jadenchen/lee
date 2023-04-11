
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	int k = 1;
	TreeNode *root = create_node(5);
	root->left = create_node(3);
	root->right = create_node(6);
	root->left->left = create_node(2);
	root->left->right = create_node(4);
	root->left->left->left = create_node(1);

	show_tree(root);
	printf("\n");
	printf("k th val %d \n", kthSmallest(root, k));
	release_tree(root);
	return 0;
}
