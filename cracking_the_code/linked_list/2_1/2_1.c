#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct list {
	int val;
	struct list *next;
} list;

void init_list(list **head, int val)
{
	list **indir = head;
	list *new = calloc(1, sizeof(list));
	new->val = val;
	new->next = NULL;
	while(*indir) {
		indir = &(*indir)->next;
	}
	*indir = new;
}

void show(list *head)
{
	list *cur = head;
	while(cur) {
		printf("%d ", cur->val);
		cur = cur->next;
	}	
	printf("\n");
}

int get_len(list *head)
{
	list *cur = head;
	int cnt = 0;
	while(cur) {
		cnt++;
		cur = cur->next;
	}
	return cnt;
}
//! leetcode 83
list * deleteDuplicates(list* head)
{
	list *cur = NULL;
	list *next = NULL;
	list *remove = NULL;
	if (!head || !head->next) 
		return head;

	cur = head;
	while(cur) {
		next = cur->next;
		while(next && cur->val == next->val) {
			remove = next;	
			cur->next = remove->next;
			next = remove->next;
			remove->next = NULL;
		}
		cur = next;
	}
	return head;
}

//! leetcode 83
list* deleteDuplicates2(list* head)
{
#if 0
	list *cur = NULL;
	list *remove = NULL;
	list *next = NULL;
	list *prev = NULL;
	int isdup = 0;
	if (!head || !head->next)
		return head;

	cur = head;
	while(cur) {
		next = cur->next;
		while(next && cur->val == next->val) {
			remove = next;
			cur->next = remove->next;
			next = remove->next;
			remove->next = NULL;
			isdup = 1;
		}

		if (isdup) {
			if (prev) {
				remove = cur;
				prev->next = remove->next;
				cur = remove->next;
				remove->next = NULL;
			} else {
				remove = cur;
				cur = remove->next;
				head = cur;
				remove->next = NULL;
			}
			isdup = 0;
		} else {
			prev = cur;
			cur = next;	
		}
	}

	return head;
#else
	list **indir = &head;
	if (!head || !head->next)
		return head;

	while(*indir) {
		if ((*indir)->next && (*indir)->val == (*indir)->next->val) {
			list *tmp = (*indir)->next;
			while(tmp && tmp->val == (*indir)->val) 
				tmp = tmp->next;
			*indir = tmp;
		} else {
			indir = &(*indir)->next;
		}
	}
	return head;
#endif
}

list *merge(list *left, list *right)
{
	list *head;
	list **indir = &head;
	for (; left && right; indir = &(*indir)->next) {
		if (left->val > right->val) {
			*indir = right;
			right = right->next;
		} else {
			*indir = left;
			left = left->next;
		}
	}	
	*indir = (list *)((uintptr_t) left | (uintptr_t)right);
	return head;
}

list *merge_list(list *head)
{
	list *slow = NULL;
	list *fast = NULL;
	list *mid = NULL;
	if (!head || !head->next)
		return head;

	slow = head;
	for (fast = slow->next; fast && fast->next; fast = fast->next->next)
		slow = slow->next;
	mid = slow->next;
	slow->next = NULL;
	list *left = merge_list(head);
	list *right = merge_list(mid);
	return merge(left, right);
}

void mergesort(list **head)
{
	*head = merge_list(*head);
}

//! leetcode 1836
list *deleteDuplicates3(list *head)
{
#if 0
	time over
	list *cur = NULL;
	list **indir = NULL;
	list *prev = NULL;
	list *cmp = NULL;
	int index = 0;
	int cmpindex = 0;

	int len = 0;
	if (!head || !head->next)
		return head;
	len = get_len(head);
	int dup[len];

	memset(dup, 0, sizeof(int)*len);
	cur = head;

	while(cur) {
		cmp = cur->next;
		cmpindex = index + 1;
		while(cmp) {
			if (cmp->val == cur->val) {
				//! set dup index
				dup[index] = 1;
				dup[cmpindex] = 1;
			}
			cmp = cmp->next;
			cmpindex++;
		}

		cur = cur->next;
		index++;
	}

	for (int i = 0; i < len; i++) {
		printf("%d ", dup[i]);	
	}
	printf("\n");
	
	cur = head;
	head = NULL;
	indir = &head;
	for (int i = 0; i < len; i++) {
		if (dup[i] == 0) {
			printf("!!!! \n");
			*indir = cur;
			indir = &(*indir)->next;
		} 
		cur = cur->next;	
	}
	//! last
	(*indir) = NULL;

	return head;
#endif
	list *cur = NULL;
	list **indir = NULL;
	int hash[10001] = {0};
	
	if (!head || !head->next)
		return head;

	cur = head;
	while(cur) {
		hash[cur->val]++;
		cur = cur->next;
	}

	cur = head;
	head = NULL;
	indir = &head;
	while(cur) {
		if (hash[cur->val] == 1) {
			*indir = cur;
			indir = &(*indir)->next;
		}

		cur = cur->next;
	}

	*indir = NULL;
	return head;
}

int main(void)
{
#if 0
	int a[3] = {1, 1, 2};
	int len = sizeof(a)/sizeof(int);
	list *head = NULL;
	for (int i = 0; i < len; i++) {
		init_list(&head, a[i]);
	}	

	show(head);
	head = deleteDuplicates(head);
	show(head);
#endif
#if 0
	int a[] = {1, 2, 3, 3, 4, 4, 5};
	int len = sizeof(a)/sizeof(int);
	list *head = NULL;
	for (int i = 0; i < len; i++) {
		init_list(&head, a[i]);
	}	

	show(head);
	head = deleteDuplicates2(head);
	show(head);
#endif
	int a[] = {1, 2, 3, 2};
	int len = sizeof(a)/sizeof(int);
	list *head = NULL;
	for (int i = 0; i < len; i++) {
		init_list(&head, a[i]);
	}	

	show(head);
	head = deleteDuplicates3(head);
	show(head);
	return 0;
}
