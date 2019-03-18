#include<stdio.h>
#include<string.h>
#include<conio.h>
#include "Stack.h"


int is_digit(char c)
{	
	return (c>='0' && c<='9');
}


float to_digit(char c)
{	
	return (float)(c-'0');
}

float power(float X, float M)
{
	if(M==0) return 1;
	if(M<0) return 1./power(X,-M);
	return X*power(X,M-1);
}

float operation(float nb1, char c, float nb2)
{ 
	switch(c)
	{
		case '+': return nb1 + nb2;
		case '-': return nb1-nb2;
		case '*': return nb1*nb2;
		case '/': return nb1/nb2;
		case '$': return power(nb1,nb2);
		case '#': return -nb1;
	}
}


float result(char *str)
{
	int i;
	float e1, e2, ans;
	stack S = CreateStack();
	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_digit(str[i]))
			Push(&S, to_digit(str[i]));
		else
		{
			if (!Top(S, &e1))
				printf("Error, Empty stack\n");
			Pop(&S);
			if (!Top(S, &e2))
				printf("Error, Empty stack\n");
			Pop(&S);
			Push(&S, operation(e2, str[i], e1));
		}
	}
	Top(S, &ans);
	return ans;
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
	char str[N];

	printf("Enter a Postfix expression\n");
	scanf("%s",str);

	printf("\nValue %.0f",result(str));

	getchar();
	getchar();
	return 0;
}