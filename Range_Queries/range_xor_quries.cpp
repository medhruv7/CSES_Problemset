#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Code

    int n,q;
    cin >> n >> q;

    int a[n];
    int xr[n + 1];
    for(int i = 0;i < 32; ++i){
        xr[0] = 0;
    }

    for(int i = 0;i < n; ++i) {
        cin >> a[i];
    }

    for(int i = 1;i <= n; ++i) {
            xr[i] = a[i - 1]^xr[i - 1];
    }

    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << (xr[b]^xr[a - 1]) << '\n';
    }
}