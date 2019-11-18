#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
//Declaring an edge as structure
struct  Edge
{
	int src, dest, weight;
};

struct Graph
{
	int V;	//Number of vertices of graph
	int E;	//Number of edges
	struct Edge* edges;
};
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph =(struct Graph*)malloc(sizeof(struct Graph));
	graph->V=V;
	graph->E=E;
	graph->edges = (struct Edge*)malloc(E*sizeof(struct Edge));
	return graph;
}

// A utility function used to print the solution 
void printArr(int dist[], int n) 
{ 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
}
void BellmanFord(struct Graph* graph, int src)
{
	int V=graph->V;
	int E=graph->E;
	int dist[V];

	//printf("Reached in the function\n");
	for (int i = 0; i < V; ++i)
	{
		dist[i]=INT_MAX;
	}
	dist[src]=0;

	//Relaxing each edge for a total of V-1 times
	for (int i = 1; i <= V-1; ++i)
	{
		for (int j = 0; j < E; ++j)
		{
			//printf("%d and %d\n", i, j);
			int u=graph->edges[j].src;
			int v=graph->edges[j].dest;
			int wt=graph->edges[j].weight;
			if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
				dist[v]=dist[u]+wt;
		}
	}

	//Checking for negative weight cycles
	for (int i = 0; i < E; ++i)
	{
		int u = graph->edges[i].src;
		int v = graph->edges[i].dest;
		int wt = graph->edges[i].weight;
		if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
			printf("Graph contains a negative weight cycle\n");
			return;
		}
	}
	printArr(dist, V);
	return;
}
int main()
{
	int V,E;
	printf("Enter the number of vertices and edges\n");
	scanf("%d%d",&V,&E);
	struct Graph* graph = createGraph(V,E);
	printf("Enter the src, dest and weight\n");
	for (int i = 0; i < E; ++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		graph->edges[i].src=x;
		graph->edges[i].dest=y;
		graph->edges[i].weight=z;
	}

	BellmanFord(graph, 0);
		
}
