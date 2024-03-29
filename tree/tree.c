#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "tree.h"
#include "queue.h"
#include "stack.h"
#include "stackad.h"

void release_tree(struct TreeNode *head)
{
	if (!head)
		return;

	release_tree(head->left);
	release_tree(head->right);
	if (head)
		free(head);
}

struct TreeNode *create_node(int val)
{
	struct TreeNode *new = calloc(1, sizeof(TreeNode));
	if (!new)
		return NULL;
	new->val = val;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void init_bst(struct TreeNode **head, int val)
{
	struct TreeNode **indir = head;
	int rootval = 0;
	if (!(*indir)) {
		*indir = create_node(val);
		return;
	}

	rootval = (*indir)->val;
	if (rootval > val)
		init_bst(&(*indir)->left, val);
	else
		init_bst(&(*indir)->right, val);
}
static void show_leveltree(struct TreeNode *head, int level)
{
	if (!head || level == 0)
		return;
	if (level == 1)
		printf("%d ", head->val);
	else {
		if (head->left)
			show_leveltree(head->left, level-1);
		if (head->right)
			show_leveltree(head->right, level-1);
	}
}

int getheight(struct TreeNode *root)
{
	if (!root)
		return 0;
	int left = getheight(root->left);
	int right = getheight(root->right);
	return left > right ? left + 1 : right + 1;
}

void show_tree(struct TreeNode *head)
{
	if (!head)
		return;

	int height = getheight(head);
	for (int i = 1; i <= height; i++)
		show_leveltree(head, i);
	printf("\n");
}

static void create_level_tree(TreeNode **head, int val, queue *pq)
{
	TreeNode *new = create_node(val);
	TreeNode *cur = peek_queue(pq);
	if (!*head) {
		*head = new;
	} else if (cur && cur->left == NULL) {
		cur->left = new;
	} else if (cur && cur->right == NULL) {
		cur->right = new;
		//TreeNode *tmp = NULL;
		//tmp = pop_queue(pq);
	}
	push_queue(pq, (void *)new);
}

//! level order
void init_levelorder_tree(TreeNode **head, int *nums, int len)
{
	if (!nums || !len)
		return;
	queue q;
	memset(&q, 0, sizeof(queue));
	for (int i = 0; i < len; i++) {
		create_level_tree(head, nums[i], &q);
	}
}

//! dfs traversal
void dfs_traversal(TreeNode *head)
{
	stack s;
	if (!head)
		return;
	//! init stack
	init_stack(&s);
	push_stack(&s, (void *)head);

	while(!empty_stack(&s)) {
		TreeNode *tmp = pop_stack(&s);
		printf("%d ", tmp->val);
		if (tmp->right)
			push_stack(&s, (void *)tmp->right);
		if (tmp->left)
			push_stack(&s, (void *)tmp->left);

	}
	printf("\n");
}


void bfs_traversal(TreeNode *head)
{
	queue q;
	if (!head)
		return;
	init_queue(&q);
	push_queue(&q, (void *)head);
	while(!empty_queue(&q)) {
		TreeNode *cur = (TreeNode *)pop_queue(&q);
		printf("%d ", cur->val);
		if (cur->left)
			push_queue(&q, (void *)cur->left);

		if (cur->right)
			push_queue(&q, (void *)cur->right);
	}
	printf("\n");
}

static int check_bal(TreeNode *cur)
{
	int lh = getheight(cur->left);
	int rh = getheight(cur->right);
	int dif = abs(lh - rh);
	return dif >= 2;
}

int balance_tree(TreeNode *head)
{
	int balance = 1;
	stack s;
	if (!head)
		return 1;
	init_stack(&s);
	push_stack(&s, (void *)head);
	while(!empty_stack(&s)) {
		TreeNode *cur = pop_stack(&s);
		if (check_bal(cur)) {
			balance = 0;
			break;
		}

		if (cur->right)
			push_stack(&s, cur->right);
		if (cur->left)
			push_stack(&s, cur->left);
	}
	release_stack(&s);
	return balance;
}

//   1
//  2 3
// 4 5
int getnode(TreeNode *head)
{
	int sum = 0;
	if (!head)
		return sum;

	stack s;
	init_stack(&s);
	push_stack(&s, head);
	while(!empty_stack(&s)) {
		TreeNode *cur = pop_stack(&s);

		if (cur->right) {
			push_stack(&s, cur->right);
		}

		if (cur->left) {
			push_stack(&s, cur->left);
		}

	}

	return sum;
}

static void longdis(TreeNode *head, int *pdiameter)
{
	if (!head)
		return;
	int left = 0;
	int right = 0;
	longdis(head->left, &left);
	longdis(head->right, &right);
	*pdiameter = MAX(left, right);
	//*pdiameter = MAX(*pdiameter, left + right);
	//return (MAX(left, right)) + 1;
	*pdiameter = MAX(1 + left + right, *pdiameter);
}

int diameter_tree(TreeNode *head)
{
	int diameter = 0;
	if (!head)
		return diameter;

	longdis(head, &diameter);
	return diameter;
}

static int get_dia(TreeNode *root)
{
	int height = 0;
	queue q;
	if (!root)
		return height;
	
	init_queue(&q);
	height++;
	push_queue(&q, root);
	while(!empty_queue(&q)) {
		TreeNode *cur = pop_queue(&q);
		if (cur->left || cur->right) {
			height++;
			if (cur->left)
				push_queue(&q, cur->left);
			if (cur->right)
				push_queue(&q, cur->right);
		}
	}
	return height;
}

int diameter_tree_ite(TreeNode *root)
{
	int diameter = 0;
	if (!root)
		return diameter;
	int left = get_dia(root->left);
	int right = get_dia(root->right);
	diameter = left + right + 1;
	return diameter;
}

int max_depth_tree(TreeNode *head)
{
	if (!head)
		return 0;

	int left_depth = max_depth_tree(head->left);
	int right_depth = max_depth_tree(head->right);
	return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

int max_depth_tree_ite(TreeNode *head)
{
	int height = 0;
	queue q;
	if (!head)
		return height;

	init_queue(&q);
	height++;
	push_queue(&q, head);
	while(!empty_queue(&q)) {
		TreeNode *cur = pop_queue(&q);
		if (cur->left || cur->right) {
			height++;
			if (cur->left) 
				push_queue(&q, cur->left);
			if (cur->right)
				push_queue(&q, cur->right);
		}
	}

	return height;
}

int symmetric_rec(TreeNode *left, TreeNode *right)
{
	if (left == NULL && right == NULL)
		return 1;

	if (left == NULL || right == NULL)
		return 0;

	if (left->val != right->val)
		return 0;

	int resl = symmetric_rec(left->left, right->right);
	int resr = symmetric_rec(left->right, right->left);
	//printf("l %d r %d \n", resl, resr);
	return resl & resr;
}

int symmetric_rec_tree(TreeNode *head)
{
	if (!head)
		return 1;

	return symmetric_rec(head->left, head->right);
}

int symmetric_ite_tree(TreeNode *head)
{
	//!   1
	//!  2 2
	//!3 4 4 3
	bool symmetric = true;
	if (!head)
		return symmetric;
	queue q;
	init_queue(&q);
	push_queue(&q, (void *)head->left);
	push_queue(&q, (void *)head->right);

	while(!empty_queue(&q)) {
		TreeNode *curl = (TreeNode *) pop_queue(&q);
		TreeNode *curr = (TreeNode *) pop_queue(&q);
		if (curl && curr) {
			if (curl->val != curr->val) {
				symmetric = false;
				break;
			}
		}

		if (curl->left && curr->right) {
			push_queue(&q, curl->left);
			push_queue(&q, curr->right);
		} else if (curl->left || curr->right) {
				symmetric = false;
				break;
		}
		if (curl->right && curr->left) {
			push_queue(&q, curl->right);
			push_queue(&q, curr->left);
		} else if (curl->right || curr->left) {
			symmetric = false;
			break;
		}
	}

	release_queue(&q);
	return symmetric;
}

int check_same(TreeNode *p1, TreeNode *p2)
{
	if ((!p1 && p2) || (p1 && !p2)) {
		return 0;
	}
	return p1->val == p2->val;
}

int is_sametree_ite(TreeNode *p, TreeNode *q)
{
	bool same = true;
	if (!p && !q)
		return true;
	if ((!p && q) || (p && !q))
		return false;
	queue qu;
	init_queue(&qu);
	push_queue(&qu, (void *)p);
	push_queue(&qu, (void *)q);

	while(!empty_queue(&qu)) {
		TreeNode *cur1 = pop_queue(&qu);
		TreeNode *cur2 = pop_queue(&qu);

		if (!cur1 && !cur2)
			continue;

		if (!check_same(cur1, cur2)) {
			same = false;
			break;
		}

		push_queue(&qu, cur1->left);
		push_queue(&qu, cur2->left);
		push_queue(&qu, cur1->right);
		push_queue(&qu, cur2->right);
	}

	release_queue(&qu);
	return same;
}

bool chk_sub(TreeNode *p1, TreeNode *p2)
{
	bool find = false;
	queue qu;
	init_queue(&qu);
	push_queue(&qu, (void *)p1);
	while(!empty_queue(&qu)) {
		TreeNode *cur = pop_queue(&qu);
		if (is_sametree_ite(cur, p2)) {
			find = true;
			break;
		}
		if (cur->left)
			push_queue(&qu, cur->left);
		if (cur->right)
			push_queue(&qu, cur->right);
	}
	release_queue(&qu);
	return find;
}

int is_subtree(TreeNode *p, TreeNode *q)
{
	if (!p && !q)
		return true;

	if ((p && !q) || (!p && q))
		return false;

	//! chk left
	bool left = chk_sub(p->left, q);
	//! chk right
	bool right = chk_sub(p->right, q);
	return left | right;
}

static TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
	TreeNode *anc = NULL;
	if (!root)
		return anc;
	if (root->val > p->val && root->val > q->val) {
		lca(root->left, p, q);
	} else if (root->val < p->val && root->val < q->val) {
		lca(root->right, p, q);
	} else {
		anc = root;
	}

	return anc;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode *anc = NULL;
	if (!root)
		return anc;
	anc = lca(root, p, q);
	return anc;
}

TreeNode* lowestCommonAncestor_ite(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode *anc = NULL;
	stack s;
	init_stack(&s);
	push_stack(&s, (void *)root);
	while(!empty_stack(&s)) {
		TreeNode *cur = pop_stack(&s);
		if (cur->val > p->val && cur->val > q->val) {
			if (cur->left)
				push_stack(&s, (void *)cur->left);
		} else if (cur->val < p->val && cur->val < q->val) {
		       if (cur->right)
			       push_stack(&s, (void *)cur->right);
		} else {
			anc = cur;
			break;
		}
	}
	return anc;
}

void addresult(int *result, TreeNode *root, int level, int *collen)
{
	if (!root)
		return;

	if (level == 1) {
		result[*collen] = root->val;
		*collen = *collen + 1;
	} else {
		if (root->left) {
			addresult(result, root->left, level - 1, collen);
		}
		if (root->right) {
			addresult(result, root->right, level - 1, collen);
		}
	}
}

int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	int **result = NULL;
	int height = 0;
	if (!root) {
		*returnSize = 0;
		return NULL;
	}

