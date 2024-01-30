// 2023-12-29 13:21:44
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
const int MOD = 998244353;
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
int ans2 = 1;
int cnt = 0;
void calc(vi &a, vpi &seg, vi &vis, int c)
{
    // cout << c << endl;
    cnt += 2;
    vis[c] = 1;
    map<int, int> last;
    for (int i = seg[c].f; i < seg[c].s; i++)
    {
        last[a[i]]++;
    }
    for (auto c : last)
    {

        if (c.s == 1 && vis[c.f] == 0)
        {
            calc(a, seg, vis, c.f);
        }
    }
    // return cnt;
}
void solve()
{
    int n;
    cin >> n;
    vi a(2 * n);
    REP(i, 0, 2 * n)
    cin >> a[i];
    int ans1 = 0;
    // int ans2 = 1;
    vi ch;
    int sum = 0;
    map<int, int> m;
    vpi seg(n + 1);
    REP(i, 0, 2 * n)
    {
        if (sum == 0)
            ch.pb(a[i]);
        if (m[a[i]] == 0)
        {
            sum += 1;
            seg[a[i]].f = i;
        }
        else
        {
            sum += -1;
            seg[a[i]].s = i;
        }
        m[a[i]] = 1;
    }
    ans1 = ch.size();
    ans2 = 1;
    vi vis(n + 1, 0);
    for (auto c : ch)
    {
        cnt = 0;
        calc(a, seg, vis, c);
        ans2 = (ans2 * cnt) % MOD;
    }
    cout << ans1 << " " << ans2 << endl;
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}