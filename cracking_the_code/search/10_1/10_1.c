#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
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

uint64_t peek(stack *ptStack)
{
	int index = 0;
	if (ptStack->top == 0)
		return ERROR;
	
	index = ptStack->top - 1;
	return ptStack->a[index];
}

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

static void postorder_inter(tree *root)
{
	stack st;
	tree *curr = NULL;
	tree *lastvisited = NULL;
	uint64_t tmp;

	memset(&st, 0, sizeof(stack));
	curr = root;
	while(!isEmpty(&st) || curr) {
		if (curr) {
			push(&st, (void  *)curr);
			curr = curr->left;
		} else {
			tree *peeknode = (tree *)uint2addr(peek(&st));
			if (peeknode->right && lastvisited != peeknode->right) {
				curr = peeknode->right;
			} else {
				pop(&st, &tmp);
				lastvisited = (tree *) uint2addr(tmp);
				printf("%d ", lastvisited->val);
			}	
		}	
	}
	printf("\n");
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
		printf("%d ", curr->val); 	
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

void inorder_put(tree *root, int *pa, int *cnt)
{
	if (!root)
		return;
	inorder_put(root->left, pa, cnt);
	pa[*cnt] = root->val;
	*cnt = *cnt + 1;
	inorder_put(root->right, pa, cnt);
}

int isValidBst(tree *root)
{
	int a[STACK_SIZE] = {0};
	int cnt = 0;
	int isValid = 1;
	inorder_put(root, a, &cnt);
	//! compare
	cnt = cnt - 1;
	for (int i = 0; i <= cnt; i++) {
		if (a[i] >= a[i+1]) {
			isValid = 0;
			break;
		}
	}
	return isValid;
}

tree *lowestCommonAncestor(tree *root, tree *p, tree *q)
{
	tree *left = NULL;
	tree *right = NULL;
	if (root == p || root == q)
		return root;
	
	if (root->left)
		left = lowestCommonAncestor(root->left, p, q);
	if (root->right)
		right = lowestCommonAncestor(root->right, p, q);
	
	if (left && right)
		return root;
	return (left == NULL) ? right : left;	
}

//! time O (n) space O(n) if skewed tree 

#if 0
leetcode 235 
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    #if 0
     struct TreeNode *left = NULL;
     struct TreeNode *right = NULL;
    if (root == p || root == q)
        return root;
    if(root->left)
        left = lowestCommonAncestor(root->left, p, q);
    if (root->right)
        right = lowestCommonAncestor(root->right, p, q);
    if (left && right)
        return root;

    return (left == NULL) ? right : left;
    #endif
    int pval = p->val;
    int qval = q->val;

    int parval = 0;
    struct TreeNode *curr = root;
    struct TreeNode *anc = NULL;
    while(curr) {
        parval = curr->val;
        if (pval > parval && qval > parval) {
            curr = curr->right;
        } else if (pval < parval && qval < parval) {
            curr = curr->left;
        } else {
            anc = curr;
            break;
        }
    }

    return anc;
}
#endif

void merge(int *num1, int num1Size, int *num2, int num2Size, int n)
{
	int n1 = num1Size - num2Size;
	int a[n1];
	int b[num2Size];
	int i, j, k;
		
	for (i = 0; i < n1; i++)
		a[i] = num1[i];
	for (i = 0; i < num2Size; i++)
		b[i] = num2[i];

	i = 0;
	j = 0;
	k = 0;
	while(i < n1 && j < num2Size) {
		if (a[i] > b[j])
			num1[k++] = b[j++];
		else 
			num1[k++] = a[i++];
	}
	while(i < n1)
		num1[k++] = a[i++];
	while(j < num2Size) 
		num1[k++] = b[j++];
}

void show(int *pa, int len)
{
	for (size_t i = 0; i < len; i++)
		printf("%2d ", pa[i]);
	printf("\n");
}

int main(void)
{
	int a[] = {2, 4, 6, 0, 0 ,0};
	int b[] = {1, 3, 5};
	int alen = sizeof(a)/sizeof(int);
	int blen = sizeof(b)/sizeof(int);
	int n = alen - blen;
	merge(a, alen, b, blen, n);
	show(a, alen); 
	return 0 ;
}
