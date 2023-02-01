// author : Uday Sharma
// 2023-01-25 20:42:55
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
    int n, m;
    cin >> n >> m;
    vi a(n);
    map<int, int> w;
    REP(i, 0, n)
    {
        cin >> a[i];
        w[a[i]]++;
    }
    vi b(m);
    REP(i, 0, m)
    {
        cin >> b[i];
        b[i]--;
    }
    int ans = m;
    vi v;
    for (auto c : w)
        v.pb(c.s);
    sortrev(v);

    if (m > v.size())
    {
        int h = m / v.size();
        int g = m % v.size();
        REP(i, 0, v.size())
        {
            v[i] -= h;
        }
        REP(i, 0, g)
        {
            v[i]--;
        }
        sortrev(v);
        REP(i, v.size(), m)
        b[i]++;
        sortrev(b);
        REP(i, 0, v.size())
        {
            ans += min(v[i], b[i]);
        }
        cout << ans << endl;
        return;
    }
    REP(i, 0, m)
    v[i]--;
    REP(i, 0, m)
    {
        ans += min(v[i], b[i]);
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