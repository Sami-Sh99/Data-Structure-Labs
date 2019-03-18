#include<stdio.h>
#include<stdlib.h>
#include"PQueue.h"
typedef struct {
	int V;
	int E;
	int **Adj;
} Graph;

Graph* adjacencyMatrix() {
	int i, u, v, w;
	Graph* G = (Graph*)malloc(sizeof(Graph));
	printf("Enter the number of Vertices: ");
	scanf("%d", &G->V);
	printf("Enter the number of Edges: ");
	scanf("%d", &G->E);
	G->Adj = (int **)malloc(G->V * sizeof(int*));
	for (u = 0; u < G->V; u++)
		G->Adj[u] = (int *)malloc(G->V * sizeof(int));

	for (u = 0; u<G->V; u++)
		for (v = 0; v<G->V; v++)
			G->Adj[u][v] = 0;
	for (i = 0; i < G->E; i++) {
		printf("Enter the edge and the weight: ");
		scanf("%d %d %d", &u, &v, &w);
		G->Adj[u][v] = w;
	}
	return G;
}

void Dijkstra(Graph *G, int s) {
	// YOUR CODE HERE

	// Declare the following:
	// 1* a priority queue
	// 2* a dynamic array containing the distance (all initialized to -1)
	// 3* a dynamic array containing the path between verticies
	pqueue q = CreateQueue();
	element qElement=s;
	int i,dist=0,
		*distance = (int*)malloc(G->V*sizeof(int)),
		*Path = (int*)malloc(G->V * sizeof(int));
	for (i = 0; i < G->V; i++)
	{
		distance[i] = -1;
		Path[i] = -1;
	}

	// traverse the graph using BFS
	// for each element v in the queue, check its adjacent vertices w
	// calculate dist = distance[v] + G->Adj[v][w];
	// update distance[w] if it's equal to -1, and enqueue w with priority equal to dist
	// OR
	// update distance[w] if distance[w]>dist, and update the priority of w in the queue to be equal to dist
	// in both cases, update the entry of w in the path array to be equal to v
	EnQueue(&q, qElement, dist);
	distance[qElement] = 0;
	while (!isEmptyQueue(q))
	{
		Front(q, &qElement);
		DeQueue(&q);
		for (i = 0; i < G->V; i++)
		{
			dist = distance[qElement] + G->Adj[qElement][i];
			if (distance[i] ==-1 && G->Adj[qElement][i]!=0)
			{
				distance[i] = dist;
				EnQueue(&q, i, dist);
				Path[i] = qElement;
			}
			else if (distance[i] > dist && G->Adj[qElement][i] != 0)
			{
				distance[i] = dist;
				update_priority(&q, i, dist);
				Path[i] = qElement;
			}
		}
	}



	// At the end, display the content of both path and distance tables.
	for (i = 0; i < G->V; i++)
	{
		printf("%d should be reached from %d of total weight %d\n", i, Path[i], distance[i]);
	}
 
	 
}

void Prim(Graph *G, int s) {

	// YOUR CODE HERE

	// Declare the following:
	// 1* a priority queue
	// 2* a dynamic array containing the distance (all initialized to -1)
	// 3* a dynamic array containing the path between verticies
	pqueue q = CreateQueue();
	element qElement = s;
	int i, dist = 0,
		*distance = (int*)malloc(G->V * sizeof(int)),
		*Path = (int*)malloc(G->V * sizeof(int));
	for (i = 0; i < G->V; i++)
	{
		distance[i] = -1;
		Path[i] = -1;
	}

	// traverse the graph using BFS
	// for each element v in the queue, check its adjacent vertices w
	// calculate dist = distance[v] + G->Adj[v][w];
	// update distance[w] to be equal to G->Adj[v][w] if it's equal to -1, and enqueue w with priority equal to dist
	// OR
	// update distance[w] to be equal to G->Adj[v][w] if distance[w]>dist, and update the priority of w in the queue to be equal to dist
	// in both cases, update the entry of w in the path array to be equal to v
	EnQueue(&q, qElement, dist);
	distance[qElement] = 0;
	while (!isEmptyQueue(q))
	{
		Front(q, &qElement);
		DeQueue(&q);
		for (i = 0; i < G->V; i++)
		{
			dist = distance[qElement] + G->Adj[qElement][i];
			if (distance[i] == -1 && G->Adj[qElement][i] != 0)
			{
				distance[i] = G->Adj[qElement][i];
				EnQueue(&q, i, dist);
				Path[i] = qElement;
			}
			else if (distance[i] > dist && G->Adj[qElement][i] != 0)
			{
				distance[i] = G->Adj[qElement][i];
				update_priority(&q, i, dist);
				Path[i] = qElement;
			}
		}
	}

	// At the end, display the content of both path and distance tables.
	for (i = 0; i < G->V; i++)
	{
		printf("\nEdge %d-%d Weight %d" ,Path[i],i, distance[i]);
	}
  
}

void BellmanFord(Graph *G, int s) {

	// Declare the following:
	// 1* a queue
	// 2* a dynamic array containing the distance (all initialized to INT_MAX)
	// 3* a dynamic array containing the path between verticies
	// 4* a dynamic array containing whether a vertex is in the queue (all initialized to 0)
	queue q = CreateQueue();
	int i, qElement, dist,
		*distances = (int*)malloc(sizeof(G->V)),
		*InQueue = (int*)malloc(sizeof(G->V)),
		*Enqueued= (int*)malloc(sizeof(G->V)),
		*Path = (int*)malloc(sizeof(G->V));
	for (i = 0; i < G->V; i++)
	{
		distances[i] = INT_MAX;
		InQueue[i] = 0;
		Path[i] = -1;
		Enqueued[i] = 0;
	}
	EnQueue(&q, s);
	distances[s] = 0;
	Path[s] = s;

	// traverse the graph using BFS
	// w is the adjacents of v;
	// for each element v in the queue, check its adjacent vertices w
	// calculate dist = distance[v] + G->Adj[v][w];
	// update distance[w] if distance[w]>dist, and update the entry of w in the path array to be equal to v
	// and enqueue w if it's not already in the queue
	while (!isEmptyQueue(q))
	{
		Front(q, &qElement);
		DeQueue(&q);
		Enqueued[qElement] = 0;
		for (i = 0; i < G->V; i++)
		{
			if (G->Adj[qElement][i] != 0)
			{
				dist = distances[qElement] + G->Adj[qElement][i];
				if (distances[i] > dist)
				{
					distances[i] = dist;
					Path[i] = qElement;
					if (Enqueued[i] != 1)
					{
						EnQueue(&q, i);
						Enqueued[i] = 1;
					}
				}
			}
		}
	}





	// At the end, display the content of both path and distance tables.
	for (i = 0; i < G->V; i++)
	{
		printf("%d should be reached from %d of total weight %d\n", i, Path[i], distances[i]);
	}
 

	 
}


void test() {
	int u, v;
	Graph *G = adjacencyMatrix();
	Dijkstra(G, 0);
}


void main()
{
	test();
	getchar();
}
