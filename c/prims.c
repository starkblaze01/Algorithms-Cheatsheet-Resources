#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 5

int minKey(int key[], bool mstSet[])
{
    int min=INT_MAX, min_index;
    for(int i=0;i<V;i++)
    {
        if(mstSet[i]==false && key[i]<min)
        {
            min = key[i], min_index=i;
        }
    }
    return min_index;
}
void printMst(int parent[],int graph[V][V])
{
    printf("Edge \tWeight\n"); 
    for (int i = 1; i < V; i++) 
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void primMst(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    
    // Initializing all keys as INFINITE 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
        
    key[0]=0;
    parent[0]=-1;
    
    for(int j=0;j<V-1;j++)
    {
        int u;
        u=minKey(key, mstSet);
        mstSet[u]=true;
        
        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
            {
                key[v]=graph[u][v], parent[v]=u;
            }
        }
    }
    printMst(parent, graph);
}
int main()
{
    int graph[V][V];
    // We are using a 5*5 graph
    printf("Enter a 5*5 representation of the input graph\n");
    // note : 0 means no edge, and any finite number means there is a directed edge with the respective weight
    for(int v=0;v<V;v++)
    {
        for(int j=0;j<V;j++)
        {
            scanf("%d",&graph[v][j]);
        }
    }
    primMst(graph);
    return 0;
}
