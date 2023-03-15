#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct TreeNode* invertTree(struct TreeNode* root)
{
	if (!root)
		return NULL;
	struct TreeNode *tmp = invertTree(root->left);
	root->left = invertTree(root->right);
	root->right = tmp;
	return root;
}

int main(void)
{
	int nums[] = {2, 1, 3};
	int len = sizeof(nums)/sizeof(nums[0]);
	TreeNode *head = NULL;
	for (int i = 0; i < len; i++)
		init_bst(&head, nums[i]);
	show_tree(head);
	head = invertTree(head);
	show_tree(head);
	release_tree(head);
	return 0;
}
