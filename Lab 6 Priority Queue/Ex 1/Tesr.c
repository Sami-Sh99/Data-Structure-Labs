#include"Queue.h"
#include<stdio.h>
void main()
{
	queue q = CreateQueue();
	EnQueue(&q, 1, 3);
	EnQueue(&q, 2, 4);
	EnQueue(&q, 3, 0);
	DeQueue(&q);
	EnQueue(&q, 4, 12);
	EnQueue(&q, 1, 3);
	EnQueue(&q, 2, 4);
	EnQueue(&q, 3, 0);
	DeQueue(&q);
	EnQueue(&q, 4, 12);
	EnQueue(&q, 3, 1);
	EnQueue(&q, 3, 1);
	EnQueue(&q, 3, 1);
	getchar();
}