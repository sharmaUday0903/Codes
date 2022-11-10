// author : Uday Sharma
// 2022-10-27 21:55:21
#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

#define f first
#define s second
#define inf 1000000000000000005
#define mp make_pair
#define pb push_back
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPREV(i, k, n) for (int i = n - 1; i >= k; i--)
#define pii pair<int, int>
#define vpi vector<pair<int, int>>
#define vi vector<int>
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.begin(), v.end(), greater<int>())
#define int long long int

signed main()
{
    fast;
    int n, l, k;
    cin >> n >> l >> k;
    vi d(n + 2, 0);
    vi a(n + 2, 0);
    vector<vi> dp(n + 5, vi(n + 5, inf));
    REP(i, 1, n + 1)
    {
        cin >> d[i];
    }
    REP(i, 1, n + 1)
    {
        cin >> a[i];
    }
    d[n + 1] = l;
    dp[1][0] = 0;
    REP(i, 2, n + 2)
    {
        REP(j, 0, k + 1)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + (d[i] - d[i - 1]) * a[i - 1];
                continue;
            }
            REPREV(prev, 1, i)
            {
                int remove = i - prev - 1;
                if (j >= remove)
                {
                    dp[i][j] = min(dp[i][j], dp[prev][j - remove] + (d[i] - d[prev]) * a[prev]);
                }
            }
        }
    }
    int ans=inf;
    REP(i,0,k+1)
    {
        ans=min(ans,dp[n+1][i]);

    }
    cout<<ans<<endl;
}