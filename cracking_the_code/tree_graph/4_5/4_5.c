#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

typedef struct tree {
	int val;
	struct tree *left;
	struct tree *right;
} tree;

typedef struct stack {
	uint64_t a[STACK_SIZE];
	int top;
} stack;

void push(stack *ptStack, void *addr)
{
	if (!ptStack)
		return;

	if (ptStack->top + 1 == STACK_SIZE) {
		return;
	}
	
	ptStack->a[ptStack->top] = addr2uint(addr);
	ptStack->top++;
}

void pop(stack *ptStack, uint64_t *data)
{
	if (!ptStack)
		return;

	if (ptStack->top - 1 < 0)
		return;

	ptStack->top--;	
	*data = ptStack->a[ptStack->top]; 
}	

int isEmpty(stack *ptStack)
{
	return ptStack->top == 0;
}

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

static void inorder_inter(tree *head)
{
	stack st;
	tree *curr = NULL;
	uint64_t tmp = 0;	
	memset(&st, 0, sizeof(stack));
	curr = head;
	while(curr || !isEmpty(&st)) {
		if (curr) {
			push(&st, (void *)curr);
			curr = curr->left;
		} else {
			//! pop
			pop(&st, &tmp);
		       	tree *pTmp = (tree *)uint2addr(tmp);	
			printf("%d ", pTmp->val);	
			curr = pTmp->right;
		}	
	}
	printf("\n");
}

static void preorder(tree *head)
{
	if (!head)
		return;
	printf("%d ", head->val);
	preorder(head->left);
	preorder(head->right);
}

static void preorder_inter(tree *head)
{
	stack st;
	tree *curr = NULL;
	uint64_t tmp = 0;
	if (!head)
		return;

	memset(&st, 0, sizeof(stack));
	push(&st,(void *)head);
	while(!isEmpty(&st)) {
		pop(&st, &tmp);
		curr = (tree *) uint2addr(tmp);
		printf(" %d ", curr->val); 	
		if (curr->right) {
			push(&st, (void *)curr->right);
		}
	       	if (curr->left) {
			push(&st, (void *)curr->left);	
		}
	}

	printf("\n");
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

void inorderput(tree *root, int *pa, int *cnt)
{
	if (!root)
		return;
	inorderput(root->left, pa, cnt);
	pa[*cnt] = root->val;
	*cnt = *cnt + 1;
	inorderput(root->right, pa, cnt);
}

int isValidBST(tree *root)
{
	//! inorder search 
	int a[1000] = {0};
	int cnt = 0;
	int isValid = 1;
	inorderput(root, a, &cnt);
	
	//! compare each element
	printf("cnt %d \n", cnt);
	cnt = cnt - 1;
	for (size_t i = 0; i < cnt; i++) {
		if (a[i] > a[i + 1]) {
			isValid = 0;
			break;
		}
	}
	return isValid;
}

int main(void)
{
	//   5 
	// 1   4 
	//    3 6 
	//
	// inorder 1 5 3 4 6
	tree *root = new_node(5);
	root->left = new_node(1);
	root->right = new_node(4);
	root->right->left = new_node(3);
	root->right->right = new_node(6);
	
	preorder_inter(root);
	inorder_inter(root);
	
#if 0
	preorder(root);
	printf("\n");
//	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	printf("balance %d \n", isBalanced(root));
#endif
	return 0 ;
}
