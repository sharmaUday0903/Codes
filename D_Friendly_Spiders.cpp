// author : Uday Sharma
// 2023-01-13 22:10:52
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
#define vvi vector<vi>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int
const int MOD = 1e9 + 7;
int power(int x, int y)
{
    int res = 1;
    while (y)
    {
        if (y % 2)
        {
            res = res * x;
        }
        y = y >> 1;
        x = x * x;
    }
    return res;
}
int power(int x, int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
int inversemod(int n, int mod)
{
    return power(n, mod - 2) % MOD;
}
const int maxn = 3e5 + 1;
vi spf(maxn, 0);
void sieve()
{
    spf[1] = 1;
    REP(i, 2, maxn)
    {
        if (!spf[i])
        {
            spf[i] = i;
            for (int j = i * i; j < maxn; j += i)
            {
                if (!spf[j])
                    spf[j] = i;
            }
        }
    }
}
void solve()
{
    int n, src, tar;
    cin >> n;
    vi v(n), dis(2 * maxn, -1), par(2 * maxn, -1);
    vvi adj(2 * maxn);

    REP(i, 0, n)
    cin >> v[i];
    cin >> src >> tar;
    src--;
    tar--;
    REP(i, 0, n)
    {
        while (spf[v[i]] > 1)
        {
            adj[i].pb(maxn + spf[v[i]]);
            adj[maxn + spf[v[i]]].pb(i);

            v[i] /= spf[v[i]];
        }
    }
    queue<int> q;
    q.push(src);
    dis[src] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto child : adj[curr])
        {
            if (dis[child] == -1)
            {
                par[child] = curr;
                dis[child] = dis[curr] + 1;
                q.push(child);
            }
        }
    }
    if (dis[tar] == -1)
    {
        cout << -1 << endl;
        return;
    }
    int node=tar;
    vi path;
    while (node!=-1)
    {
        if(node<n)path.pb(node);
        node=par[node];
    }
    reverse(path.begin(),path.end());
    cout<<(dis[tar]+1)/2<<endl;
    for(auto c:path)cout<<c+1<<" ";
    
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin >> t;
    sieve();
    while (t--)
    {
        solve();
    }
}