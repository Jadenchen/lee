#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void release_tree(struct TreeNode *head)
{
	if (!head)
		return;

	release_tree(head->left);
	release_tree(head->right);
	if (head)
		free(head);
}

static struct TreeNode *create_node(int val)
{
	struct TreeNode *new = calloc(1, sizeof(TreeNode));
	if (!new)
		return NULL;
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void init_bst(struct TreeNode **head, int val)
{
	struct TreeNode **indir = head;
	int rootval = 0;
	if (!(*indir)) {
		*indir = create_node(val);
		return;
	}

	rootval = (*indir)->val;
	if (rootval > val)
		init_bst(&(*indir)->left, val);
	else
		init_bst(&(*indir)->right, val);
}
static void show_leveltree(struct TreeNode *head, int level)
{
	if (!head || level == 0)
		return;
	if (level == 1)
		printf("%d ", head->val);
	else {
		if (head->left)
			show_leveltree(head->left, level-1);
		if (head->right)
			show_leveltree(head->right, level-1);
	}
}

int getheight(struct TreeNode *root)
{
	if (!root)
		return 0;
	int left = getheight(root->left);
	int right = getheight(root->right);
	return left > right ? left + 1 : right + 1;
}

void show_tree(struct TreeNode *head)
{
	if (!head)
		return;

	int height = getheight(head);
	for (int i = 1; i <= height; i++)
		show_leveltree(head, i);
	printf("\n");
}

