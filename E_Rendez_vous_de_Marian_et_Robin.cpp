// 2024-09-23 10:49:28
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
const int MOD = 1e9 + 7;
int rootn(int x, int y)
{
    return ceil(log(x) / log(y));
}
bool sortbysec(pii &a, pii &b)
{
    return a.s < b.s;
}
bool sortbyfirstdesc(pii &a, pii &b)
{
    return a.f > b.f;
}
bool sortbysecdesc(pii &a, pii &b)
{
    return a.s > b.s;
}
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
    return power(n, mod - 2, mod) % MOD;
}
// For solving union of segments from point xl to xr Use segment tree with lazy propogation to store
//  number of segements that have point i for leaf and other intermediate nodes for minimum of them
// at last use lazy porpogation to update a segment from xl to xr
const int maxl = 2e5 + 5;
bool isprime[maxl];
int fact[maxl];
void sieve()
{
    memset(isprime, true, sizeof(isprime));

    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i < maxl; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < maxl; j += i)
                isprime[j] = false;
        }
    }
}
void inifact()
{
    fact[0] = 1;
    fact[1] = 1;
    REP(i, 2, maxl)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
}
vector<int> dijkstra(int s, vector<int> &d1, vector<int> &d2, vector<vpi> &adj, unordered_map<int, int> horse)
{
    int n = adj.size();
    d1.assign(n, INF);
    d2.assign(n, INF);

    d1[s] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    if (horse[s] == 1)
        pq.push({0, {s, 1}});
    else
        pq.push({0, {s, 0}});
    while (!pq.empty())
    {
        long long dis = pq.top().first;
        int u = pq.top().second.f;
        int x = pq.top().second.s;

        pq.pop();
        if (x == 0)
        {
            if (dis > d1[u])
                continue;
        }
        else
        {
            if (dis > d2[u])
                continue;
        }

        for (auto pp : adj[u])
        {
            int v = pp.f;
            int w = pp.s;
            long long ndis = w + dis;
            if (x == 1)
                ndis = dis + w / 2;
            if (x == 0)
            {
                if (d1[v] > ndis)
                {
                    d1[v] = ndis;
                    pq.push({ndis, {v, x}});
                }
            }
            else
            {
                if (d2[v] > ndis)
                {
                    d2[v] = ndis;
                    pq.push({ndis, {v, x}});
                }
            }

            if (x == 0 && horse[v] == 1)
            {
                ndis = w + dis;
                if (d2[v] > ndis)
                {
                    d2[v] = ndis;
                    pq.push({ndis, {v, 1}});
                }
            }
        }
    }
    vi d(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = min(d1[i], d2[i]);
    }
    return d;
}
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    unordered_map<int, int> horse;
    REP(i, 0, h)
    {
        int x;
        cin >> x;
        horse[x - 1] = 1;
    }
    vector<vpi> adj(n);
    REP(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vi ddd1;
    vi ddd2;
    vi d1 = dijkstra(0, ddd1, ddd2, adj, horse);
    vi d2 = dijkstra(n - 1, ddd1, ddd2, adj, horse);
    // for (auto c : d1)
    //     cout << c << " ";
    // cout << endl;
    // for (auto c : d2)
    //     cout << c << " ";
    // cout << endl;
    int ans = INF;
    REP(i, 0, n)
    {
        if (d1[i] != INF && d2[i] != INF)
        {
            int p = max(d1[i], d2[i]);
            ans = min(ans, p);
        }
    }
    if (ans == INF)
        ans = -1;
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