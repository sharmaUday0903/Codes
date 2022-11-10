// author : Uday Sharma
// 2022-11-01 11:30:35
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

signed main()
{
    fast;
    int n;
    cin >> n;
    vi p(n);

    REP(i, 1, n)
    {
        cin >> p[i];
        p[i]--;
    }
    p[0] = -1;
    vi h(n, 1), dp(n);
    REPREV(i, 0, n)
    {
        dp[i] = max(dp[i], h[i]);
        if (i)
        {
            dp[p[i]] += dp[i];
            h[p[i]] = max(h[p[i]], h[i] + 1);
        }
    }
    cout<<dp[0]<<endl;
}