// author : Uday Sharma
// 2023-01-28 02:07:13
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
    int n;
    cin >> n;
    vvi v(n, vi(n - 1));
    REP(i, 0, n)
    {
        REP(j, 0, n - 1)
        {
            cin >> v[i][j];
        }
    }
    vi ans;
    map<int, int> m;
    REP(i, 0, n - 1)
    {
        REP(j, 0, n)
        {
            int p = v[j][i];
            m[p]++;
        }
        
        for (auto c : m)
        {

            if (c.s == n - 1)
            {
                ans.pb(c.f);
                m[c.f] = 0;
            }
        }
        if (i == n - 3)
        {
            for (auto c : m)
            {

                if (c.s == n-2)
                {
                    ans.pb(c.f);
                    m[c.f] = 0;
                    break;
                }
            }
        }
    }
    REP(i, 0, n)
    cout << ans[i] << " ";
    cout << endl;
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