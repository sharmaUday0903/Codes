// author : Uday Sharma
// 2023-02-07 14:26:34
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
    n--;
    int ans1 = 1, ans2 = 0;
    int cnt = 2;
    int pai = 0;
    while (n)
    {
        if (pai == 0)
        {
            if (n >= cnt)
            {
                n -= cnt;
                ans2 += cnt;
            }
            else
            {
                ans2 += n;
                n = 0;
            }
            cnt++;
            if (n >= cnt)
            {
                n -= cnt;
                ans2 += cnt;
            }
            else
            {
                ans2 += n;
                n = 0;
            }
            cnt++;
            pai = 1 - pai;
        }
        else
        {
            if (n >= cnt)
            {
                n -= cnt;
                ans1 += cnt;
            }
            else
            {
                ans1 += n;
                n = 0;
            }
            cnt++;
            if (n >= cnt)
            {
                n -= cnt;
                ans1 += cnt;
            }
            else
            {
                ans1 += n;
                n = 0;
            }
            pai = 1 - pai;
            cnt++;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
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