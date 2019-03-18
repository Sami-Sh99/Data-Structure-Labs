#include"Queue.h"
#include<stdlib.h>
queue CreateQueue()
{
	queue q;
	q.front = NULL;
	q.rear = NULL;
	return q;
}
int isEmptyQueue(queue q)
{
	return q.front == NULL;
}
int Front(queue q, element*e)
{
	if (isEmptyQueue(q))
		return 0;
	*e = q.front->data;
	return 1;
}
int DeQueue(queue *q)
{
	if (isEmptyQueue(*q))
		return 0;
	process*temp = q->front;
	q->front = q->front->next;
	free(temp);
	if (q->front == NULL)
		q->rear = NULL;
	return 1;
}
int EnQueue(queue *q, element e,int priority)
{
	process *current = q->front;
	process*newNode = (process*)malloc(sizeof(struct cell));
	if (!newNode)
		return 0;
	newNode->data = e;
	newNode->priority = priority;
	if (isEmptyQueue(*q))
	{
		q->front = newNode;
		newNode->next = NULL;
		return 1;
	}
	for (; current->next && current->next->priority <= priority; current = current->next);
	if (!current->next)
		q->rear = newNode;
	newNode->next = current->next;
	current->next = newNode;
	return 1;

}