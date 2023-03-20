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

struct TreeNode *create_node(int val);

int getheight(struct TreeNode *root);

//! level order tree 
void show_tree(struct TreeNode *head);

//! level order
void init_levelorder_tree(TreeNode **head, int *nums, int len);

//! dfs traversal
void dfs_traversal(TreeNode *head);

//! bfs traversal
void bfs_traversal(TreeNode *head);
#endif
