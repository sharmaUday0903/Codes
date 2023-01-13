// author : Uday Sharma
// 2022-12-19 14:54:09
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
    int n, r, m;
    cin >> n >> r >> m;
    vector<vi> adj(n + 1);
    REP(i, 0, r)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool ans = true;
    vi depth(n + 1, inf);
    vi vis(n + 1, false);
    // vi v(m);
    // REP(i, 0, m)
    // {
    //     int k, s;
    //     cin >> k >> s;
    // }
    REP(i, 0, m)
    {
        int k, s;
        cin >> k >> s;
        if (vis[k])
        {
            ans = false;
            // break;
        }
        else
        {
            vis[k] = true;
            depth[k] = 0;
            queue<int> q;
            q.push(k);
            while (!q.empty())
            {
                int f = q.front();
                q.pop();
                for (auto c : adj[f])
                {
                    if (depth[f] < s)
                    {
                        if (vis[c])
                        {
                            ans = false;
                            // break;
                        }
                        else
                        {
                            vis[c] = true;
                            depth[c] = depth[f] + 1;
                            q.push(c);
                        }
                    }
                }
            }
        }
    }

    ans ? cout << "Yes\n" : cout << "No\n";
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