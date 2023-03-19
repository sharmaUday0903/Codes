// author : Uday Sharma
// 2023-02-01 20:16:51
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
    int n, m, d;
    cin >> n >> m >> d;
    vi a(n);
    map<int, int> ma;
    int ans = INT_MAX;
    REP(i, 0, n)
    {
        cin >> a[i];
        ma[a[i]] = i;
    }
    vi b(m);
    REP(i, 0, m)
    cin >> b[i];
    REP(i, 0, m - 1)
    {
        int p = ma[b[i]];
        int q = ma[b[i + 1]];
        if (q < p)
        {
            cout << 0 << endl;
            return;
        }
        int w = q - p;
        // int u=p+d;
        // if(q>u){
        //      cout << 0 << endl;
        //     return;
        // }
        ans = min(ans, q - p);
        if (d <= n - 2)
        {
            int y = d + 1 - w;
            ans = min(ans, y);
        }
        // if(u<=n-1)
        // {
        //     int y=u-q;
        //     ans=min(ans,y);
        // }
    }
    int zero=0;
    ans=max(ans,zero);
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