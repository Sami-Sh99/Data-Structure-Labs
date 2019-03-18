#include<stdio.h>
#include"Queue.h"

void main()
{
	queue q = CreateQueue();
	EnQueue(&q, 23, 1);
	EnQueue(&q, 23, 3);
	EnQueue(&q, 23, 4);
	EnQueue(&q, 23, 6);
	EnQueue(&q, 23, 2);
	EnQueue(&q, 23, 2);

}