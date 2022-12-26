#include <stdio.h>
#include <stdlib.h>
#define N (10)

typedef enum {
	dog = 0,
	cat = 1
} animal;

typedef struct list {
	int order;
	struct list *next;
} list;

typedef struct animalshelter {
	list *dog;
	list *cat;
	int order;
} animalshelter;

animalshelter *init_shelter()
{
	animalshelter *new = calloc(1, sizeof(animalshelter));
	printf("%s\n", __func__);
	return new;
}

void release_node(list *remove)
{
	if (remove)
		free(remove);
}

void release_list(list *head)
{
	list *remove = NULL;
	while(head) {
		remove = head;
		head = head->next;
		release_node(remove);
	}	
}

void release_shelter(animalshelter *new)
{
	if (new) {
		if (new->dog) 
			release_list(new->dog);
			
		if (new->cat) 
			release_list(new->cat);
		free(new);
		printf("%s\n", __func__);
	}
}

list *new_node(int order)
{
	list *new = calloc(1, sizeof(list));
	new->order = order;
	new->next = NULL;
	return new;
}

void add(list **head, int order)
{
	list **indir = head;
	list *new = new_node(order);
	while(*indir) {
		indir = &(*indir)->next;
	}

	*indir = new;
}	

void enqueue(animalshelter *shelter, animal ani)
{
	if (ani == dog) {
		printf("%s dog\n", __func__);
		add(&shelter->dog, shelter->order);
	} else {
		printf("%s cat\n", __func__);
		add(&shelter->cat, shelter->order);
	}
	
	shelter->order++;	
}

void dequeue(list **head, int *order)
{
	list **indir = head;
	if (*indir) {
		*order = (*indir)->order;
		*head = (*indir)->next;
	} else 
		*order = 65536;
}

void dequeueDog(animalshelter *shelter, int *order)
{	
	printf("%s \n", __func__);
	dequeue(&shelter->dog, order);
}

void dequeueCat(animalshelter *shelter ,int *order)
{
	printf("%s \n", __func__);
	dequeue(&shelter->cat, order);
}

int getlen(list *head)
{
	int len = 0;
	while(head) {
		len++;
		head = head->next;
	}
	return len;
}

int getorder(list *head)
{
	return head->order;
}

void dequeueAny(animalshelter *shelter, int *order) 
{
	int dogsize = getlen(shelter->dog);
	int catsize = getlen(shelter->cat);
	if (dogsize == 0)
		return dequeueCat(shelter, order); 
	else if (catsize == 0) 
		return dequeueDog(shelter, order);
	
	int dogorder = getorder(shelter->dog);
	int catorder = getorder(shelter->cat);	
	if (dogorder > catorder) 
		return dequeueCat(shelter, order);
	else 
		return dequeueDog(shelter, order);
}

//! time O(N^2) space O(N)
int main(void)
{
	int order = 0;
	//! init 
	animalshelter *new = init_shelter();
	//! enque cat 
	enqueue(new, cat);
	//! enque cat
	enqueue(new, cat);
	//! enque dog 
	enqueue(new, dog);
	//! dequeue dog
	dequeueDog(new, &order);
	printf("dog order %d \n", order);
	//! dequeue cat
	dequeueCat(new, &order);
	printf("cat order %d \n", order);
	//! dequeue any
	dequeueAny(new, &order);
	printf("any order %d \n", order);
	release_shelter(new);
	return 0;
}
