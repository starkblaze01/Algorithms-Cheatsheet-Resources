// Union find algo to find connected components in a undirected graph
// Used Path compression and Ranking to optimize union find

#include<iostream>
#include<vector>

using namespace std;

vector<int> parent, ranks;

int Find (int x) {
	int tmp = x;
	while (parent[x] != x) x = parent[x];

	parent[tmp] = x; // Path compression
	return x;
}

bool Union (int x, int y) {
	int px = Find(x), py = Find(y);

	if (px == py) {
		// already belong to the same component
		return false;
	}
	else if (ranks[px] > ranks[py]) {
		parent[py] = px;
	}
	else {
		parent[px] = py;
		if (ranks[px] == ranks[py]) {
			ranks[py]++;
		}
	}
	return true;
}

int main () {
	int V, E;
	cout<<"Enter the number of vertices (V):"<<endl;
	cin>>V;

	cout<<endl;

	cout<<"Enter the number of edges (E):"<<endl;
	cin>>E;

	cout<<endl;

	// filling the union-find's parent and ranks array
	parent = vector<int>(V);
	ranks = vector<int>(V, 0);
	for (int i = 0; i < V; i++) parent[i] = i;

	cout<<"Enter the edges as 'u v' meaning undirected edge between u and v"<<endl;
	cout<<"[Note: vertices are numbered from 0 to V-1]"<<endl;

	for (int i = 0; i < E; i++) {
		int a, b;
		cin>>a>>b;
		Union(a,b);
	}


	cout<<endl;

	// Printing the connected components
	vector<vector<int>> comps (V);
	for (int i = 0; i < V; i++) {
		comps[Find(i)].push_back(i);
	}

	cout<<"Following connected components are present in the graph:"<<endl;
	int i = 1;
	for (vector<int> c : comps) {
		if (c.empty()) continue;
		cout<<"Component "<<i<<": ";
		for (int v : c) {
			cout<<v<<" ";
		}
		i++;
		cout<<endl;
	}
}
