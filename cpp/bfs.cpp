#include <iostream>
#include <vector>
#include<map>
#include<queue>
using namespace std;

class graph
{
    private:
    int vertices;
    map<int,vector<int>> vec;
    public:
    graph(int v)
    {
       vertices = v; 
    }
    void addEdge(int start,int end);
    void display();
    void bfs(int startpt);
};
void graph::addEdge(int start,int end)
{
    
    vec[start].push_back(end);

}
void graph::display()
{
    /*for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<vec[i][j];
    }*/
    for(auto it:vec)
    {
        cout<<it.first<<"->";
        for (int j=0;j<it.second.size();j++)
        {
            cout<<it.second[j]<<" ";
        }
        cout<<"\n";
    }
}
void graph::bfs(int startpt)
{
    queue<int> q;
    vector<int> visited ={0};
    q.push(startpt);
    visited[startpt]++;
    while(q.size())
    { 
        int i = q.front();
        cout<<q.front()<<" ";
        q.pop();
        
        for(int j=0;j<vec[i].size();j++ )
        {   if(!visited[vec[i][j]])
                q.push(vec[i][j]);
            visited[vec[i][j]]++;
        }
    }
    
}
int main() {
	
	graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	//g.display();
	g.bfs(2);
	return 0;
}