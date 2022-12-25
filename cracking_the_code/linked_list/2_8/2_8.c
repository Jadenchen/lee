#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list *next;
} list;

list *detectCycle(list *head)
{
	list *slow = NULL;
	list *fast = NULL;
	list *cycle = NULL;
	list *first = NULL;
	list *curr = head;
	if (!head || !head->next) 
		return first;
	
	slow = head;
	fast = head;
	while(fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			cycle = slow;
			break;
		}
	}

	while(curr && cycle) {
		if (curr == cycle) {
			first = curr;
			break;
		}
		curr = curr->next;
		cycle = cycle->next;
	}
	return first;
}
//! time O(max(lenA, lenB), space O(1)
//! leetcode 160
int main(void)
{
	return 0;
}

