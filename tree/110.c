#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int balance_tree(TreeNode *head)
{
	if (!head)
		return 1;
	//!   3
	//!  9 20
	//! 11 12 15 7
	
}

int main(void)
{
	int nums[] = {3,9,20, 11,12,15,7};
	int len = sizeof(nums)/sizeof(nums[0]);
	TreeNode *head = NULL;
	init_levelorder_tree(&head, nums, len);
	printf("   3\n");
	printf("  9 20 \n");
	printf("11 12 15 17\n");
	printf("level\n");
	show_tree(head);
//	printf("is balance %d \n", balance_tree(head));
	printf("dfs\n");
	dfs_traversal(head);
	printf("bfs\n");
	bfs_traversal(head);
	release_tree(head);

		
#if 0
	head = create_node(3);
	head->left = create_node(9);
	head->left->left = create_node(20);
	show_tree(head);
	printf("is balance %d \n", balance_tree(head));
	release_tree(head);
#endif
	return 0;
}
