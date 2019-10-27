#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int dest, src, weight;
};
struct Graph
{
    int V,E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E= E;
    graph->edge = new Edge[E];
    return graph;
}
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
    
    //Initialsing all distances to 0
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    
    // Relaxing all edges V-1 times
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u=graph->edge[j].src;
            int v=graph->edge[j].dest;
            int wt=graph->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[v]>dist[u] + wt)
                dist[v]=dist[u]+wt;
        }
    }
    // Checking for negative weight cycles
    for (int i = 0; i < E; i++) { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
            printf("Graph contains negative weight cycle"); 
            return; // If negative cycle is detected, simply return 
        } 
    } 
    printArr(dist, V); 
  
    return; 
}
int main() 
{ 
    int V ; // Number of vertices in graph 
    int E ; // Number of edges in graph 
    cout<<"Enter the number of vertices and edges in the given graph\n";
    cin>>V>>E;
    struct Graph* graph = createGraph(V, E); 
    cout<<"Enter the source destination and weight of the graph\n";
    int i;
    for(i=0;i<E;i++)
    {
        cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
    }
    int src;
    cout<<"Enter the source vertex\n";
    cin>>src;
    BellmanFord(graph, src);
    return 0;
}
