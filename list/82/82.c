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
	while(head) {
		len++;
		head = head->next;
	}
	return len;
}

static void list_del(list *remove, list *prev)
{
	list *next = remove->next;
	if (prev)
		prev->next = next;	
	remove->next = NULL;
}

static void list_add(list *add, list *curr)
{
	list *next = curr->next;
	add->next = next;
	curr->next = add;
}

static list *remove_back(list *pa, int target)
{
	int len = 0;
	list *prev = NULL;
	list *curr = NULL;
	if (!pa)
		return NULL;
	len = get_len(pa);
	len = len - target;
	if (len < 0)
		return NULL;	
	curr = pa;	
	if (len == 0) {
		pa = curr->next;
	} else {
		for (size_t i = 0; i < len; i++) {
			prev = curr;
			curr = curr->next;
		}	
		list_del(curr, prev);
	}
	return pa;
}

void remove_node(list *curr, list *remove)
{
	list *next = remove->next;
	curr->next = next;
}	     

list *deleteDuplicates(list *head)
{
	//! use indirect pointer 
	list **indir = &head;
	if (!head || !head->next)
		return head;

	while(*indir) {
		if ((*indir)->next && (*indir)->next->val == (*indir)->val) {
			list *tmp = (*indir)->next;
			while(tmp && tmp->val == (*indir)->val)
				tmp = tmp->next;
			*indir = tmp;

		} else 
			indir = (*indir)->next;
	}

	return head;
}	

int main(void) 
{

	return 0;
}
