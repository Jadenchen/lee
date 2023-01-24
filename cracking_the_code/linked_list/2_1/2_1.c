#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list *next;
} list;

//! return kth 
void removedup(list *head)
{
	

}

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
#endif
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
	int a[] = {1, 2, 3, 3, 4, 4, 5};
	int len = sizeof(a)/sizeof(int);
	list *head = NULL;
	for (int i = 0; i < len; i++) {
		init_list(&head, a[i]);
	}	

	show(head);
	head = deleteDuplicates2(head);
	show(head);
	return 0;
}
