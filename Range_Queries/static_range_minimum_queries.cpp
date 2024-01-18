#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Code

    int n, q;
    cin >> n >> q;

    int lg[n + 1];
    lg[1] = 0;
    lg[2] = 1;

    for (int i = 3; i <= n; ++i)
    {
        lg[i] = lg[i / 2] + 1;
    }

    int arr[n];
    int st[25][n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        st[0][i] = arr[i];
    }

    for (int p = 1; p < 25; ++p)
    {
        for (int i = 0; i + (1 << p) <= n; ++i)
        {
            st[p][i] = min(st[p - 1][i], st[p - 1][i + (1 << (p - 1))]);
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int len = (r - l + 1);
        cout << min(st[lg[len]][l], st[lg[len]][r - (1<<lg[len]) + 1]) << '\n';
    }
}