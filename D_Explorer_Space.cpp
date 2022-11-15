// author : Uday Sharma
// 2022-11-11 12:03:18
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

int n, m, k;
vector<vector<int>> wth, wtv;
int dp[505][505][25];

int recur(int x, int y, int t)
{
    if (x < 0 || y < 0 || x >= n | y >= m)
        return inf;
    if (t == 0)
    {
        return 0;
    }
    if (dp[x][y][t] != inf)
    {
        return dp[x][y][t];
    }
    else
    {
        if (y < m)
        {
            dp[x][y][t] = min(dp[x][y][t], recur(x, y + 1, t - 2) + 2 * wth[x][y]);
        }
        if (y >0)
        {
            dp[x][y][t] = min(dp[x][y][t], recur(x, y - 1, t - 2) + 2 * wth[x][y-1]);
        }
        if (x>0)
        {
            dp[x][y][t] = min(dp[x][y][t], recur(x-1, y, t - 2) + 2 * wtv[x-1][y]);
        }
        if (x<n)
        {
            dp[x][y][t] = min(dp[x][y][t], recur(x+1, y, t - 2) + 2 * wtv[x][y]);
        }
      
    }
    return dp[x][y][t];
}

void solve()
{
    cin >> n >> m >> k;
    wth.assign(n, vi(m));
    wtv.assign(n, vi(m));
    REP(i, 0, n)
    {
        REP(j, 0, m - 1)
        {
            cin >> wth[i][j];
        }
    }
    REP(i, 0, n - 1)
    {
        REP(j, 0, m)
        {
            cin >> wtv[i][j];
        }
    }
    REP(i, 0, 505)
    {
        REP(j, 0, 505)
        {
            REP(k, 0, 25)
            {
                dp[i][j][k] = inf;
            }
        }
    }
    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            if (k & 1)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << recur(i, j, k) << " ";
            }
        }
        cout << endl;
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