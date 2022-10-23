#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[j-1] < a[i] && a[i] < d[j])
                d[j] = a[i];
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 6, 1, 2, 7, 10, 4, 50, 60};
    cout << lis(arr) << endl;
}
/*
> Time Complexity: O(n log n)
> Related Problems
* https://codeforces.com/problemsets/acmsguru/problem/99999/521
* https://www.spoj.com/problems/DOSA/
* https://codeforces.com/contest/76/problem/F
* https://codeforces.com/problemset/problem/10/D
*/
