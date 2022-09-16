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
#define int long long int

bool pal(int h)
{
    string s = to_string(h);
    string y = s;
    reverse(y.begin(), y.end());
    return (y == s);
}
const int md = 1e9 + 7;
const int N = 4e4 + 1;
const int M = 500;
vector<int> isPal(N, 0);
vi pp;
vector<vector<int>> dp(N, vector<int>(M, 0));
void preCompute()
{
    REP(i, 1, isPal.size())
    {
        if (pal(i))
        {
            isPal[i] = 1;
            pp.pb(i);
        }
        else
        {
            isPal[i] = 0;
        }
    }
    REP(i, 0, M)
    {
        dp[0][i] = 1;
    }
    REP(i, 1, isPal.size())
    {
        REP(j, 0, M)
        {
            if (j == 0)
            {

                dp[i][j] += dp[i - 1][j];
            }
            else if (i - pp[j] >= 0)
            {
                dp[i][j] += dp[i - pp[j]][j] + dp[i][j - 1];
            }
            else
                dp[i][j] = dp[i][j - 1];
            dp[i][j] %= md;
        }
    }
}

signed main()
{
    fast;
    preCompute();
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        cout << dp[n][M - 1] << endl;
    }
}