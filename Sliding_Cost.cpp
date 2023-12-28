// 2023-11-03 00:20:38
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
    return power(n, mod - 2) % MOD;
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    if (k == 1)
    {
        for (auto c : a)
            cout << 0 << " ";
        return;
    }

    if (k == 2)
    {
        REP(i, 1, n)
        {
            cout << abs(a[i - 1] - a[i]) << " ";
        }
        return;
    }
    int sum1 = 0, sum2 = 0;
    set<pair<int, int>> l, r;
    vpi temp;
    REP(i, 0, k)
    {
        temp.pb({a[i], i});
    }
    sortv(temp);
    REP(i, 0, (k + 1) / 2)
    {
        l.insert(temp[i]);
        sum1 += temp[i].f;
    }
    REP(i, (k + 1) / 2, k)
    {
        r.insert(temp[i]);
        sum2 += temp[i].f;
    }
    int med = l.rbegin()->first;
    int p = l.size() * med - sum1 + sum2 - r.size() * med;
    cout << p << " ";
    REP(i, k, n)
    {
        if (l.find({a[i - k], i - k}) != l.end())
        {
            l.erase({a[i - k], i - k});
            sum1 -= a[i - k];
        }
        else
        {
            r.erase({a[i - k], i - k});
            sum2 -= a[i - k];
        }
        if (l.rbegin()->first < a[i])
        {
            r.insert({{a[i], i}});
            sum2 += a[i];
        }
        else
        {
            l.insert({a[i], i});
            sum1 += a[i];
        }
        while (l.size() < (k + 1) / 2)
        {
            pii x = *r.begin();

            r.erase(x);
            sum2 -= x.first;
            l.insert(x);
            sum1 += x.first;
        }
        while (r.size() < (k) / 2)
        {
            pii x = *l.rbegin();
            l.erase(x);
            sum1 -= x.f;
            r.insert(x);
            sum2 += x.f;
        }
        int med = l.rbegin()->first;
        int p = l.size() * med - sum1 + sum2 - r.size() * med;
        cout << p << " ";
    }
}

signed main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}