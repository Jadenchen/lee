#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
#include "stack.h"

void release_tree(struct TreeNode *head)
{
	if (!head)
		return;

	release_tree(head->left);
	release_tree(head->right);
	if (head)
		free(head);
}

struct TreeNode *create_node(int val)
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

static void create_level_tree(TreeNode **head, int val, queue *pq)
{
	TreeNode *new = create_node(val);
	TreeNode *cur = peek_queue(pq);
	if (!*head) {
		*head = new;
	} else if (cur && cur->left == NULL) {
		cur->left = new;
	} else if (cur && cur->right == NULL) {
		cur->right = new;	
		TreeNode *tmp = NULL;
		tmp = pop_queue(pq); 
	}		
	push_queue(pq, (void *)new);
}

//! level order
void init_levelorder_tree(TreeNode **head, int *nums, int len)
{
	if (!nums || !len)
		return; 
	queue q;
	memset(&q, 0, sizeof(queue));
	for (int i = 0; i < len; i++) {
		create_level_tree(head, nums[i], &q);
	}
}

//! dfs traversal
void dfs_traversal(TreeNode *head)
{
	stack s;
	if (!head)
		return;
	//! init stack 
	init_stack(&s);
	push_stack(&s, (void *)head);

	while(!empty_stack(&s)) {
		TreeNode *tmp = pop_stack(&s);
		printf("%d ", tmp->val);
		if (tmp->right)
			push_stack(&s, (void *)tmp->right);
		if (tmp->left)
			push_stack(&s, (void *)tmp->left);

	}
	printf("\n");
}
	

void bfs_traversal(TreeNode *head)
{
	queue q;
	if (!head)
		return;
	init_queue(&q);
	push_queue(&q, (void *)head);
	while(!empty_queue(&q)) {
		TreeNode *cur = (TreeNode *)pop_queue(&q);	
		printf("%d ", cur->val);
		if (cur->left)
			push_queue(&q, (void *)cur->left);

		if (cur->right)
			push_queue(&q, (void *)cur->right);
	}
	printf("\n");
}
