#include <bits/stdc++.h>

using namespace std;

int sum = 0;

void addEdge(vector <int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int dfs(vector <int> graph[], int u, vector <bool & visited)
{
    visited[u] = true;
    sum += u;
    for(int i = 0; i < graph[u].size(); ++i)
        if(visited[graph[u][i]] == false)
            dfs(graph, u, visited);

    return sum;
}

void dfsForAll(vector <int> graph[],int v)
{
    vector<bool> visited(v, false);
    for(int u = 0; u < v; u++)
        if(visited[u] == false)
            dfs(graph, u, visited);
}

int main()
{
    int height, n;
    cin >> height;


    return 0;
}
