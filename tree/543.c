#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5};
	int len = sizeof(nums)/sizeof(nums[0]);
	TreeNode *head = NULL;
	head = create_node(nums[0]);	
	head->left = create_node(nums[1]);
	head->right = create_node(nums[2]);
	head->left->left= create_node(nums[3]);
	head->left->right = create_node(nums[4]);
	show_tree(head);
	printf("dimeter tree num %d \n", diameter_tree(head));
	release_tree(head);
	return 0;
}
