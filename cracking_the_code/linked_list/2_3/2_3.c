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

void del(list *curr, list *remove)
{
	if (remove->next)
		curr->next = remove->next;
	else 
		curr->next = NULL;
}

//! remove mid (leetcode: 2095)
//! time O(n) space O(1)
list *removemid(list *head)
{
	int len = 0;
	int index = 0;
	list *curr = NULL;
	list *prev = NULL;
	if (!head || !head->next)
		return head;

	len = getlen(head);
	len = len/2;
	curr = head;
	while(curr) {
		if (index++ == index)
			break;
		prev = curr;
		curr = curr->next;
	}		
	del(prev, curr);
	return head;
}

int main(void)
{
	return 0;
}

