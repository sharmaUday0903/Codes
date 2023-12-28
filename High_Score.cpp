// 2023-11-06 11:53:14
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
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    vvi edges(m, vi(3));
    REP(i, 0, m)
    {
        cin >> edges[i][0];
        edges[i][0]--;
        cin >> edges[i][1];
        edges[i][1]--;
        adj[edges[i][0]].pb(edges[i][1]);
        cin >> edges[i][2];
    }
    vi dis(n, -1e18);
    dis[0] = 0;
    queue<int> q;
    vi vis(n, 0);
    REP(i, 0, n)
    {
        for (auto c : edges)
        {
            if (dis[c[0]] != -1e18)
                if (dis[c[1]] < dis[c[0]] + c[2])
                {
                    dis[c[1]] = max(dis[c[1]], dis[c[0]] + c[2]);
                    if (i == n - 1)
                    {
                        q.push(c[1]);
                        vis[c[1]] = 1;
                    }
                }
        }
        // for (auto c : dis)
        //     cout << c << " ";
        // cout
        //     << endl;
    }

    int x = -1;

    while (!q.empty())
    {
        int p = q.front();
        // cout << p << " ";
        q.pop();
                if (p == n - 1)
                {
                    x = n - 1;
                }
        for (auto c : adj[p])
        {
            if (!vis[c])
            {

                q.push(c);
                vis[c] = 1;
            }
        }
    }
    if (x != -1)
    {
        cout << -1 << endl;
        return;
    }
    cout << dis[n - 1];
}

signed main()
{
    fast;
    int t = 1;
    while (t--)
        solve();
}