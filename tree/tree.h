#ifndef TREE_H
#define TREE_H
#include <stdbool.h>

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
int diameter_tree_ite(TreeNode *head);

//! max depth
int max_depth_tree(TreeNode *head);
int max_depth_tree_ite(TreeNode *head);

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

bool isValidBST(TreeNode *root);

TreeNode *buildTree(int *pre, int presize, int *inorder, int insize);

int kthSmallest(TreeNode* root, int k);
//! right side view
int* rightSideView(TreeNode* root, int* returnSize);
//! cnt good nodes
int goodNodes(TreeNode* root);
//! inorder save
int *inorder_save(TreeNode *root, int *returnSize);
//! preorder save
int *preorder_save(TreeNode *root, int *returnSize);
//! postorder save
int *postorder_save(TreeNode *root, int *returnSize);
//! invert tree 
TreeNode *inverttree(TreeNode *root);
//! merge tree 
TreeNode *merge_twotree(TreeNode *root1, TreeNode *root2);
#endif
