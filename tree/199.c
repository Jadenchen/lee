#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	int *right = NULL;
	int returnSize = 0;

	TreeNode *root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
#if 0
	root->left->left = NULL;
	root->left->right = create_node(5);
	root->right->left = NULL;
	root->right->right = create_node(4);
#else

	root->left->left = create_node(4);
#endif
	show_tree(root);
	right = rightSideView(root, &returnSize);
	for (int i = 0; i < returnSize; i++)
		printf("%d ", right[i]);

	printf("\n");
	release_tree(root);
	return 0;
}
