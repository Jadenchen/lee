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

list *findinter(list *headA, list *headB)
{
	int lena = getlen(headA);
	int lenb = getlen(headB);
	int len = 0;
	list *cmp = NULL;
	list *ocmp = NULL;
	list *find = NULL;

	if (lena > lenb) {
		cmp = headA;
		ocmp = headB;
		len = lena - lenb;
	} else {
		cmp = headB;
		ocmp = headA;
		len = lenb - lena;
	}

	while(len--) 
		cmp = cmp->next;

	while(ocmp) {
		if (ocmp == cmp) {
			find = ocmp;
			break;
		}

		ocmp = ocmp->next;
		cmp = cmp->next;
	}
	return find;
}

list *getIntersectionNode(list *headA, list *headB)
{
    list **indirA = &headA;
    list **indirB = NULL;
    list *inter = NULL;
    while(*indirA) {
        indirB = &headB;
        while(*indirB) {
                if (*indirA == *indirB) {
                    inter = *indirA;
                    break;
                }
            indirB = &(*indirB)->next;
        }

        indirA = &(*indirA)->next;
        if (inter)
            break;
    }
    return inter;
}
//! time O(max(lenA, lenB), space O(1)
//! leetcode 160
int main(void)
{
	return 0;
}

