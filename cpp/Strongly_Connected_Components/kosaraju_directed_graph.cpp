// KOSARAJU'S algo to find strongly connected components in a directed graph
// Time:- O(V+E)

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> revgraph; // stores transpose of original graph

// 2 visited arrays required because DFS is performed 2 times
vector<bool> vis1, vis2;

stack<int> st;

vector<int> comp;

void dfs (int u) {
	vis1[u] = true;
	for (int v : graph[u]) {
		if (!vis1[v]) {
			dfs(v);
		}
	}
	st.push(u);
}

void dfsutil (int u) {
	comp.push_back(u);
	vis2[u] = true;
	for (int v : revgraph[u]) {
		if (!vis2[v]) {
			dfsutil(v);
		}
	}
}

int main () {
	int V, E;
	cout<<"Enter the number of vertices (V):"<<endl;
	cin>>V;

	cout<<endl;

	cout<<"Enter the number of edges (E):"<<endl;
	cin>>E;

	cout<<endl;

	graph = vector<vector<int>> (V, vector<int>());
	revgraph = vector<vector<int>> (V, vector<int>());

	vis1 = vector<bool>(V, false);
	vis2 = vector<bool>(V, false);

	cout<<"Enter the edges as 'u v' meaning directed edge from u to v"<<endl;
	cout<<"[Note: vertices are numbered from 0 to V-1]"<<endl;

	for (int i = 0; i < E; i++) {
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b);
	}

	// Kosaraju's algo
	
	// Step 1: 1st DFS
	// to store the vertices on the basis of their finish time
	for (int i = 0; i < V; i++) {
		if (!vis1[i]) {
			dfs(i);
		}
	}

	// Step 2: Transpose of graph 
	// i.e. reverse all edges
	for (int i = 0; i < V; i++) {
		vector<int> adj = graph[i];
		for (int dest : adj)
			revgraph[dest].push_back(i);
	}

	vector<vector<int>> scc; // answer

	// 3. 2nd DFS on transposed graph
	// vertices taken in the order in which they were stored
	// after the 1st DFS
	while (!st.empty()) {
		int u = st.top();
		st.pop();

		comp = vector<int>(); // stores current component
		if (!vis2[u]) {
			dfsutil(u);
			scc.push_back(comp); // add to answer
		}
	}

	cout<<endl;

	// SCCs
	cout<<"Following strongly connected components are present in the graph:"<<endl;
	int i = 1;
	for (vector<int> c : scc) {
		cout<<"Component "<<i<<": "<<endl;
		for (int v : c)
			cout<<v<<" ";
		cout<<endl;
		i++;
	}
}
