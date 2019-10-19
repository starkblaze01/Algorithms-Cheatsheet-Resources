// A C++ program to print topological sorting of a DAG 

#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 

// Class to represent a graph 
class Graph 
{ 
	int V; 

	// Pointer to an array containing adjacency listsList 
	list<int> *adj; 

	// A function used by topologicalSort 
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
	Graph(int V); // Constructor 

	// function to add an edge to graph 
	void addEdge(int v, int w); 

	// prints a Topological Sort of the complete graph 
	void topologicalSort(); 
}; 
// Constructor for the Graph class
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

// A recursive function used by topologicalSort 
void Graph::topologicalSortUtil(int v, bool visited[], 
								stack<int> &Stack) 
{ 
	// Mark the current node as visited. 
	visited[v] = true; 

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			topologicalSortUtil(*i, visited, Stack); 

	// Push current vertex to stack which stores result 
	Stack.push(v); 
} 

// The function to do Topological Sort. It uses recursive 
// topologicalSortUtil() 
void Graph::topologicalSort() 
{ 
	stack<int> Stack; 

	// Marking all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Calling the recursive helper function to store Topological Sort starting from all vertices one by one 
	for (int i = 0; i < V; i++) 
	if (visited[i] == false) 
		topologicalSortUtil(i, visited, Stack); 

	// Printing the contents of stack 
	while (Stack.empty() == false) 
	{ 
		cout << Stack.top() << " "; 
		Stack.pop(); 
	} 
} 

int main() 
{ 
	// Create a graph given in the above diagram 
  int n,e,i,x,y;
  cout<<"Enter the number of vertices\n";
  cin>>n;
	Graph g(n); 
  cout<<"Enter the number of edges\n";
  cin>>e;
  cout<<"Enter the edges\n";
  for(i=0;i<e;i++)
  {
    cin>>x;
    cin>>y;
    g.addEdge(x,y);
  }

	cout << "Following is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
} 
