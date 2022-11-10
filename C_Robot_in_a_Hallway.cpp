// author : Uday Sharma
// 2022-10-27 22:22:16
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
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        int ans = inf, cells = 2;
        vector<vi> v(2, vi(n));
        vi clk(n, 0), anti_clk(n, 0);

        REP(i, 0, 2)
        {
            REP(j, 0, n)
            {
                cin >> v[i][j];
                v[i][j]++;
            }
        }
        v[0][0] = 0;
        clk[n - 1] = max(v[0][n - 1] + 1, v[1][n - 1]);
        anti_clk[n - 1] = max(v[0][n - 1], v[1][n - 1] + 1);

        REPREV(i, 0, n - 1)
        {
            cells += 2;
            clk[i] = max({clk[i + 1] + 1, v[0][i] + cells - 1, v[1][i]});
            anti_clk[i] = max({anti_clk[i + 1] + 1, v[0][i], v[1][i] + cells - 1});
        }
        int curr_time = -1;
        for (int i = 0; i < n; i++, cells -= 2)
        {
            if (i & 1)
            {
                ans = min(ans, max(curr_time + cells, anti_clk[i]));

                curr_time = max(curr_time + 1, v[1][i]);
                curr_time = max(curr_time + 1, v[0][i]);
            }
            else
            {
                ans = min(ans, max(curr_time + cells, clk[i]));

                curr_time = max(curr_time + 1, v[0][i]);
                curr_time = max(curr_time + 1, v[1][i]);
            }
        }
        cout<<ans<<endl;
    }
}