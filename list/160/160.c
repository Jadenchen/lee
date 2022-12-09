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

list *find_connect(list *headA, list *headB)
{
	int lenA = 0;
	int lenB = 0;
	int len = 0;
	list *cmp = NULL;
	list *ocmp = NULL;
	list *find = NULL;
	if (!headA || !headB) 
		return NULL;

	//! same length
	lenA = get_len(headA);
	lenB = get_len(headB);
	
	if (lenA > lenB) {
		len = lenA - lenB;
		cmp = headA;
		ocmp = headB;		
	} else {
		len = lenB - lenA;
	       	cmp = headB;
		ocmp = headA;
	}	

	while(len--)
		cmp = cmp->next;	

	while(cmp) {
		if (cmp->val == ocmp->val) {
			if (!find) 
				find = cmp;
		} else 
			find = NULL;
		cmp = cmp->next;
		ocmp = ocmp->next;
	}

	return find;
}

int main(void) 
{
	int target = 6;
	int num[] = {4, 1, 8, 4, 5};
	int num1[] = {5, 6, 1, 8, 4, 5};
	int len = sizeof(num)/sizeof(int);
	int len1 = sizeof(num1)/sizeof(int);
	list *pa = NULL;
	list *pa1 = NULL;
	list *pa2 = NULL;
	pa = create_list(num, len);
	pa1 = create_list(num1, len1);
	if (!pa ||!pa1)
		return -1;

	show_list(pa);
	show_list(pa1);
	
	pa2 = find_connect(pa, pa1);
	show_list(pa2);
	release_list(pa);
	release_list(pa1);
	return 0;
}
