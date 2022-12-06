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

static void swap_twonode(list **pplsit)
{
	if (!*pplist)
		return;

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
	printf("reverse\n");
	release_list(pa);
	return 0;
}