	height = *returnSize = getheight(root);
	*returnColumnSizes = calloc(height, sizeof(int));

	result = calloc(*returnSize, sizeof(int *));
	for (int i = 0; i < *returnSize; i++) {
		result[i] = calloc(20, sizeof(int));
	}

	for (int i = 1; i <= height;i++) {
		int collen = 0;
		addresult(result[i - 1], root, i, &collen);
		(*returnColumnSizes)[i - 1] = collen;
	}
	return result;
}

static void inorder(stack *s, TreeNode *root, int *len)
{
	if (root->left)
		inorder(s, root->left, len);

	if (root) {
		push_stack(s, (void *)root);
		*len = *len + 1;
	}

	if (root->right)
		inorder(s, root->right, len);
}

bool isValidBST(TreeNode *root)
{
	int len = 0;
	bool valid = true;
	stack s;
	memset(&s, 0, sizeof(stack));
	inorder(&s, root, &len);
	TreeNode *cur = (TreeNode *)pop_stack(&s);
	int tmp = cur->val;
	for (int i = 1; i < len; i++) {
		cur = pop_stack(&s);
		int cmp = cur->val;
		if (tmp <= cmp) {
			valid = false;
			break;
		}
		tmp = cmp;
	}
	return valid;
}

int findindex(int rootval, int *inorder, int left, int right)
{
	int index = 0;
	for (int i = left; i <= right; i++) {
		if (rootval == inorder[i]) {
			index = i;
			break;
		}
	}
	return index;
}

