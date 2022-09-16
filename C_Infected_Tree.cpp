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
#define int long long int

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        REP(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int> depth(n);
        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int p)
        {
            int deg = 0;
            for (auto v : adj[u])
            {
                if (v == p)
                {
                    continue;
                }
                depth[v] = depth[u] + 1;
                dfs(v, u);
                deg++;
            }

            if (deg < 2)
            {
                ans = max(ans, n - 2 * depth[u] - 1 - deg);
            }
        };
        dfs(0, -1);
        cout << ans << endl;
    }
}