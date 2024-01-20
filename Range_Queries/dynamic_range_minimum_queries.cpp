#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()

vector<ll> seg;

const int INF = 1e9 + 10;

void printTree() {
    cout << '\n';
    for(int i = 1;i < seg.size(); ++i) {
        cout << seg[i] << ' ';
    }
    cout << '\n';
}

int build(int arr[], int &n){
    int tree_size = 1;
    while(tree_size < n){
        tree_size *= 2;
    }

    seg.resize(2*tree_size);

    for(int i = 0;i < n; ++i){
        seg[i + tree_size] = arr[i];
    }

    for(int i = tree_size + n; i < 2*tree_size; i++) {
        seg[i] = INF;
    }

    for(int i = tree_size - 1; i > 0; i--) {
        seg[i] = min(seg[2*i], seg[2*i + 1]);
    }

    return tree_size;
}

ll query(int low, int high, int node_low, int node_high, int node) {
    if(low <= node_low && high >= node_high) {
        return seg[node];
    }
    if(low > node_high || high < node_low) {
        return INF;
    }

    ll half = (node_low + node_high)>>1LL;

    return min(query(low, high, node_low, half, 2*node), query(low, high, half + 1, node_high, 2*node + 1));
}

ll update(int node_low, int node_high,int k,int u,int node) {
    if(node_low == k && node_high == k) {
        return seg[node] = u;
    }
    if(node_low <= k && node_high >= k) {
        ll half = (node_low + node_high)>>1LL;
        seg[node] = min(update(node_low, half, k, u, 2*node), update(half + 1, node_high, k, u, 2*node + 1));
    }

    return seg[node];
}

int main()
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

    while(q--) {
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
            cout << query(a, b, 0, sz - 1, 1) << '\n';
        }
    }
}