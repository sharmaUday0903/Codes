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

vi convert(1001);
void ini()
{

    convert[0] = 0;
    convert[1] = 0;
    convert[2] = 1;
    // for (int i = 3; i <= 1000; i++)
    // {
    //     convert[i] = convert[i - 1] + 1;
    //     for (int j = 1; 2 * j <= i; j++)
    //     {
    //         int val1 = (i - j) / j;
    //         int val2 = val1 + 1;
    //         if ((i - j) / val1 == j)
    //             convert[i] = min(convert[i - j] + 1, convert[i]);
    //         if ((i - j) / val2 == j)
    //             convert[i] = min(convert[i - j] + 1, convert[i]);
    //     }
    // }
    REP(i, 3, 1001)
    {
        int cnt = 0;
        int cnt1 = 0;
        int p =i;
        while (p > 1)
        {
            if (p % 2 == 1)
            {
                cnt1++;
            }
            p /= 2;
            cnt++;
        }

        convert[i]=cnt1+cnt;
    }
}
signed main()
{
    fast;
    int t;
    cin >> t;
    ini();
    REP(i, 0, t)
    {
        int n, k;
        cin >> n >> k;
        int ttlcst = 0;
        int b[n], c[n];
        REP(i, 0, n)
        {
            cin >> b[i];

            b[i] = convert[b[i]];
            ttlcst += b[i];
        }
        REP(i, 0, n)
        {
            cin >> c[i];
        }
        if (ttlcst <= k)
        {
            int ans = 0;
            REP(i, 0, n)
            {
                ans += c[i];
            }
            // cout << ans << endl;
        }
        else
        {
            vector<vector<int>> dp(n + 1, vector<int>(k + 1));
            REP(i, 0, n + 1)
            {
                REP(j, 0, k + 1)
                {
                    if (i == 0)
                    {
                        dp[i][j] = 0;
                    }
                    else if (b[i - 1] <= j)
                    {
                        dp[i][j] = max(c[i - 1] + dp[i - 1][j - b[i - 1]], dp[i - 1][j]);
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            cout << dp[n][k] << endl;
        }
        // cout << convert[2] << endl;
    }
}