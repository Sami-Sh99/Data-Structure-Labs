#include<stdio.h>
#include<string.h>
#include<conio.h>
#include "Stack.h"

int stackable(char o1, char o2)
{
	switch(o1)
	{
		case '(': return 1;
		case '+': case '-': return (o2=='(');
		case '#': return (o2!='#');
		case '*':case '/': return (o2=='(' || o2=='+'||o2=='-');
		case '$': return (o2!='#' && o2!='$');
		case ')': return (o2=='(');
	}
}

int is_operator(char c)
{
	return (c=='*' || c=='-' || c=='/'  || c=='+' || c=='$' || c=='#' || c==')' || c=='(' );
}


int is_digit(char c)
{	
	return (c>='0' && c<='9');
}



void infix_to_postfix(char *infix, char *postfix)
{
	int i, j = 0;
	element e;
	stack S = CreateStack();
	for (i = 0; infix[i] != '\0'; i++)
	{
		if (is_digit(infix[i]))
			postfix[j++] = infix[i];
		else if (is_operator(infix[i]))
		{
			if (infix[i] == ')')
			{
				while (Top(S, &e) && e != '(')
				{
					postfix[j++] = e;
					Pop(&S);
				}
				Pop(&S);
			}
			else if (Top(S, &e) && (infix[i] == '+' || infix[i] == '-') && !stackable(infix[i], e))
			{
				postfix[j++] = e;
				Pop(&S);
				Push(&S, infix[i]);
			}
			else if (stackable(infix[i], e))
				Push(&S, infix[i]);
			else
				Push(&S, infix[i]);
		}
	}
	while (Top(S, &e))
	{
		postfix[j++] = e;
		Pop(&S);
	}
	postfix[j] = '\0';
}


int main()
{
	char str[N],R[N];
	int i;

	printf("Enter an infix expression\n");
	scanf("%s",str);

	infix_to_postfix(str, R);

	for(i=0;R[i];i++)
		printf("%c",R[i]);

	getchar();
	getchar();
	return 0;
}