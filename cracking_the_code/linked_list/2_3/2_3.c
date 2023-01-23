#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list *next;
} list;


int getlen(list *head)
{
	int len = 0;
	list *curr = head;
	while(curr) {
		len++;
		curr = curr->next;
	}
	return len;
}

void del(list *curr, list *remove)
{
	if (remove->next)
		curr->next = remove->next;
	else 
		curr->next = NULL;
}

//! remove mid (leetcode: 2095)
//! time O(n) space O(1)
list *removemid(list *head)
{
	list *slow = NULL;
	list *fast = NULL;
	list *prev = NULL;
	list *mid = NULL;
	if (!head || !head->next)
		return head;
	
	slow = head;
	fast = head;
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	mid = slow;
	prev = head;
	while(prev && prev->next != mid) {
		prev = prev->next;
	}
	if (prev->next) 
		prev->next = mid->next;
	else 
		head = head->next;
	return head;
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
	while(head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

int main(void)
{
	int a[4] = {1, 2, 3, 4};
	int len = sizeof(a)/sizeof(int);
	list *head = NULL;
	for (int i = 0; i < len; i++) {
		init_list(&head, a[i]);
	}	

	show(head);
	head = removemid(head);
	show(head);
	return 0;
}

