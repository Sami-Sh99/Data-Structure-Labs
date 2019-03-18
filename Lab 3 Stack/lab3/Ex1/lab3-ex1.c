#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
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

void display(stack s)
{
	element e;
	while(Top(s,&e))
	{
		Pop(&s);
		printf("|%5d|\n",e);
	}
	printf("|_____|\n");
}

list CreateList()
{
	return NULL;
}

void fill(list *L1, list *L2)
{
	int x,y;
	list node;
	while (1)
	{
		printf("Data ? ");
		scanf("%d", &x);
		if (x < 0)
			break;
		node = (list)malloc(sizeof(struct cell));
		if (node == NULL)
		{
			exit(-1);
		}

		printf("List ? (1, 2, 0) ");
		scanf("%d", &y);
		if (y == 1)
		{
			node->data = x;
			node->next = *L1;
			*L1 = node;
		}
		if (y == 2)
		{
			node->data = x;
			node->next = *L2;
			*L2 = node;
		}
		if (y == 0)
		{
			node->data = x;
			node->next = *L1;
			*L1 = node;
			*L2 = node;
		}

	}


}

void main()
{

	list L1, L2 , L3;
	int count1 = 0, count2 = 0;
	L1 = CreateList();
	L2 = CreateList();

	fill(&L1, &L2);
	if (intersection(L1, L2, &count1, &count2, &L3))
		printf("%d %d %d", L3->data, count1, count2);
	
	getchar();
	getchar();
	getchar();
}