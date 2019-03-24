#include"Queue.h"

typedef struct {
	int V;
	int E;
	int **adj;
}Graph;
typedef struct node {
	int v;
	struct node* next;
}node;

void push(node**head, int e)
{
	node*temp;
	if (!*head)
	{
		*head = (node*)malloc(sizeof(node));
		(*head)->v = e;
		(*head)->next = NULL;
	}
	else {
		temp = (node*)malloc(sizeof(node));
		temp->next = *head;
		temp->v = e;
		*head = temp;
	}

}

int topologicalSort(Graph*g,node**head, int*indegree, int s)
{
	queue q = CreateQueue();
	int e, i, count = 0;

	for (i = 0; i<g->V; i++)
		if (indegree[i] == 0)
			EnQueue(&q, i);
	while (Front(q, &e))
	{
		DeQueue(&q);
		push(head,e+1);
		if (indegree[e] == 0)
		{
			for (i = 0; i < g->V; i++)
			{
				if (g->adj[e][i] == 1)
				{
					indegree[i]--;
					if (indegree[i] == 0)
					{
						EnQueue(&q, i);

					}
				}
			}
		}
		count++;
	}
	if (count != g->V)return 0;
	return 1;

}
void recPrint(node*head)
{
	if (head)
	{
		recPrint(head->next);
		printf("%d\n",head->v);
	}
}
void main()
{
	Graph G;
	node *answer = NULL;
	int n, m, i, r, c, *indegree, *visited;
	printf("Enter n and m:");
	scanf("%d %d",&n,&m);
	printf("Enter %d lines\n", m);
	G.V = n;
	G.E = m;
	G.adj = (int**)malloc(G.V * sizeof(int*));
	for(i=0;i<G.V;i++)
		G.adj[i] = (int*)malloc(G.V * sizeof(int));
	for (i = 0; i < G.V; i++)
		for (n = 0; n < G.V; n++)
			G.adj[i][n] = 0;
	visited = (int*)malloc(G.V * sizeof(int));
	for (i = 0; i < G.V; i++)
		visited[i] = 0;
	while (m--)
	{
		scanf("%d %d", &r, &c);
		G.adj[r-1][c-1] = 1;
	}

	indegree = (int*)malloc(G.V * sizeof(int));
	for (i = 0; i < G.V; i++)
		indegree[i] = 0;
	for (i = 0; i < G.V; i++)
		for (n = 0; n < G.V; n++)
			if (G.adj[n][i] == 1)
				indegree[i]++;

	if (topologicalSort(&G, &answer, indegree, 0))
		recPrint(answer);
	else
		printf("IMPOSSIBLE");
	getchar();
	getchar();
}