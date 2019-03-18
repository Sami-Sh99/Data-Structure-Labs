#include"Queue.h"

queue CreateQueue()
{
	queue q;
	q.front = 1;
	q.rear =  0;
	return q;
}
int isEmptyQueue(queue q) 
{
	if (q.front == (q.rear + 1) % N)
		return 1;
	return 0;
}
int isFullQueue(queue q)
{
	if (q.front == (q.rear + 2) % N)
		return 1;
	return 0;
}
int DeQueue(queue *q)
{
	if (isEmptyQueue(*q))
		return 0;
	q->front = (q->front + 1) % N;
	return 1;
}
int Front(queue q, element*e)
{
	if (isEmptyQueue(q))
		return 0;
	*e = q.data[q.front].data;
	return 1;
}


int EnQueue(queue*q, element e, int priority)
{
	process temp[N]; // implementing a stack 
	int top = -1, qIndex = q->rear;

	process qProcess = { e,priority };
	if (isFullQueue(*q))
		return 0;
	if (isEmptyQueue(*q))
	{
		q->rear = (q->rear + 1) % N;
		q->data[q->rear].data = e;
		q->data[q->rear].priority = priority;
		return 1;
	}

	//Add queue elements to stack in a sorted order:
	while (q->rear >= q->front)
	{
		if (q->data[q->rear].priority > priority)
		{
			temp[++top] = q->data[q->rear];
			q->rear = (q->rear - 1) % N;
		}
		else
		{
			temp[++top] = qProcess;
			priority = -1;
		}
	}
	//if all processes were insorted and priority parameter wasn't changed, insert it to become the top;
	if (priority != -1)
		temp[++top] = qProcess;

	q->rear = (q->front - 1) % N;

	while (top != -1)
	{
		q->rear = (q->rear + 1) % N;
		q->data[q->rear] = temp[top--];
	}
	return 1;
}



////////////////////////////////////////////////////////////////////////////
//Linked List implementation:
// queue CreateQueue()
// {
// 	queue q;
// 	q.front = NULL;
// 	q.rear = NULL;
// 	return q;
// }
// int isEmptyQueue(queue q)
// {
// 	return q.front == NULL;
// }
// int Front(queue q, element*e)
// {
// 	if (isEmptyQueue(q))
// 		return 0;
// 	*e = q.front->data;
// 	return 1;
// }
// int DeQueue(queue *q)
// {
// 	if (isEmptyQueue(*q))
// 		return 0;
// 	process*temp = q->front;
// 	q->front = q->front->next;
// 	free(temp);
// 	if (q->front == NULL)
// 		q->rear = NULL;
// 	return 1;
// }
// int EnQueue(queue *q, element e,int priority)
// {
// 	process *current = q->front;
// 	process*newNode = (process*)malloc(sizeof(struct cell));
// 	if (!newNode)
// 		return 0;
// 	newNode->data = e;
// 	newNode->priority = priority;
// 	if (isEmptyQueue(*q))
// 	{
// 		q->front = newNode;
// 		newNode->next = NULL;
// 		return 1;
// 	}
// 	for (; current->next && current->next->priority <= priority; current = current->next);
// 	if (!current->next)
// 		q->rear = newNode;
// 	newNode->next = current->next;
// 	current->next = newNode;
// 	return 1;
// }