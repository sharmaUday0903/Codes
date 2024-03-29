// author : Uday Sharma
// 2023-01-18 23:43:29
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
    vi dp(m + 1, 0);
    REP(i, 0, n)
    {
        int x;
        cin >> x;
        dp[x]++;
    }
    vi a(m);
    REP(i, 0, m)
    cin >> a[i];
    REP(i, 2, m + 1)
    dp[i] += dp[i - 1];
    int ans = 0;
    REP(i, 1, m + 1)
    {
        int candies=0;
        REP(j,1,(m/i)+1)
        {
            int l = j*i;
            int r =min(m,(j+1)*i-1);
            candies+=(dp[r]-dp[l-1])*j;
        }
        ans=max(ans,candies*a[i-1]);
    }
    cout<<ans<<endl;
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