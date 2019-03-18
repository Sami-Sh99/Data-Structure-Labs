#include "PQueue.h"
#include<stdlib.h>
#include<stdio.h>
pqueue CreateQueue()
{
	pqueue q;
	q.front = NULL;
	return q;
}

int EnQueue(pqueue *q, element e, int priority)
{
	node *temp=NULL, *href;
	temp =(node *) malloc(sizeof(node));
	if (!temp) return 0;
	temp->data = e;
	temp->priority = priority;
	if (q->front == NULL || priority < q->front->priority) {/*Queue is empty or item to be added has priority more than first item*/
		temp->next = q->front;
		q->front = temp;
	}
	else
	{
		href = q->front;
		while (href->next != NULL && href->next->priority <= priority)
			href = href->next;
		temp->next = href->next;
		href->next = temp;
	}

	return 1;
}

int DeQueue(pqueue *q)
{
	struct cell *temp;
	if (isEmptyQueue(*q)) return 0;
	temp = q->front;
	q->front = q->front->next;
	free(temp);
	return 1;
}

int Front(pqueue q, element *e)
{
	if (isEmptyQueue(q)) return 0;
	*e = q.front->data;
	return 1;
}

int isEmptyQueue(pqueue q)
{
	return q.front == NULL;
}


void display_queue(pqueue tmp)
{
	struct cell *temp = tmp.front;

	if (temp == NULL)
		printf("Priority Queue is empty\n");
	else
	{
		printf("Priority Queue is :\n");
		printf("Item\n");
		while (temp != NULL)
		{
			printf("%5d         %5d\n\n", temp->priority, temp->data);
			temp = temp->next;
		}
	}
}
void delete_head(struct cell **nodeRef)
{
	struct cell *p;
	p = *nodeRef;
	*nodeRef = (*nodeRef)->next;
	free(p);
}

// delete a given element (recursive)
int delete_value(struct cell **nodeRef, element e)
{
	if (*nodeRef == NULL)
		return 0;
	if ((*nodeRef)->data == e)
	{
		delete_head(nodeRef);
		return 1;
	}
	delete_value(&((*nodeRef)->next), e);
}


void recursive_ordered_insert(struct cell **node, element value, int priority)
{
	struct cell *temp;
	if ((*node == NULL) || !((*node)->priority < priority))
	{
		temp = *node;
		*node = (struct cell *) malloc(sizeof(struct cell));
		if (!*node) return ;
		(*node)->data = value;
		(*node)->priority = priority;
		(*node)->next = temp;
		return;
	}

	 recursive_ordered_insert(&((*node)->next), value, priority);

}


void update_priority(pqueue *q, element data, int priority) {
	if (delete_value(&(q->front), data) == 1)
		recursive_ordered_insert(&(q->front), data, priority);
}
