#include "Queue.h"
queue CreateQueue()
{
	queue q;
	q.front = 0; q.length=0;
	return q;
}

int EnQueue(queue *q, element e)
{
	if (isFullQueue(*q)) return 0;
	q->data[(q->front + q->length)%N] = e;
	q->length = (q->length + 1)%N;
	return 1;
}

int DeQueue(queue *q)
{
	if (isEmptyQueue(*q)) return 0;
	q->front=(q->front + 1) % N;
	q->length--;
	return 1;
}

int Front(queue q, element *e)
{
	if (isEmptyQueue(q)) return 0;
	*e = q.data[q.front];
	return 1;
}

int isEmptyQueue(queue q)
{
	return q.length == 0;
}

int isFullQueue(queue q)
{
	return q.length ==(N-1);
}

void display_queue(queue q)
{
	element e;
	while(Front(q,&e))
	{
		printf("%d ",e);
		DeQueue(&q);
	}
}
