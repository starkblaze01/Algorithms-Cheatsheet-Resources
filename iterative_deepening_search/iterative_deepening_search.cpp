// C++ program to search if a target node is reachable from 
// a source with given max depth. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Graph class represents a directed graph using adjacency 
// list representation. 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A function used by IDDFS 
    bool DLS(int v, int target, int limit); 
  
public: 
    Graph(int V);   // Constructor 
    void addEdge(int v, int w); 
  
    // IDDFS traversal of the vertices reachable from v 
    bool IDDFS(int v, int target, int max_depth); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
// A function to perform a Depth-Limited search 
// from given source 'src' 
bool Graph::DLS(int src, int target, int limit) 
{ 
    if (src == target) 
        return true; 
  
    // If reached the maximum depth, stop recursing. 
    if (limit <= 0) 
        return false; 
  
    // Recur for all the vertices adjacent to source vertex 
    for (auto i = adj[src].begin(); i != adj[src].end(); ++i) 
       if (DLS(*i, target, limit-1) == true) 
          return true; 
  
     return false; 
} 
  
// IDDFS to search if target is reachable from v. 
// It uses recursive DFSUtil(). 
bool Graph::IDDFS(int src, int target, int max_depth) 
{ 
    // Repeatedly depth-limit search till the 
    // maximum depth. 
    for (int i = 0; i <= max_depth; i++) 
       if (DLS(src, target, i) == true) 
          return true; 
  
    return false; 
} 
  
// Driver code 
int main() 
{ 
    // Let us create a Directed graph with 7 nodes 
    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 6); 
  
    int target = 6, maxDepth = 3, src = 0; 
    if (g.IDDFS(src, target, maxDepth) == true) 
        cout << "Target is reachable from source "
                "within max depth"; 
    else
        cout << "Target is NOT reachable from source "
                "within max depth"; 
    return 0; 
} 