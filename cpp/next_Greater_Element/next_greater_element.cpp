#include<bits/stdc++.h>
using namespace std;

void next_greater(vector<int> &A)
{
    stack<int> s; int n=A.size();
    int ng[n];
    s.push(0);
    for(int i=1;i<n;i++)
    {
        while(!s.empty()&&A[i]>A[s.top()])
        {
            ng[s.top()]=i;  s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        ng[s.top()]=-1;
        s.pop();
    }

    for(int i=0;i<n;i++) if(ng[i]!=-1) cout<<A[i]<<"-->"<<A[ng[i]]<<endl;
}

int main()
{
    int n;
    cout << "Enter the number of Elements: ";
    cin>>n;
    vector<int> a(n);
    cout << "\nEnter the Elements: ";

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    next_greater(a);

} 
