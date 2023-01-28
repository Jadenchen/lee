#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct stacknode {
	uint64_t a[STACK_SIZE];
	int top;
} stacknode;

typedef struct stack {
	int sum[STACK_SIZE];
	int top;
}stack;

void pushnode(stacknode *ps, void *addr)
{
	if (!ps)
		return;
	if (ps->top + 1 == STACK_SIZE)
		return;
	ps->a[ps->top++] = addr2uint(addr);

}

void *popnode(stacknode *ps)
{  
	return uint2addr(ps->a[--ps->top]); 
}

int isEmptynode(stacknode *st)
{
	return st->top == 0;
}

void *peek(stacknode *ps)
{
	int index = ps->top - 1;
	return uint2addr(ps->a[index]);
}

void push(stack *ps, int sum)
{
	ps->sum[ps->top++] = sum;
}

int pop(stack *ps)
{
	return ps->sum[--ps->top];
}
bool hasPathSum(struct TreeNode* root, int targetSum)
{
	if (!root)
		return false;
	stack sums;
	stacknode nodes;
	int cursum = 0;
	struct TreeNode *cur = NULL;
	memset(&sums, 0, sizeof(stack));
	memset(&nodes, 0, sizeof(stacknode));

	pushnode(&nodes, (void *)root);
	push(&sums, targetSum - root->val);

	while(!isEmptynode(&nodes)) {
		cur = (struct TreeNode *)popnode(&nodes);
		cursum = pop(&sums);
		if (!cur->left && !cur->right && cursum == 0) {
			return true;
		}

		if (cur->right) {
			pushnode(&nodes, cur->right);
			push(&sums, cursum -  cur->right->val);
		}

		if (cur->left) {
			pushnode(&nodes, cur->left);
			push(&sums, cursum -  cur->left->val);
		}
	}

	return false;
}
int main(void)
{
	return 0 ;
}
