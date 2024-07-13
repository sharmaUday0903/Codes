// 2024-03-14 20:25:23
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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m), c(k);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    REP(i, 0, m)
    {
        cin >> b[i];
    }
    REP(i, 0, k)
    {
        cin >> c[i];
    }
    multiset<int> s;
    REP(i, 0, n - 1)
    {
        s.insert(a[i + 1] - a[i]);
    }
    int p = *s.rbegin();
    s.erase(s.find(p));
    int q = -1;
    if (s.size())
        q = *s.rbegin();
    // if (s.size())
    // {
    //     int q = *s.rbegin();
    //     s.insert(p);
    //     if (q * 2 >= p)
    //     {
    //         cout << q << endl;
    //         return;
    //     }
    // }
    int val1, val2;
    REP(i, 0, n - 1)
    {
        if ((a[i + 1] - a[i]) == p)
        {
            val2 = a[i + 1];
            val1 = a[i];
            break;
        }
    }
    sortv(b);
    sortv(c);
    int val3 = (val1 + val2) / 2;
    // cout<<val3<<endl;
    int ans = p;
    REP(i, 0, m)
    {

        int p = val3 - b[i];
        if (p < 0)
        {
            int r = b[i] + c[0];
            int p1 = val2 - r;
            int p2 = r - val1;
            if (p1 >= 0 && p2 >= 0)
            {
                int y = max(p1, p2);
                ans = min(ans, y);
            }
        }
        else
        {
            int q = lower_bound(c.begin(), c.end(), p) - c.begin();
            if (q <= (k - 1))
            {
                int r = b[i] + c[q];
                int p1 = val2 - r;
                int p2 = r - val1;
                if (p1 >= 0 && p2 >= 0)
                {
                    int y = max(p1, p2);
                    ans = min(ans, y);
                }
            }
            q--;
            if (q>=0)
            {
                int r = b[i] + c[q];
                int p1 = val2 - r;
                int p2 = r - val1;
                if (p1 >= 0 && p2 >= 0)
                {
                    int y = max(p1, p2);
                    ans = min(ans, y);
                }
            }
        }
    }
    ans=max(ans,q);
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