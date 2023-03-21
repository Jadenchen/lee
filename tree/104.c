#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	int nums[] = {3,9,20,15,7};
	int len = sizeof(nums)/sizeof(nums[0]);
	TreeNode *head = NULL;
	head = create_node(nums[0]);
	head->left = create_node(nums[1]);
	head->right = create_node(nums[2]);
	head->left->left = NULL;
	head->left->right = NULL;
	head->right->left = create_node(nums[3]);
	head->right->right = create_node(nums[4]);
	show_tree(head);
	printf("max depth %d \n", max_depth_tree(head));
	release_tree(head);
	return 0;
}

