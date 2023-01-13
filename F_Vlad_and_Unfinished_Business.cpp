// author : Uday Sharma
// 2022-12-18 15:17:25
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

vector<vi> adj;
vector<bool> todo, good;

void dfs(int x, int p)
{
    for (auto u : adj[x])
    {
        if (u != p)
        {
            dfs(u, x);
            if (todo[u])
            {
                todo[x] = true;
            }
            if (good[u])
            {
                good[x] = true;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj.clear();
    adj.resize(n);
    todo.resize(n);
    fill(todo.begin(), todo.end(), false);
    good.resize(n);
    fill(good.begin(), good.end(), false);
    REP(i, 0, m)
    {
        int v;
        cin >> v;
        v--;
        todo[v] = true;
    }
    good[y] = true;
    REP(i, 0, n-1)
    {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(x,-1);
    int ans = 0;
    REP(i, 0, n)
    {
        if (i == x)
        {
            continue;
        }
        if (good[i])
        {
            ans++;
        }
        else if (todo[i])
        {
            ans += 2;
        }
    }
    cout << ans << endl;
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