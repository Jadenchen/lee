#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//! leet 101
//    1
//   / \
//  2   2
//   \   \
//   3    3
int main(void)
{
	TreeNode *head = create_node(1);
	head->left = create_node(2);
	head->right = create_node(2);
#if 0
	head->left->left = create_node(3);
	head->left->right = create_node(4);
	head->right->left = create_node(4);
	head->right->right = create_node(3);
#else 
	head->left->right = create_node(3);
	head->right->right = create_node(3);
#endif
	
	show_tree(head);
	printf("symmetric rec %d \n", symmetric_rec_tree(head));
	printf("iteration ite %d \n", symmetric_ite_tree(head));
	release_tree(head);
	return 0;
}

