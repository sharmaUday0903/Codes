// author : Uday Sharma
// 2022-11-10 21:36:27
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

void solve()
{
    int k;
    cin >> k;
    int n = 1 << k;
    string s;
    cin >> s;
    vi dp(2 * n);
    REP(i, 0, n)
    {
        dp[i + n] = 1;
    }
    REPREV(i, 0, n)
    {
        dp[i] = (s[n - 1 - i] == '0') ? dp[2 * i + 1] : (s[n - 1 - i] == '1') ? dp[2 * i]
                                                                              : dp[2 * i] + dp[2 * i + 1];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u;
        char c;
        cin >> u >> c;
        u--;
        s[u] = c;
        for (int  i = n-1-u; i; i/=2)
        {
               dp[i] = (s[n - 1 - i] == '0') ? dp[2 * i + 1] : (s[n - 1 - i] == '1') ? dp[2 * i] : dp[2 * i] + dp[2 * i + 1];
        }
        cout<<dp[1]<<endl;
        
    }
}
signed main()
{
    fast;
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}