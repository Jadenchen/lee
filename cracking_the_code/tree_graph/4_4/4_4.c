#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tree {
	int val;
	struct tree *left;
	struct tree *right;
} tree;

static void postorder(tree *head)
{
	if (!head)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("%d ", head->val);
}

static void inorder(tree *head)
{
	if (!head)
		return;
	inorder(head->left);
	printf("%d ", head->val);
	inorder(head->right);
}

static void preorder(tree *head)
{
	if (!head)
		return;
	printf("%d ", head->val);
	preorder(head->left);
	preorder(head->right);
}

static tree *helper(int *nums, int left, int right)
{
	//! recursive
	if (left > right) 
		return NULL;

	//! choose left middle
	int p = (left + right)/2;

	tree *root = calloc(1, sizeof(tree));
	root->val = nums[p];
	root->left = helper(nums, left, p - 1);
	root->right = helper(nums, p + 1, right);
	return root;	
}

//! time O(N)
//! space O(logN) 

tree *sortedArrayToBST(int *nums, int length)
{
	return helper(nums, 0, length - 1);
}

int get_height(tree *root)
{
	if (!root)
		return 0;
	int left = get_height(root->left);
	int right = get_height(root->right);
	return left > right ? left + 1 : right + 1;
}

#define ERROR (65536)

int check(tree *root)
{
	if (!root)
		return 0;
	int left = check(root->left);
	if (left ==  ERROR) 
		return ERROR;
	int right = check(root->right);
	if (right == ERROR)
		return ERROR;
	if (abs(left - right) > 1) {
		return ERROR;	
	} else {
		return left > right ? left + 1 : right + 1;
	}
}

int isBalanced(tree *root)
{
	if (!root)
		return true;
	return check(root) != ERROR;
}

tree *new_node(int val)
{
	tree *new = calloc(1, sizeof(tree));
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void showlevel(tree *root, int level)
{
	if (level == 1)
		printf("%d ", root->val);
	else {
		if (root->left)
			showlevel(root->left, level - 1);
		if (root->right)
			showlevel(root->right, level - 1);
	}
}

void levelorder(tree *root)
{
	int height = get_height(root);

	printf("height %d \n", height);
	for (size_t i = 1; i <= height; i++) {
		showlevel(root, i);
	}
	printf("\n");
}

int main(void)
{
	//! 1 2 2 3 3 null null 4 4)
	tree *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(2);
	root->left->left = new_node(3);
	root->left->right = new_node(3);
	root->left->left->left = new_node(4);
	root->left->left->right = new_node(4);
	
	
	levelorder(root);
#if 0
	preorder(root);
	printf("\n");
//	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

#endif
	printf("balance %d \n", isBalanced(root));
	return 0 ;
}
