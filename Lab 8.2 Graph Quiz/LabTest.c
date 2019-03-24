#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Queue.h"

typedef struct {
	int V;
	int E;
	int **Adj;
} Graph;

char Bevereges[100][51];

void topologicalSort(Graph*g,int*indegree, int s)
{
	queue q = CreateQueue();
	int e, i;

	for(i=0;i<g->V;i++)
		if (indegree[i] == 0)
			EnQueue(&q, i);
		
	while (Front(q, &e))
	{
		DeQueue(&q);
		printf("%s ", Bevereges[e]);
		if (indegree[e] == 0)
			for (i = 0; i < g->V; i++)
			{
				if (g->Adj[e][i] == 1)
				{
					indegree[i]--;
					if (indegree[i] == 0)
						EnQueue(&q, i);
				}
			}
	}

}

void main()
{
	Graph g;
	int nb_Bevereges, i, j, nb_Relations, t1, t2;
	char temp_S[105], s1[51], s2[51];
	int *indegree;
	queue q = CreateQueue();
	printf("Enter Number of Bevereges: ");
	scanf("%d", &nb_Bevereges);
	g.V = nb_Bevereges;
	indegree= (int*)malloc(sizeof(int)*g.V);
	for (i = 0; i < g.V; i++)
	{
		visited[i] = 0;
		indegree[i] = 0;
	}
	g.Adj = (int **)malloc(sizeof(int*)*g.V);
	for (i = 0; i < g.V; i++)
		g.Adj[i] = (int *)malloc(g.V * sizeof(int));

	for (i = 0; i < g.V; i++)
		for (j = 0; j < g.V; j++)
			g.Adj[i][j] = 0;

	for (i = 1; i <= nb_Bevereges; i++)
	{
		printf("Enter beverege number %d: ", i);
		scanf("%s", Bevereges[i-1]);
	}
	printf("Enter number of relations between bevereges: ");
	scanf("%d",&(g.E));
	for (j = 0; j < g.E; j++)
	{
		printf("Enter 2 bevereges: ");
		scanf("%s%s", s1, s2);
		//sscanf(temp_S, "%s%s", s1, s2);
		for (i = 0; i < nb_Bevereges; i++)
		{
			if (strcmp(s1, Bevereges[i]) == 0)
				t1 = i;
			if (strcmp(s2, Bevereges[i]) == 0)
				t2 = i;
		}
		g.Adj[t1][t2] = 1;
	}

	for (i = 0; i < g.V; i++)
		for (j = 0; j < g.V; j++)
			if (g.Adj[j][i] == 1)
				indegree[i]++;

	printf("Zahraa should drink bevereges in this order: ");

	topologicalSort(&g, indegree, 0);




	getchar();
	getchar(); 
	getchar();
}