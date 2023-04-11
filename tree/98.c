#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	TreeNode *p = NULL;

	p = create_node(2);
	p->left = create_node(1);
	p->right = create_node(3);

	//show_tree(p);
	printf("is bst %d \n", isValidBST(p));
	release_tree(p);
	return 0;
}
