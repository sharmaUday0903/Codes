// 2023-12-19 19:49:25
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
int gp(int p, int e)
{
    int nr = (power(p, e + 1, MOD) - 1 + MOD) % MOD;
    int dri = inversemod(p - 1, MOD);
    return (nr * dri) % MOD;
}
void solve()
{
    int n;
    cin >> n;
    vi prime(n);
    vi exp(n);
    REP(i, 0, n)
    cin >> prime[i] >> exp[i];
    int NOD = 1;
    REP(i, 0, n)
    NOD = (NOD * (exp[i] + 1)) % MOD;

    int SOD = 1;
    REP(i, 0, n)
    SOD = (SOD * gp(prime[i], exp[i])) % MOD;

    int MODD = 1;
    bool odd = 0;
    int POO;
    REP(i, 0, n)
    {
        if (exp[i] % 2 == 1)
        {
            odd = 1;
            POO = i;
        }
    }
    if (odd)
    {
        int OE = 1;
        REP(i, 0, n)
        {
            if (i == POO)
            {
                OE = (OE * (exp[i] + 1) / 2) % (MOD - 1);
            }
            else
                OE = (OE * (exp[i] + 1)) % (MOD - 1);
        }
        REP(i, 0, n)
        {
            MODD = (MODD * power(prime[i], (exp[i] * OE) % (MOD - 1), MOD)) % MOD;
        }
    }
    else
    {
        int OE = 1;
        REP(i, 0, n)
        {

            OE = (OE * (exp[i] + 1)) % (MOD - 1);
        }
        REP(i, 0, n)
        {
            MODD = (MODD * power(prime[i], ((exp[i] / 2) * OE) % (MOD - 1), MOD)) % MOD;
        }
    }

    cout << NOD << " " << SOD << " " << MODD << endl;
}

signed main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}