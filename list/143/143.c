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

int hascycle(list *pa)
{
	list *slow = NULL;
	list *fast = NULL;
	int found = 0;
	if (!pa || !pa->next)
		return found;

	slow = pa;
	fast = slow->next;
	while(slow && fast && fast->next) {
		if (slow == fast) {
			found = 1;
			break;
		}
		slow = slow->next;
		fast = fast ->next->next;
	}
	return found;

}

struct list *find_last(struct list *head)
{
	struct list *prev = NULL;
	struct list *cur = head;
	int len = get_len(head);
	if (len < 3)
		return NULL;
	while(cur->next) {
		prev = cur;
		cur = cur->next;
	}
	if (prev && prev->next) {
		prev->next = NULL;
	}
	return cur;

}

void reorderList(struct list* head)
{
	struct list *cur = NULL;
	struct list *next = NULL;
	if (!head->next)
		return;

	cur = head;
	while(cur) {
		next = cur->next;
		struct list *last = find_last(cur);
		if (last == NULL)
			break;
		last->next = next;
		cur->next = last;
		cur = last->next;
	}
}

int main(void)
{
	//int a[] = {1, 2, 3, 4};
	int a[] = {1, 2, 3, 4, 5};
	list *head = NULL;
	int len = sizeof(a)/sizeof(int);
	head = create_list(a, len);
	show_list(head);
	reorderList(head);
	printf("reorder \n");
	show_list(head);
	release_list(head);
	return 0;
}
