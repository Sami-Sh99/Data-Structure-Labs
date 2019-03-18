#include "Stack.h"

stack CreateStack()
{
	stack p;
	p.top = -1;
	return p;
}

int Push(stack *p, element e)
{
	if (isFullStack(*p)) return 0;
	p->data[++p->top] = e;
	return 1;
}

int Pop(stack *p)
{
	if (isEmptyStack(*p)) return 0;
	p->data[p->top] = 0;
	p->top--;
	return 1;
}

int Top(stack p, element *e)
{
	if (isEmptyStack(p)) return 0;
	*e = p.data[p.top];
	return 1;
}

int isEmptyStack(stack p)
{
	return (p.top == -1);
}

int isFullStack(stack p)
{
	return (p.top == N-1);
}