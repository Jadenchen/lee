#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list *next;
} list;


/**
 * Definition for singly-linked list.
 * list {
 *     int val;
 *     list *next;
 * };
 */

void add(list **head, list *remove, int x)
{
	list *cur = *head;
	list *small = NULL;
	list *prev = NULL;
	list *next = NULL;
	while(cur) {
		if (cur->val >= x) {
			small = prev;
			break;
		}
		prev =  cur;
		cur = cur->next;
	}
	if (prev) {
		next = prev->next;
		prev->next = remove;
		remove->next = next;
	} else {
		remove->next = *head;
		*head = remove;
	}
}

list *del(list *head, int re_index)
{
	int index = 0;
	list *cur = head;
	list *next = NULL;
	list *prev = NULL;
	list *remove = NULL;
	while(cur) {
		if (index == re_index) {
			remove = cur;
			break;
		}
		prev = cur;
		cur = cur->next;
		index++;
	}

	next = remove->next;
	prev->next = next;
	remove->next = NULL;
	return remove;
}

int getlen(list *head)
{
	int len = 0;
	list *cur = head;
	while(cur) {
		len++;
		cur = cur->next;
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

list* partition(list* head, int x)
{
#if 0
	int len = 0;
	list *cur = head;
	list *remove = NULL;
	int xindex = 0;
	int index = 0;
	if (!head || !head->next) {
		return head;
	}
	len = getlen(head);
	int rec[len];
	memset(rec, 0, sizeof(int)*len);
	while(cur) {
		if (cur->val < x)
			rec[index] = 1;
		if (cur->val == x) 
			xindex = index;
		cur = cur->next;
		index++;
	}

	//! find index bigger than xindex
	for (int i = xindex; i < len; i++) {
		if (rec[i] == 1) {
			remove = del(head, i);
			add(&head, remove, x);
		}
	}
	return head;
#endif
	list *before_head = NULL;
	list *after_head = NULL;
	list *before = NULL;
	list *after = NULL;
	list *cur = head;
	before_head = new_node(0);
	after_head  = new_node(0);
	before = before_head;
	after = after_head;
	while(cur) {
		if (cur->val < x) {
			before->next = cur;
			before = before->next;
		} else {
			after->next = cur;
			after = after->next;
		}
		cur = cur->next;
	}

	after->next = NULL;
	before->next = after_head->next;
	return before_head->next;
}

list* partition2(list* head, int x)
{
	list *befor_head = NULL;
	list *after_head = NULL;
	list *before = NULL;
	list *after = NULL;
	list *cur = head;
	befor_head = new_node(0);
	after_head  = new_node(0);
	before = befor_head;
	after = after_head;
	while(cur) {
		if (cur->val < x) {
			before->next = cur;
			before = before->next;
		} else {
			after->next = cur;
			after = after->next;
		}
		cur = cur->next;
	}

	after->next = NULL;
	before->next = after_head->next;
	return befor_head->next; 
}

int main(void)
{
	return 0;
}	
