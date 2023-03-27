#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
	//3,9,20,null,null,15,7
	TreeNode *head = create_node(3);
	int returnSize = 0;
	int *returnColmnSize = NULL;
	int **result = NULL;
	head->left = create_node(9);
	head->right = create_node(20);
	head->left->left = NULL;
	head->left->right = NULL;
	head->right->left = create_node(15);
	head->right->right = create_node(7);
	result = levelOrder(head, &returnSize, &returnColmnSize); 
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < returnColmnSize[i]; j++) {
			printf ("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	show_tree(head);
	release_tree(head);
	if (result) {
		for (int i = 0; i < returnSize; i++) {
			if (result[i]) 
				free(result[i]);
		}
	}

	if (returnColmnSize) free(returnColmnSize);
	return 0;
}

