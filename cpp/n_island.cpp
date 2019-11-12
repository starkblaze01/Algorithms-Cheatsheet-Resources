//https://www.geeksforgeeks.org/find-number-of-islands/
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int l;
int issafe(vector<vector<int> > &ar,vector<vector<int> > &visited,int i,int j)
{
    if(i>=0 && i<5 && j>=0 && j<5 && !visited[i][j] && ar[i][j] )
        return 1;
    return 0;
}
int dfs(vector<vector<int> > &ar,vector<vector<int> > &visited,int m,int n)
{
    int xoff[8] = {-1,0,1,-1,1,-1,0,1};
    int yoff[8] = {-1,-1,-1,0,0,1,1,1};
    visited[m][n] = 1;
    for(int k=0;k<8;k++)
    {
        if(issafe(ar,visited,xoff[k]+m,yoff[k]+n))
            dfs(ar,visited,xoff[k]+m,yoff[k]+n);
    }
}

int island(vector<vector<int> > ar)
{
    //int visited[5][5];
    //memset(visited, 0, sizeof(visited));
    vector<vector<int> > visited(l,vector<int>(l,0));
    int count =0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(ar[i][j] && !visited[i][j])
             {
                dfs(ar,visited,i,j);
                count++;
             }
        }
    }
    cout<<count;
}
int main()
{
    int a[5][5]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
    l = sqrt(sizeof(a)/sizeof(int));
    vector <vector<int> > ar(l, vector<int>(l));
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            ar[i][j] = a[i][j];
        }
    }
    /*for(int i=0;i<l;i++)
    {
        for(int j=0;j<l;j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }*/
    island(ar);
    return 0;
}