TreeNode *build(int *preorder, int *inorder, int left, int right, int *index)
{
	TreeNode *root = NULL;
	int orderindex = 0;
	if (left > right)
		return root;

	root = create_node(preorder[*index]);
	*index = *index + 1;
	//printf ("index %d \n", *index);
	if (left == right)
		return root;


	orderindex = findindex(root->val, inorder, left, right);
	//printf ("index %d  orderindex %d  root val %d  \n",
//			*index, orderindex, root->val);
	root->left = build(preorder, inorder, left, orderindex - 1, index);
	root->right = build(preorder, inorder, orderindex + 1, right, index);
	return root;
}

TreeNode *buildTree(int *preorder, int presize, int *inorder, int insize)
{
	int index = 0;
	//printf("presize %d insize %d \n", presize, insize);
	return build(preorder, inorder, 0, presize - 1, &index);
}

static void getkthsmall(TreeNode *root, int k, int *a)
{
	static int cnt = 0;

	if (!root)
		return;
	if (root->left)
		getkthsmall(root->left, k, a);
	a[cnt] = root->val;
	cnt++;
	if (root->right)
		getkthsmall(root->right, k, a);
}

int kthSmallest(TreeNode *root, int k)
{
	int arr[1000] = {0};
	getkthsmall(root, k, arr);
	for (int i = 0; i < 20; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return arr[k - 1];
}

static void getresult(TreeNode *root, int *a, int level, int *cnt)
{
	if (!root || level == 0)
		return;

	if (level == 1) {
		a[*cnt] = root->val;
		*cnt = *cnt + 1;
	} else {
		if (root->left)
			getresult(root->left, a, level - 1, cnt);
		if (root->right)
			getresult(root->right, a, level - 1, cnt);
	}
}

int* rightSideView(TreeNode* root, int* returnSize)
{
	int *result = NULL;
	int arr[100][100];
	int colum[100] = {0};
	if (!root) {
		*returnSize = 0;
		return NULL;
	}

	*returnSize = getheight(root);
	printf("height %d \n", *returnSize);
	result = calloc(*returnSize, sizeof(int));
	for (int i = 0; i < *returnSize; i++)
		memset(arr[i], 0, sizeof(int)*100);

	for (int i = 1; i <= *returnSize; i++) {
		int len = 0;
		getresult(root, arr[i-1], i, &len);
		colum[i - 1] = len;
	}

	for (int i = 0; i < *returnSize; i++) {
		result[i] = arr[i][colum[i] - 1];
	}
	return result;
}

static void getgood(TreeNode *root, int *cnt)
{
	stackad s;
	stack_info s_info;
	stack_info *ptcur_info;
	init_stackad(&s);
	s_info.data = addr2uint(root);
	s_info.val = root->val;
	push_stackad(&s, &s_info);
	while(!empty_stackad(&s)) {
		ptcur_info = pop_stackad(&s);	
		TreeNode *cur_node = uint2addr(ptcur_info->data);
		int min_val = ptcur_info->val;
		//printf("mi %d val %d \n", min_val, cur_node->val);
		if (min_val <= cur_node->val) {
			min_val = cur_node->val;
			*cnt = *cnt + 1;
		}
		if (cur_node->right) {
			s_info.data = addr2uint(cur_node->right);
			s_info.val = min_val;
			push_stackad(&s, &s_info);
		}
		if (cur_node->left) {
			s_info.data = addr2uint(cur_node->left);
			s_info.val = min_val;
			push_stackad(&s, &s_info);
		}
	}

	release_stackad(&s);
}

int goodNodes(TreeNode* root)
{
	//!   3 /3
	//!  3 /3 
	//! 4 /3 2  /3
	int cnt = 0;
	if (!root)
		return cnt;
	getgood(root, &cnt);
	return cnt;
}

static void inorder_save_node(stack *s, TreeNode *root, int *len)
{
	if (!root)
		return;
	inorder_save_node(s, root->left, len);
	if (root) {
		push_stack(s, root);
		*len = *len + 1;
	}
	inorder_save_node(s, root->right, len);
}

int *inorder_save(TreeNode *root, int *returnSize)
{
	stack s;
	int node_size = 0;
	int *result = NULL;
	if (!root) {
		*returnSize = node_size;
		return result;
	}

	init_stack(&s);
	inorder_save_node(&s, root, &node_size);
	*returnSize = node_size;
	result = calloc(node_size, sizeof(int)); 
	for (int i = 0; i < node_size; i++) {
		TreeNode *cur = pop_stack(&s);
		result[node_size - 1 - i] = cur->val; 
	}
	release_stack(&s);
	return result;
}

static void preorder_save_node(stack *s, TreeNode *root, int *len)
{
	if (!root)
		return;
	push_stack(s, root);
	*len = *len + 1;
	preorder_save_node(s, root->left, len);
	preorder_save_node(s, root->right, len);
}

int *preorder_save(TreeNode *root, int *returnSize)
{
	stack s;
	int node_size = 0;
	int *result = NULL;
	if (!root) {
		*returnSize = node_size;
		return result;
	}

	init_stack(&s);
	preorder_save_node(&s, root, &node_size);
	*returnSize = node_size;
	result = calloc(node_size, sizeof(int)); 
	for (int i = 0; i < node_size; i++) {
		TreeNode *cur = pop_stack(&s);
		result[node_size - 1 - i] = cur->val; 
	}
	release_stack(&s);
	return result;
}

static void postorder_save_node(stack *s, TreeNode *root, int *len)
{
	if (!root)
		return;
	postorder_save_node(s, root->left, len);
	postorder_save_node(s, root->right, len);
	push_stack(s, root);
	*len = *len + 1;
}

int *postorder_save(TreeNode *root, int *returnSize)
{
	stack s;
	int node_size = 0;
	int *result = NULL;
	if (!root) {
		*returnSize = node_size;
		return result;
	}

	init_stack(&s);
	postorder_save_node(&s, root, &node_size);
	*returnSize = node_size;
	result = calloc(node_size, sizeof(int)); 
	for (int i = 0; i < node_size; i++) {
		TreeNode *cur = pop_stack(&s);
		result[node_size - 1 - i] = cur->val; 
	}
	release_stack(&s);
	return result;
}

static void swap(TreeNode *root)
{
	TreeNode *tmp = NULL;

	if (root->right)
		tmp = root->right;
	root->right = root->left;
	root->left = tmp;
}

TreeNode *inverttree(TreeNode *root)
{
	//!     2          2
	//!    1 3 ->     3 1 
	//!  4 5 7 8    5 4 8 7
	//!
	queue q;
	
	if (!root)
		return NULL;
	init_queue(&q);
	push_queue(&q, (void *)root);
	while(!empty_queue(&q)) {
		TreeNode *cur = pop_queue(&q);
		if (cur->left)
			push_queue(&q, (void *)cur->left);
		if (cur->right)
			push_queue(&q, (void *)cur->right);
		swap(cur);
	}

	return root;
}

static void create_tree(TreeNode **root, TreeNode *cur1, TreeNode *cur2)
{

}

TreeNode *merge_func(TreeNode *root1, TreeNode *root2)
{

	TreeNode *merge = NULL;
#if 0
	queue q1;
	queue q2;
	init_queue(&q1);
	init_queue(&q2);
	while(!empty_queue(&q1) || !empty_queue(&q2)) {
		TreeNode *cur1 = pop_queue(&q1);
		TreeNode *cur2 = pop_queue(&q2); 
		create_tree(&merge, cur1, cur2);
		if (cur1->left)
			push_queue(&q1, (void *)cur1->left);
		if (cur2->left)
			push_queue(&q2, (void *)cur2->left);
		if (cur1->right)
			push_queue(&q1, (void *)cur1->right);
		if (cur2->right)
			push_queue(&q2, (void *)cur2->right);

	}
#endif
	return merge;
}

TreeNode *merge_twotree(TreeNode *root1, TreeNode *root2)
{
	TreeNode *merge = NULL;
	if (!root1 && !root2)
		return NULL;
	if (!root1)
		return root2;
	if (!root2)
		return root1;
	merge = merge_func(root1, root2);
	return merge;
}
