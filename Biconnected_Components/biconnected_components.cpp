#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>adj[10];
vector<int>par(10,-1);
vector<bool>visit(10,false);
int low[10],demo[10];
int even=0,odd=0;
int tim=0;
stack<pair<int,int>>st;

void dfs(int u){
    visit[u]=true;
    low[u]=demo[u]=++tim;
    vector<int>::iterator it;
    int child=0;
    for(it=adj[u].begin();it!=adj[u].end();it++){
        int v=*it;
        if(!visit[v]){
            child++;
            par[v]=u;
            if(u<v)
            st.push(make_pair(u,v));
            else
            st.push(make_pair(v,u));
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(par[u]==-1 && child>1){
                int a=min(u,v);
                int b=max(u,v);

                set<int>count;
                while(!st.empty()){
                    pair<int,int>p=st.top();
                    if(a==p.first && b==p.second){
                        count.insert(p.first);
                        count.insert(p.second);
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                        count.insert(p.first);
                        count.insert(p.second);
                    }
                }
                if(count.size()%2!=0)odd++;
                else even++;
            }
            else if(par[u]!=-1 && low[v]>=demo[u]){
                int a=min(u,v);
                int b=max(u,v);

                set<int>count;
                while(!st.empty()){
                    pair<int,int>p=st.top();
                    if(a==p.first && b==p.second){
                        count.insert(p.first);
                        count.insert(p.second);
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                        count.insert(p.first);
                        count.insert(p.second);
                    }
                }
                if(count.size()%2!=0)odd++;
                else even++;
            }
        }
        else if(par[u]!=v && demo[v]<low[u]){
            low[u]=demo[v];
            if(u<v)
            st.push(make_pair(u,v));
            else
            st.push(make_pair(v,u));
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(!visit[i]){
            tim=0;
            dfs(i);
            set<int>count;
            while(!st.empty()){
                pair<int,int>p=st.top();
                count.insert(p.first);
                count.insert(p.second);
                st.pop();
            }

            if(count.size()%2!=0)odd++;
            else even++;
        }
    }

    cout << odd << " " << even << endl;
    return 0;
}