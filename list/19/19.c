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

int getlen(list *head)
{
	list *cur = head;
	int len = 0;
	while(cur) {
		len++;
		cur = cur->next;
	}
	return len;
}

list *reverse(list *head)
{
	list *cur = NULL;
	list *prev = NULL;
	list *next = NULL;
	if (!head || !head->next)
		return head;
	cur = head;
	while(cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
	return head;
}
list * removeNthFromEnd(list* head, int n)
{
	list **indir = NULL;
	list *remove = NULL;
	int idx = 1;
	int len = 0;
	if (!head)
		return NULL;
	head = reverse(head);
	remove = head;
	while(remove) {
		if (idx == n)
			break;
		remove = remove->next;
		idx++;
	}

	head = reverse(head);
	indir = &head;
	while(*indir != remove)
		indir = &(*indir)->next;

	if (remove->next)
		*indir = remove->next;
	else
		*indir = NULL;
	return head;
}

int main(void)
{
#if 0
	int target = 6;
	int num[] = {1, 2, 3, 4, 5, 6};
	int len = sizeof(num)/sizeof(int);
	list *pa = NULL;
	pa = create_list(num, len);
	if (!pa)
		return -1;

	show_list(pa);
	printf("target %d \n", target);
	pa = remove_back(pa, target);
	show_list(pa);
	release_list(pa);
#endif
	int a[] = {1, 2, 3, 4, 5};
	int n = 2;
	int len = sizeof(a)/sizeof(int);
	list *head = create_list(a, len);
	show_list(head);
	head = removeNthFromEnd(head, n);
//	head = reverse(head);
	show_list(head);
	release_list(head);
	return 0;
}
