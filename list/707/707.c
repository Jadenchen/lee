#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list *next;
} list;

//! create_list
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

static void remove_node(list **pplist, int target)
{
#if 0
	list *remove = NULL;
	list **indir = pplist;
	int bfound = -1;
	if (!*pplist)
		return;
	
	while(*indir) {
		if ((*indir)->val == target) {
			remove = *indir;
			indir = &(*indir)->next;	
			free(remove);	
			continue;
		}
		indir = &(*indir)->next;
	}	
#else 
	list *prev = NULL;
	list *remove = NULL;
	list *curr = *pplist;
	while(curr) {
		if (curr->val == target) {
			if (curr == *pplist) {
				remove = curr;
				*pplist = (*pplist)->next;
				curr = *pplist;	
			} else {
				remove = curr;
				curr = curr->next;
				prev ->next = curr;
			}
			free(remove);
			continue;
		}
		prev = curr;
		curr = curr->next;
	}
#endif
}

list *new_ele(int target)
{
	list *new = calloc(1, sizeof(target));
	if (!new)
		return NULL;
	new->val = target;
	new->next = NULL;
	return new;
}

static void addHead(list **pplist, int target)
{
	list *new = NULL;
	new = new_ele(target);
       if (!new)
       		return;
      	if (!*pplist) 
		*pplist = new;
	else {
		new->next = *pplist;
		*pplist = new;
	}
}
static void addTail(list **pplist, int target)
{
	list *new = NULL;
	list **indir = NULL;
	indir = pplist;
	new = new_ele(target);
	if (!new)
		return;
	while((*indir)->next) {
		indir = &(*indir)->next;
	}
	(*indir)->next = new;
}

static int get_len(list *phead)
{
	int len = 0;
	while(phead) {
		len++;
		phead = phead->next;
	}
	return len;
}

static void addAtIndex(list **pplist, int index, int target)
{
	list *curr = NULL;
	list *prev = NULL;
	list **indir = NULL;
	list *next = NULL;
	int len = 0;
	list *new = NULL;
	if (!*pplist)
		return;
	curr = *pplist;
	len = get_len(curr);
	if (index > len)
		return;
	
	new = new_ele(target);
	if (!new)
		return;

	indir = pplist;
	if (index == 1) {
		next = (*indir)->next;
		new->next = (*indir);
		*indir = new;
	} else {
		while(--index) {
			indir = &(*indir)->next;	
		}

		next = (*indir)->next;
		(*indir)->next = new;
		if (next)
			new->next = next;
	}
}

static void delAtIndex(list **pplist, int index)
{
	list **indir = NULL;
	list *remove = NULL;
	list *next = NULL;
	int len = 0;
	if (!*pplist)
		return;

	len = get_len(*pplist);
	if (index > len)
		return;

	indir = pplist;
	if (index == 1) {
		remove = *indir;
		*indir = (*indir)->next; 
		free(remove);
	} else {
		while(--index) 
			indir = &(*indir)->next;
		remove = (*indir)->next;
		if (remove)
			free(remove);
		if ((*indir)->next && (*indir)->next->next)
			(*indir)->next = (*indir)->next->next;
	}
}

int main(void) 
{
	int num[] = {1, 2, 6, 3, 4, 5, 6};
	///int num[] = {6, 2, 6, 3, 4, 5, 6};
	//int num[] = {6, 6};

	//! 1->2->6->3->4->5->6
	//
	int len = sizeof(num)/sizeof(int);
	list *pa = NULL;
	int target = 6;
	int index = 3;
	
	pa = create_list(num, len);
	if (!pa)
		return -1;
	show_list(pa);
	printf("remove\n");
	remove_node(&pa, target);
	show_list(pa);
	target = 8;
	printf("add head \n");	
	addHead(&pa, target);
       	show_list(pa);	
	target = 9;
	printf("add taile\n");
	addTail(&pa, target);
	show_list(pa);
	printf("add index 3\n");
	target = 10;
	index = 3;
	addAtIndex(&pa, index, target);	
	show_list(pa);
	printf("add index 1\n");
	target = 11;
	index = 1;
	addAtIndex(&pa, index, target);	
	show_list(pa);

	printf("re index 3\n");
	index = 3;
	delAtIndex(&pa, index);
	show_list(pa);

	printf("re index 1\n");
	index = 1;
	delAtIndex(&pa, index);
	show_list(pa);
	release_list(pa);
	return 0;
}
