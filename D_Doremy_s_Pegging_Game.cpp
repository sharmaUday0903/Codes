// author : Uday Sharma
// 2022-11-26 21:07:14
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
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define inf 1000000000000000005
#define int long long int
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

void solve()
{
    int n, p;
    cin >> n >> p;
    int ans = 0;
    int cnt = 1;
    int y = (n * (n - 3)) / 2;
    if (y + 1 < n)
    {
        REPREV(i, y + 1, n + 1)
        {
            int pp = (cnt * i) % p;
            ans = (ans + pp) % p;
            cnt = pp;
        }
        cout << ans << endl;
    }
    else
    {
        REPREV(i, n , y+2)
        {
            int pp = (cnt * i) % p;
            ans = (ans + pp) % p;
            cnt = pp;
        }
        cout << ans << endl;
    }
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}