#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 9 

int minDistance(int dist[], bool sptSet[])
{
    int min=INT_MAX, min_index;
    for(int i=0;i<9;i++)
    {
        if(sptSet[i]==false && dist[i]<min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
int printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
}
void dijsktra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for(int i=0;i<V;i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for(int count= 0; count < V-1;count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u]=true;
        for(int v=0;v<V;v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}
// driver program to test above function 
int main() 
{ 
    int graph[V][V] ;
                        
    printf("Enter a 9*9 representation of the input graph\n");
    // note : 0 means no edge, and any finite number means there is a directed edge with the respective weight
    for(int v=0;v<V;v++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&graph[v][j]);
        }
    }
  
    dijsktra(graph, 0); 
  
    return 0; 
} 
