// author : Uday Sharma
// 2023-01-13 21:21:23
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

void solve()
{
    int n, x;
    cin >> n >> x;
    vi a(65, 0), b(65, 0);
    int i = 0;
    int nn = n, xx = x;
    while (nn)
    {
        if (nn % 2 == 1)
        {
            a[i] = 1;
        }
        i++;
        nn /= 2;
    }
    i = 0;
    while (xx)
    {
        if (xx % 2 == 1)
        {
            b[i] = 1;
        }
        i++;
        xx /= 2;
    }
    bool u = true;
    REP(i, 0, 65)
    {
        if (b[i] == 1 && a[i] == 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    if (n == x)
    {
        cout << n << endl;
        return;
    }
    int in = -1;
    REPREV(i, 0, 65)
    {
        if (a[i] != b[i])
        {
            in = i;
            break;
        }
    }
    REP(i, 0, in)
    {
        if (b[i] == 1)
        {
            cout << -1 << endl;
            return;
        }
    }
    if (b[in + 1] == 1)
    {
        cout << -1 << endl;
        return;
    }
    vi c = b;
    c[in + 1] = 1;
    int ans = 0;
    REP(i, 0, 65)
    {
        if (c[i] == 1)
        {
            int p = power(2, i);
            ans += p;
        }
    }
    cout << ans << endl;
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