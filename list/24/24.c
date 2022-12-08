#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list *next;
} list;

static void new_node(list **pplist, int num)
{
	while(*pplist) {
		pplist = &(*pplist)->next;
	}

	*pplist = calloc(1, sizeof(list));
	if (!*pplist) {
		return;
	}

	(*pplist)->val = num;
	(*pplist)->next = NULL;
}

static void release_list(list *head)
{
	list *remove = NULL;
	if (!head)
		return;
	while(head) {
		remove = head;
		head = head->next;
		free(remove);
	}
}

static void show_list(list *head)
{
	while(head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

list *create_list(int *pa, int len)
{
	list *new = NULL;
	for (size_t i = 0; i < len; i++) {
		new_node(&new, pa[i]);
	}
	return new;
}	

static int get_len(list *head)
{
	int len = 0;
	if(!head)
		return len;
	while(head) {
		len++;
		head = head->next;
	}
	return len;
}

static list *swappairs(list *head)
{
	list *curr = head;
	list *next = NULL; 
	list *nn = NULL;
	int len = 0;	
	if (!head || !head->next)
		return NULL;
	len = get_len(head)
	len = len/2;
	next = curr->next;
	nn = next->next;

	for (size_t i = 0; i < len; i++) {
		//! list del
		list_del(curr);
		//! list_add
		list_add(curr, next);
		curr = nn;
		next = curr->next;
		nn = next->next;	
	}

	return head;
}

int main(void) 
{
	int num[] = {1, 2, 3, 4};
	int len = sizeof(num)/sizeof(int);
	list *pa = NULL;
	pa = create_list(num, len);
	if (!pa)
		return -1;
	
	show_list(pa);
	pa = swappairs(pa);
	show_list(pa);
	release_list(pa);
	return 0;
}
