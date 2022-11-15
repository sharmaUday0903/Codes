// author : Uday Sharma
// 2022-11-11 11:38:18
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

const int mod =998244353;

void solve()
{
    int n;
    cin >> n;
    vi dp(n+1);
    dp[0] = 1;
    REP(i, 1, n + 1)
    {
        for (int j = i; j <= n; j += i)
        {
            dp[j] += 1;
        }
    }
    int sum=0;
    REP(i,2,n+1)
    {
        sum=(sum+dp[i-1])%mod;
        dp[i]=(dp[i]+sum)%mod;
    }
    cout<<dp[n]<<endl;
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