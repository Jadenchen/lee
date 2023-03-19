#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

//! bst
void init_bst(struct TreeNode **head, int val);

void release_tree(struct TreeNode *head);

void show_tree(struct TreeNode *head);

//! level order
void init_levelorder_tree(TreeNode **head, int nums, int len);
void show_levelorder_tree(TreeNode *head);
#endif
