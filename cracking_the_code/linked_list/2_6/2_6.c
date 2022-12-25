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

list *rev_list(list *head)
{
	list *prev = NULL;
	list *next = NULL;
	list *cur = head;
	while(cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
	return head;
}

int isPali(list *head)
{	
	int bPa = 1;
	list *slow = NULL;
	list *fast = NULL;
	list *mid = NULL;
	list *remain = NULL;
	list *reverse = NULL;
	list *cur1 = NULL;
	list *cur2 = NULL;
	if (!head->next)
		return bPa;
	slow = head;
	fast = head;
	while(fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	mid = slow;
	remain = mid->next;
	mid->next = NULL;
	reverse = rev_list(remain);
	cur1 = head;
	cur2 = reverse;
	while(cur2) {
		if (cur1->val != cur2->val) {
			bPa = 0;
			break;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return bPa;
}

int main(void)
{
	//int a[] = {1,1,2,1};
	int a[] = {1,2,2,1};
	list *head = NULL;
	list *revere = NULL;
	for (size_t i = 0; i < 4; i++)
		init_list(&head, a[i]);
	show(head);

	//! find mid
	if (isPali(head)) {
		printf("yes it is\n");
	} else 
		printf("no it is not\n");

	return 0;
}

