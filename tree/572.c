#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	TreeNode *p = NULL;
	TreeNode *q = NULL;
	
	p = create_node(3);
	p->left = create_node(4);
	p->right = create_node(5);
	p->left->left = create_node(1);
	p->left->right = create_node(2);

	q = create_node(4);
	q->left = create_node(1);
	q->right = create_node(2);
	show_tree(p);
	show_tree(q);
	printf("is sub tree %d \n", is_subtree(p, q));
	//printf("is same tree %d \n", is_sametree_ite(q, q));
	release_tree(p);
	release_tree(q);
	return 0;
}
