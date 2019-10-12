/*****************************************************

@author: vichitr
Compiled On: 12th Oct 2019

*****************************************************/
#include<bits/stdc++.h>
#define MAX 9223372036854775807
#define endl "\n"
#define ll long long
#define int long long

#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
using namespace std;

const ll MOD = 1e9+7;
const ll SZ = 107;
const ll N = 3e5+1;
const ll M = 2e5+7;

ll pwr(ll x, ll y)
{
    ll r = 1LL;
    while(y)
    {
        if(y&1)
            r = (r * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return r;
}

int inv(int x)
{
	return pwr(x, MOD-2ll);
}


void solve()
{
	int x, y; cin>>x>>y;
    cout<<pwr(x, y)<<endl;
}

signed main()
{
    fast;
    int t=1;
    cin >>t;
    while(t--){
        solve();
        
    }
    return 0;
}

/*****************************



****************************/
