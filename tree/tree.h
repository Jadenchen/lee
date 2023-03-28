#ifndef TREE_H
#define TREE_H

#define MAX(a, b) (a) > (b) ? (a) : (b)
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
//! symmetric tree
int symmetric_rec_tree(TreeNode *head);
int symmetric_ite_tree(TreeNode *head);

//!Lowest Common Ancestor of a Binary Search Tree 
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q);

 //!Lowest Common Ancestor of a Binary Search Tree 
TreeNode* lowestCommonAncestor_ite(TreeNode* root,TreeNode* p,TreeNode* q);
 
 //! level order 
int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes);
#endif
