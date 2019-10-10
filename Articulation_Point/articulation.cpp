#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>adj[11];
vector<bool>visit(11,false);
vector<int>art;
vector<pair<int,int>> brid;
int tim=0;
int deno[11];
int low[11];
vector<int>par(11,-1);

void dfs(int u){
    visit[u]=true;
    vector<int>::iterator it;
    int child=0;
    low[u]=deno[u]=++tim;
    for(it=adj[u].begin();it!=adj[u].end();it++){
        int v = *it;
        if(!visit[v]){
            child++;
            par[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(deno[u]<low[v]){
                int x = min(u,v);
                int y = max(u,v);
                brid.push_back(make_pair(x,y));
            }
            if(child>=2 && par[u]==-1){
                art.push_back(u);
            }
            else if(par[u]!=-1 && deno[u]<=low[v]){
                art.push_back(u);
            }
        }
        else if(par[u]!=v){
            low[u]=min(low[u],deno[v]);
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int src,des;
        cin >> src >> des;
        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    for(int i=0;i<n;i++){
        dfs(i);
    }
    cout << art.size() << endl;
    sort(art.begin(),art.end());
    sort(brid.begin(),brid.end());
    for(int i=0;i<art.size();i++){
        cout << art[i] << " ";
    }
    cout << endl;
    cout << brid.size() << endl;
    for(int i=0;i<brid.size();i++){
        pair<int,int>p=brid[i];
        cout << p.first << " " << p.second << endl;
    }

}