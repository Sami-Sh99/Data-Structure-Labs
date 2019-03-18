#include<stdio.h>
#include<string.h>
#include "Stack.h"

int intersection(list L1, list L2, int *count1, int *count2, list *inter)
{
	stack S1 = CreateStack();
	stack S2 = CreateStack();
	int counter = 0, e1, e2;
	for (; L1 && L2; L1 = L1->next, L2 = L2->next)
	{
		Push(&S1, L1);
		Push(&S2, L2);
		*count1 += 1;
		*count2 += 1;
	}
	while (L1)
	{
		Push(&S1, L1);
		L1 = L1->next;
		*count1 += 1;
	}
	while (L2)
	{
		Push(&S2, L2);
		L2 = L2->next;
		*count2 += 1;
	}
	Top(S1, &e1);
	Top(S2, &e2);
	while (e1 == e2)
	{
		Pop(&S1);
		Pop(&S2);
		*inter = e1;
		Top(S1, &e1);
		Top(S2, &e2);
		counter++;
	}
	if (isEmptyStack(S1) || isEmptyStack(S2))
		return 0;
	*count1 -= counter;
	*count2 -= counter;
	return 1;
}

int main()
{

	int T[] = { 1,9,4,6,5,4 }, i=0;
	char e1;
	stack S1 = CreateStack();
	stack S2 = CreateStack();
	Push(&S1, T[i]);
	for (i = 1; i < 6; i++)
	{
		if (Top(S1, &e1))
		{
			if (e1 <= T[i])
				Push(&S1, T[i]);
			else
			{
				while (Top(S1, &e1) && e1 > T[i])
				{
					Pop(&S1);
					Push(&S2, e1);
				}
				Push(&S1, T[i]);
				while (Top(S2, &e1))
				{
					Pop(&S2);
					Push(&S1, e1);
				}
			}
		}
	}
	for (i = 0; !isEmptyStack(S1); i++)
	{
		Top(S1, T + i);
		Pop(&S1);
	}
	getchar();
	return 0;
}