// author : Uday Sharma
// 2022-11-03 23:17:59
#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define inf 1000000000000000005
#define int long long int

void solve()
{
    int p;
    cin >> p;
    int n = 1 << p;
    vector<vector<array<int, 2>>> adj(n);
    vi a(n), b(n - 1);
    REP(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    a[0] = 1 << p;
    auto dfs = [&](auto dfs, int u, int pa, int d) -> void
    {
        for (auto [v, j] : adj[u])
        {
            if (v == pa)
            {
                continue;
            }
            if (d)
            {
                b[j] = v ^ n;
                a[v] = v;
            }
            else
            {
                b[j] = v;
                a[v] = v ^ n;
            }
            dfs(dfs, v, u, !d);
        }
    };
    dfs(dfs, 0, -1, -1);
      cout << "1\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << b[i] << " \n"[i == n - 2];
    }
}
signed main()
{
    fast;
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}