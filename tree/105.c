#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	TreeNode *root = NULL;
	int preorder[] = {3, 9, 20, 15, 7};
	int inorder[] = {9, 3, 15, 20, 7};
	root = buildTree(preorder, sizeof(preorder)/sizeof(int), inorder,
			sizeof(inorder)/sizeof(int));
	show_tree(root);
	release_tree(root);
	return 0;
}
