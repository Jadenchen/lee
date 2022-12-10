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

int get_index(list *head, list *find)
{
	list *curr = head;
	int index = 0;
	while(curr) {
		if (curr == find)
			break;
		index++;
		curr = curr->next;
	}
	return index;
}

list *find_first(list *head, list *find)
{	
	list *curr = find;
	list *first = curr;
	int find_index = get_index(head, curr);
	int cmp_index = 0;
	curr = curr->next;
	while(curr != find) {
		cmp_index = get_index(head, curr);
		if (cmp_index < find_index) {
			first = curr;
			find_index = cmp_index;
		}
		curr = curr->next;
	}
	
	return first;
}

list *has_cycle(list *head)
{
	list *slow = NULL;
	list *fast = NULL;
	list *find = NULL;
	
	if (!head || !head->next)
		return;
	slow = head;
	fast = slow->next;
	while(slow && fast && fast->next) {
		if (slow == fast) {
			find = slow;
			break;
		}	
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("find %d \n", find->val);
	if (find)
		find = find_first(head, find);
	return find;
}

list *has_cycle_floyd(list *pa)
{
	list *slow = pa;
	list *fast = pa;
	list *find = NULL;
	list *first = NULL;
	list *second = NULL;
       	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			find = slow;
			break;
		}
	}	

	first = pa;
	second = find;
	while(first != second) {
		first = first->next;
		second = second->next;
	}
	return first;
}

int main(void) 
{
	int num[] = {3, 2, 0, -4};
	int len = sizeof(num)/sizeof(int);
	list *pa = NULL;
	list *first = NULL;
	pa = create_list(num, len);
	if (!pa)
		return -1;
	list *curr = pa;
	list *end = pa;
	curr = curr->next;
	end = curr->next->next;
	end->next = curr;
	
#if 0
	first = has_cycle(pa);
#else 
	//! floyid solution
	first = has_cycle_floyd(pa);
#endif
	printf("first %d \n", first->val);
	return 0;
}
