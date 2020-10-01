// C++ code to print topological sort of given graph
// using Kahn's Alogirthm (BFS)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> topologicalSort (vector<vector<int>> graph, int V) {
	// Compute in-degrees for each vertex
	vector<int> indeg(V, 0);
	for (int i = 0; i < V; i++) {
		for (int j : graph[i]) {
			indeg[j]++;
		}
	}
	
	// BFS
	queue<int> q;

	// start with the vertices which have in-degree = 0
	for (int i = 0; i < V; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> ans;
	vector<bool> vis(V, false);
	int remaining = V;

	while (!q.empty() && remaining) {
		// stop if queue is empty, or all vertices are visited
		
		int u = q.front();
		q.pop();

		if (vis[u]) continue;
		vis[u] = true;
		remaining--;

		ans.push_back(u);

		// remove the vertex u from the graph
		// and all the edges coming out of it
		// and update the neighbor's in-degree
		for (int v : graph[u]) {
			indeg[v]--;

			// add the vertices to queue for which
			// in-degree becomes 0
			if (indeg[v] == 0) {
				q.push(v);
			}
		}

	}

	// if there is still some unvisited vertex, then topological sort not possible
	if (remaining) return {};

	return ans;
}

int main () {
	int V;
	cout<<"Enter the number of vertices (V) (should be > 0):"<<endl;
	cin>>V;
	cout<<endl;

	int E;
	cout<<"Enter the number of edges (E):"<<endl;
	cin>>E;
	cout<<endl;

	// adjacency list representation of the directed graph
	vector<vector<int>> graph(V); 

	// Assuming that the vertices are numbered from 0 to V-1
	cout<<"Enter each edge in separate line as 'u v', which means a directed edge from u to v"<<endl;
	cout<<"[NOTE: vertices are numbered from 0 to V-1]"<<endl;
	for (int i = 0; i < E; i++) {
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

	vector<int> sorted = topologicalSort(graph, V);

	cout<<endl;
	if (sorted.empty()) {
		cout<<"Topological sort not possible for the given graph"<<endl;
	}
	else {
		cout<<"One possible ordering for vertices is:-"<<endl;
		for (int v : sorted) {
			cout<<v<<" ";
		}
		cout<<endl;
	}
}
