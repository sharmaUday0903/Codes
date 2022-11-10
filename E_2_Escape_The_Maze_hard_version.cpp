// author : Uday Sharma
// 2022-11-02 10:05:53
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

vi nearest_red;
vi dist;
vector<vi> adj;
int n, k;
vector<bool> isred;
bool ok = true;
int ans;

void dfs(int curr_node, int par)
{
    if (curr_node != 1)
    {
        dist[curr_node] = dist[par] + 1;
    }
    if (isred[curr_node])
    {
        nearest_red[curr_node] = 0;
    }
    int ctr = 0;
    for (auto c : adj[curr_node])
    {
        if (c == par)
        {
            continue;
        }
        dfs(c, curr_node);
        nearest_red[curr_node] = min(nearest_red[curr_node], 1 + nearest_red[c]);
    }
}

void dfs2(int curr_node, int par)
{
    if (curr_node != 1 and adj[curr_node].size() == 1)
    {
        ok = true;
        return;
    }
    for (auto x : adj[curr_node])
    {
        if (x == par)
            continue;
        ;
        if (nearest_red[x] > dist[x])
            dfs2(x, curr_node);
        else
            ans++;
    }
}

void solve()
{
    cin >> n >> k;
    isred.assign(n + 1, false);
    adj.assign(n + 1, {});
    nearest_red.assign(n + 1, inf);
    dist.assign(n + 1, 0);
    REP(i, 1, k + 1)
    {
        int xx;
        cin >> xx;
        isred[xx] = true;
    }
    REP(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans = 0;
    ok = false;
    dfs(1, -1);
    dfs2(1, -1);
    if (!ok)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
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