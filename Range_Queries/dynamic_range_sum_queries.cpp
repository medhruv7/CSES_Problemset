#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define int long long
#define all(a) a.begin(), a.end()

vector<ll> seg;

void printTree() {
    cout << '\n';
    for(int i = 1;i < seg.size(); ++i) {
        cout << seg[i] << ' ';
    }
    cout << '\n';
}

int build(int arr[], int &arr_size) {
    ll tree_size = 1;
    while(tree_size < arr_size) {
        tree_size = tree_size<<1LL;
    }

    seg.resize(tree_size<<1LL);

    // leaf
    for(int i = 0;i < arr_size; ++i){
        seg[tree_size + i] = arr[i];
    }

    // parent using dp
    for(int i = tree_size - 1;i > 0; i--) {
        seg[i] = seg[2*i] + seg[2*i + 1];
    }

    return tree_size;
}

ll query(int node_low, int node_high, int low, int high, int node) {
    // Interval fully inside query range
    if(low <= node_low && high >= node_high){
        return seg[node];
    }

    // Interval totally disjoint
    if(high < node_low || low > node_high) {
        return 0;
    }

    // Interval partially inside 
    ll half = (node_high + node_low)>>1LL;
    return query(node_low, half, low, high, 2*node) + query(half + 1, node_high, low, high, 2*node + 1);
}

ll update(int node_low, int node_high, int k, int u,int node) {
    if(k == node_low && k == node_high){
        return seg[node] = u;
    }
    if(k >= node_low && k <= node_high) {
        ll half = (node_low + node_high)>>1LL;
        seg[node] = update(node_low, half, k, u, 2*node) + update(half + 1, node_high, k, u, 2*node + 1);
    }

    return seg[node];
 }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Code
    int n,q;
    cin >> n >> q;

    int arr[n];

    for(int i = 0;i < n; ++i){
        cin >> arr[i];
    }

    int sz = build(arr, n);

    // printTree();

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k,u;
            cin >> k >> u;
            k--;
            update(0, sz - 1, k, u, 1);
        }else{
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            cout << query(0, sz - 1, a, b, 1) << '\n';
        }
    }
}