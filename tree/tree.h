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

//! balance tree
int balance_tree(TreeNode *head);

//! diameter tree 
int diameter_tree(TreeNode *head);

//! max depth
int max_depth_tree(TreeNode *head);

//! symmetric tree 
int symmetric_rec_tree(TreeNode *head); 
int symmetric_ite_tree(TreeNode *head); 

//! same tree 
int is_sametree_ite(TreeNode *p, TreeNode *q);
//! subtree 
int is_subtree(TreeNode *p, TreeNode *q);
#endif
