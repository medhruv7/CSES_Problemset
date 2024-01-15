#include "../bits/stdc++.h"
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

    ll arr[n + 1];

    for(int i = 1;i <= n; ++i){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }
}