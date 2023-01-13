// author : Uday Sharma
// 2022-11-22 02:44:46
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
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<array<int, 2>>> adj(n);
    REP(i, 1, n)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        adj[x].pb({y, z});
        adj[y].pb({x, z});
    }
    vi f(n);
    set<int> s;
    function<void(int, int, int)> dfs = [&](int x, int t, int p)
    {
        if (x != b)
            s.insert(f[x]);
        for (auto [y, z] : adj[x])
        {
            if (y==p||y==t)
            {
                continue;
            }
            f[y]=f[x]^z;
            dfs(y,t,x);
        }
    };
    f[a]=0;
    dfs(a,b,-1);
    auto t=s;
    s.clear();
    f[b]=0;
    dfs(b,-1,-1);
    for(auto x:s)
    {
        if (t.count(x))
        {
            cout<<"YES\n";
            return;
        }
        
    }
    cout<<"NO\n";
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