#include <stdio.h>
#include <stdlib.h>
#include "tree.h"



int main(void)
{
	int nums[] = {3,9,20, NULL,NULL,15,7};
	int len = sizeof(nums)/sizeof(nums[0]);
	TreeNode *head = NULL;
	init_levelorder_tree(&head, nums. len);
	show_tree(head);
	release_tree(head);
	return 0;
}
