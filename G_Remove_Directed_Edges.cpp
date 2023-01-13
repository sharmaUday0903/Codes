// author : Uday Sharma
// 2022-12-18 14:18:10
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
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    vector<vi> rev_adj(n + 1);
    vi indegree(n + 1, 0);
    vi outdegree(n + 1, 0);
    REP(i, 1, m + 1)
    {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        outdegree[u]++;
        adj[u].pb(v);
        rev_adj[v].pb(u);
    }
    queue<int> q;
    vi topo;
    int ans=0;
    topo.pb(0);
    REP(i, 1, n + 1)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int tp = q.front();
        q.pop();
        topo.pb(tp);
        for (auto x : adj[tp])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    vi dp(n + 1, 0);
    REP(i, 1, n + 1)
    {
        int curr = topo[i];
        vi vec;
        bool found = false;
        int val = 1;
        for (auto x : rev_adj[curr])
        {
            if (adj[x].size() == 1)
            {
                found = true;
                continue;
            }
            vec.pb(dp[x]);
        }
        sortv(vec);
        if (found)
        {
            if (vec.size() > 0)
            {
                val = vec.back() + 1;
            }
        }
        else
        {
            if (vec.size() <= 1)
            {
                val = 1;
            }
            else
            {
                val = vec.back() + 1;
            }
        }
        dp[curr] = val;
        ans = max(ans, dp[curr]);
    }
    cout<<ans<<endl;
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}