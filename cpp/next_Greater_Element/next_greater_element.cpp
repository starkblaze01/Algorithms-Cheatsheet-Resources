// Aviral Gupta
#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
#define LM 1e18
#define ll  long long int
#define ld long double
#define ms(dp,val) memset(dp,val,sizeof(dp))
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) ((i >= min(a, b)) && (i <= max(a, b)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second 
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
const ll mod=998244353;
inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< pll > vpi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;

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
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    next_greater(a);
    
}