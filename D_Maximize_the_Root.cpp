// 2024-07-30 20:32:30
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define pii pair<int, int>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pb push_back
#define mp make_pair
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
#define ub(v, idx, val) upper_bound(v.begin() + idx, v.end(), val)
#define lb(v, idx, val) lower_bound(v.begin() + idx, v.end(), val)

#define vvi vector<vi>
const double pi = 3.14159265358979323846;
const int INF = 1e15;
int ans;
void dfs(int u, vvi &adj, vi &a, vi &dp)
{
    int mx = INF;
    for (auto c : adj[u])
    {
        dfs(c, adj, a, dp);
        mx = min(mx, dp[c]);
    }
    if (mx == INF)
    {
        dp[u] = a[u];
    }
    else
    {
        if (a[u] >= mx)
        {
            dp[u] = mx;
        }
        else
        {
            dp[u] = (mx + a[u]) / 2;
        }
    }
    if (u == 0)
    {
        ans = a[0] + mx;
    }
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    vvi adj(n);
    REP(i, 0, n - 1)
    {
        int x;
        cin >> x;
        x--;
        adj[x].pb(i + 1);
    }
    ans = 0;
    vi dp(n, INF);
    dfs(0, adj, a, dp);
    cout << ans << endl;
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}