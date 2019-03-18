#include "Queue.h"

void create_system(systemQ t)
{
	int i;
	for (i = 0; i < N; i++)
		t[i] = CreateQueue();
}

void display(systemQ t)
{
	int i;
	queue tempQ = CreateQueue();//store a priority Queue then re-EnQueue it in the systemQ
	element e;
	for (i = 0; i < N; i++)
	{
		printf("Priority %d:", i);
		while (Front(t[i], &e))
		{
			DeQueue(&t[i]);
			EnQueue(&tempQ, e);
			printf("\t %d", e);
		}
		while (Front(tempQ, &e))
		{
			DeQueue(&tempQ);
			EnQueue(&t[i], e);
		}
		printf("\n");
	}
}

int add(systemQ t, process e, element priority)
{
	if (priority >= N)
		return 0;
	if (!EnQueue(&t[priority], e))
		return 0;
	return 1;
}

int deletePri(systemQ t)
{
	int i = N - 1;
	while (!DeQueue(&t[i]) && i>=0)
		i--;
	if (i < 0)
		return 0;
	return 1;
}

int nb_elements(queue Q)
{
	int counter = 0;
	while (DeQueue(&Q))
		counter++;
	return counter;
}

void exchange(element p1,element p2,systemQ t)
{
	queue temp;
	temp = t[p1];
	t[p1] = t[p2];
	t[p2] = temp;

}
