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

#define ub(v, idx, val) upper_bound(v.begin() + idx, v.end(), val)
#define lb(v, idx, val) lower_bound(v.begin() + idx, v.end(), val)

#define vvi vector<vi>
const double pi = 3.14159265358979323846;

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
vi convert(1001);
void ini()
{

    convert[0] = 0;
    convert[1] = 0;
    convert[2] = 1;
    for (int i = 3; i <= 1000; i++)
    {
        convert[i] = convert[i - 1] + 1;
        for (int j = 1; 2 * j <= i; j++)
        {
            int val1 = (i - j) / j;
            int val2 = val1 + 1;
            if ((i - j) / val1 == j)
                convert[i] = min(convert[i - j] + 1, convert[i]);
            if ((i - j) / val2 == j)
                convert[i] = min(convert[i - j] + 1, convert[i]);
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vi b(n), c(n);
    REP(i, 0, n)
    cin >> b[i];
    REP(i, 0, n)
    cin >> c[i];

    vi cst(n);

    int totalcst = 0;
    REP(i, 0, n)
    {

        cst[i] = convert[b[i]];
        totalcst += cst[i];
    }

    if (totalcst <= k)
    {
        int ans = 0;
        REP(i, 0, n)
        ans += c[i];
        cout << ans << "\n";
        return;
    }
    int ans = 0;
    // REP(i,0,n)
    // if(cst[i]==0)
    // {
    //     ans+=c[i];
    //     cst[i]=INT_MAX;
    // }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {

            if (i == 0)
                dp[i][j] = 0;
            else if (cst[i - 1] <= j)
                dp[i][j] = max(c[i - 1] + dp[i - 1][j - cst[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // REP(i,0,n+1)
    // {
    //     REP(j,0,k+1)
    //     cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    cout << dp[n][k] << "\n";
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    ini();
    while (t--)
        solve();
}