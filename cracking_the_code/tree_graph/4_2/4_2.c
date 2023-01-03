#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	int a[5] = {-10, -3, 0, 5, 9};
	int size = sizeof(a)/sizeof(int);
	
	tree *root = sortedArrayToBST(a, size);

	preorder(root);
	printf("\n");
//	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	return 0 ;
}
