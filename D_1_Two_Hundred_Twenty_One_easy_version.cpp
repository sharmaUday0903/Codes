// author : Uday Sharma
// 2022-11-04 19:37:12
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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi dp(n);
    REP(i, 0, n)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '+')
                dp[i] = 1;
            else
                dp[i] = -1;
        }
        else
        {
            if (s[i] == '-')
                dp[i] = 1;
            else
                dp[i] = -1;
        }
    }
    vi prefsum(n + 1, 0);
    REP(i, 0, n)
    {
        prefsum[i + 1] = prefsum[i] + dp[i];
    }
    REP(i, 0, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        if (prefsum[r] - prefsum[l] == 0)
        {
            cout << 0 << endl;
        }
        else if ((r - l) % 2 == 1)
        {
            cout << 1 << endl;
            /* code */
        }
        else
            cout << 2 << endl;
    }
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