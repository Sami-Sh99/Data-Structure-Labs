#include "Queue.h"

queue CreateQueue()
{
	queue q;
	q.front = 1; q.rear=0;
	return q;
}

int EnQueue(queue *q, element e)
{
	if (isFullQueue(*q)) return 0;
	q->rear= (q->rear + 1 ) % M;
	q->data[q->rear] = e;
	return 1;
}

int DeQueue(queue *q)
{
	if (isEmptyQueue(*q)) return 0;
	q->front=(q->front + 1) % M;
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
	return (q.front == (q.rear+1)%M);

}

int isFullQueue(queue q)
{
	return (q.front == (q.rear+2)%M);
}

