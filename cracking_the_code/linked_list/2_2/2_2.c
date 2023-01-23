#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int val;
	struct list *next;
} list;

//! return kth 
void removedup(list *head)
{
	

}

void init_list(list **head, int val)
{
	list **indir = head;
	list *new = calloc(1, sizeof(list));
	new->val = val;
	new->next = NULL;
	while(*indir) {
		indir = &(*indir)->next;
	}
	*indir = new;
}

void show(list *head)
{
	list *cur = head;
	while(cur) {
		printf("%d ", cur->val);
		cur = cur->next;
	}	
	printf("\n");
}

int get_len(list *head)
{
	list *cur = head;
	int cnt = 0;
	while(cur) {
		cnt++;
		cur = cur->next;
	}
	return cnt;
}

void list_del(list *remove, list *prev)
{
	list *next = remove->next;
	if (prev) {
		prev->next = next;
	}
}

list* removeNthFromEnd(list* head, int n)
{
	int len = 0;
	int index = 0;

	list *cur = head;
	list *prev = NULL;
	len = get_len(head);
	index = len -n + 1;
	if (index == 1) {
		head = head->next;
		return head;
	}
	
	while(cur) {
		index--;
		if (index == 0)
			break;
		prev = cur;
		cur = cur->next;
	}	

	list_del(cur, prev);
	return head;
}

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	int len = sizeof(a)/sizeof(int);
	list *head = NULL;
	for (int i = 0; i < len; i++) {
		init_list(&head, a[i]);
	}	

	show(head);
	//head = removeNthFromEnd(head, 2);
	head = removeNthFromEnd(head, 5);
	show(head);
}

