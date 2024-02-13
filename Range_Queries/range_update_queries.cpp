#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()

vector<ll> tree;

ll query(int l, int r, int tree_l, int tree_r, int node) {
    if(l <= tree_l && r >= tree_r) {
        return tree[node];
    }
    if(l > tree_r || r < tree_l) return 0;

    int mid = ((tree_l + tree_r)>>1);

    return query(l, r, tree_l, mid, 2*node) + query(l, r, mid + 1, tree_r, 2*node + 1);
}

ll update(int tree_l, int tree_r, int idx, int val, int node) {
    if(tree_l == idx && tree_r == idx) {
        return tree[node] += val;
    }
    if(idx >= tree_l && idx <= tree_r) {
        int mid = (tree_l + tree_r)>>1;
        tree[node] = update(tree_l, mid, idx, val, 2*node) + update(mid + 1, tree_r, idx, val, 2*node + 1);
    }

    return tree[node];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Code

    int n,q;
    cin >> n >> q;

    int pad = 1;
    while(pad < n) {
        pad <<= 1;
    }
    tree.resize(2*pad);

    ll a[n];
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l,r,v;
            cin >> l >> r >> v;
            --l, --r;
            update(0, n - 1, l, v, 1);
            update(0, n - 1, r + 1, -v, 1);
        }else{
            int idx;
            cin >> idx;
            --idx;
            cout << (a[idx] + query(0, idx, 0, n - 1, 1)) << '\n';
        }
    }
}