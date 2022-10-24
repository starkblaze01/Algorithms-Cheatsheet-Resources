// Problem Link :- https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/D


/*
There is an array of n elements, initially filled with zeros. You need to write a data structure that processes two types of queries:
- add v to the segment from l to r−1,
- find the sum on the segment from l to  r−1
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long


struct segtree {
    int siz;
    long long NO_OPERATION = 0;
    long long NEUTRAL_ELEMENT = 0;
    vector<long long>values;
    vector<long long>operations;

    void init(int n) {
        siz = 1;
        while (siz < n) {
            siz *= 2;
        }
        values.assign(2 * siz, 0ll);
        operations.assign(2 * siz, 0ll);
    }

    long long modify_op(long long a, long long b, long long len) {


        return a + (b * len);
    }

    long long cal_op(long long a, long long b) {
        return a + b;
    }

    void apply_mod_op(long long &a, long long b, long long len) {
        a = modify_op(a, b, len);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        int md = (lx + rx) / 2;

        
        apply_mod_op(operations[2 * x + 1], operations[x], 1);
        apply_mod_op(values[2 * x + 1], operations[x], md - lx);
        apply_mod_op(operations[2 * x + 2], operations[x], 1);
        apply_mod_op(values[2 * x + 2], operations[x], rx - md);

        operations[x] = NO_OPERATION;
    }



    void modify(int l, int r, int val, int si, int ss, int se) {
        propagate(si, ss, se);
        if (r <= ss || l >= se) {
            return;
        }
        if (l <= ss && r >= se) {
            apply_mod_op(operations[si], val, 1);
            apply_mod_op(values[si], val, se - ss);
            // cout << (si) << " " << values[si] << endl;;
            return;
        }

        int mid = (ss + se) / 2;
        modify(l, r, val, 2 * si + 1, ss, mid);
        modify(l, r, val, 2 * si + 2, mid, se);

        values[si] = cal_op(values[2 * si + 1], values[2 * si + 2]);

    }

    void modify(int l, int r, int val) {
        modify(l, r, val, 0, 0, siz);
    }


    int calc(int l, int r, int si, int ss, int se) {
        propagate(si, ss, se);
        if (r <= ss || l >= se) {
            return NEUTRAL_ELEMENT;
        }
        if (l <= ss && r >= se) {
            return values[si];
        }

        int mid = (ss + se) / 2;
        int a = calc(l, r, 2 * si + 1, ss, mid);
        int b = calc(l, r, 2 * si + 2, mid, se);

        return cal_op(a, b);
    }

    int calc(int l, int r) {
        return calc(l, r, 0, 0, siz);
    }

};


int32_t main() {
    int n, q; cin >> n >> q;
    vector<long long> v(n);
    segtree st;
    st.init(n);

    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            long long l, r,  v;
            cin >> l >> r >> v;
            st.modify(l, r, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.calc(l, r) << endl;
        }
    }

}

// Input

/*
5 6
1 0 3 3
2 1 2
1 1 4 4
2 1 3
2 1 4
2 3 5

*/

// Output
/*
3
14
18
4

*/
