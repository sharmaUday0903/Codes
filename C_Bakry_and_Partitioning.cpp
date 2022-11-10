// author : Uday Sharma
// 2022-10-30 22:44:49
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

const int N = 1e5 + 5;
vi adj[N];
int val[N], xor_arr[N];
bool vis[N];
int cnt = 0;

int dfs1(int u)
{
    xor_arr[u] = val[u];
    vis[u] = true;
    for (auto c : adj[u])
    {
        if (!vis[c])
        {
            xor_arr[u] ^= dfs1(c);
        }
    }
    return xor_arr[u];
}

int dfs2(int u)
{
    vis[u] = true;
    int tmp = val[u];
    for (auto c : adj[u])
    {
        if (!vis[c])
        {
            tmp ^= dfs2(c);
        }
    }
    if (tmp == xor_arr[0])
    {
        cnt++;
        tmp = 0;
    }
    return tmp;
}

signed
main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, k;
        cin >> n >> k;
        REP(i, 0, n)
        {
            cin >> val[i];
            vis[i] = false;
        }
        REP(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs1(0);
        REP(i, 0, n)
        {
            vis[i] = false;
        }
        bool ans = false;
        if (xor_arr[0] == 0)
        {
            ans = true;
        }
        else
        {
            dfs2(0);
            if (cnt >= 2 && k != 2)
            {
                ans = true;
                /* code */
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
        cnt = 0;
        REP(i, 0, n)
        {
            adj[i].clear();
            xor_arr[i] = val[i] = 0;
        }
    }
}