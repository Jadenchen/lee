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


list *new_node(int val)
{
	list *new = calloc(1, sizeof(list));
	new->val = val;
	new->next = NULL;
	return new;
}

void init_list(list **head, int val)
{
	list *new = new_node(val);
	list **indir = head;
	while(*indir)
		indir = &(*indir)->next;
	*indir = new;
}

void show(list *head)
{
	list *cur = head;
	while(cur) {
		printf(" %d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void creat_list(list **head, int *a, int len, int carrier)
{
	for(size_t i = 0; i < len; i++) 
		init_list(head, a[i]);
	if (carrier)
		init_list(head, 1);
}

list *addtwonumbers(list *l1, list *l2)
{
	int len1 = getlen(l1);
	int len2 = getlen(l2);
	int len = len1 > len2 ? len1:len2;
	int a[len];
	list *cur1 = l1;
	list *cur2 = l2;
	list *new = NULL;
	int val = 0;
	int carrier = 0;
	int index = 0;
	while(cur1 && cur2) {
		val = (cur1->val + cur2->val + carrier) % 10;
		carrier = (cur1->val + cur2->val + carrier) >=10 ? 1 : 0;
		a[index++] = val;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	if (len1 > len2) {
		while(cur1) {
			val = (cur1->val + carrier) %10;
			carrier = (cur1->val + carrier) >= 10 ? 1: 0;
			a[index++] = val;
			cur1 = cur1->next;
		}
	} else {
		while(cur2) {
			val = (cur2->val + carrier) %10;
			carrier = (cur2->val + carrier) >= 10 ? 1: 0;
			a[index++] = val;
			cur2 = cur2->next;
		}
	}
	creat_list(&new, a, len, carrier);
	return new;
}

list *addtwonumbers2(list *l1, list *l2)
{
	list *new_head = NULL;
	list **indir = &new_head;
	list *new = NULL;
	int val = 0;

	int over = 0;

	while(l1 && l2) {
		if (over) {
			val = l1->val + l2->val + over;
			over = 0;
		} else {
			val = l1->val + l2->val;
		}
		if (val >= 10) {
			over = 1;
			val = val % 10;
		}
		new = new_node(val);
		*indir = new;
		indir = &(*indir)->next;
		l1 = l1->next;
		l2 = l2->next;
	}

	while(l1) {
		val = l1->val + over;
		if (val >= 10) {
			over = 1;
			val = val % 10;
		} else {
			over = 0;
		}
		new = new_node(val);
		l1 = l1->next;
		*indir = new;
		indir = &(*indir)->next;
	}

	while(l2) {
		val = l2->val + over;
		if (val >= 10) {
			over = 1;
			val = val % 10;
		} else {
			over = 0;
		}
		new = new_node(val);
		l2 = l2->next;
		*indir = new;
		indir = &(*indir)->next;
	}

	if (over) {
		new = new_node(over);
		*indir = new;
		over = 0;
		indir = &(*indir)->next;
	}

	return new_head;
}

int main(void)
{
	int a[] = {9,9,9,9,9,9,9};
	int b[] = {9,9,9,9};

	list *l1 = NULL;
	list *l2 = NULL;	
	list *new = NULL;
	for (size_t i = 0; i < 7; i++)
		init_list(&l1, a[i]);

	for (size_t i = 0; i < 4; i++)
		init_list(&l2, b[i]);

	show(l1);
	show(l2);
	//new = addtwonumbers(l1, l2);
	new = addtwonumbers2(l1, l2);
	show(new);
	return 0;
}

