
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = INT_MAX;
    int cnt = m;
    while (m >= n)
    {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int p = m;
        while (p)
        {
            mx = max(mx, p % 10);
            mn = min(mn, p % 10);
            p/=10;
        }
        int tans = mx - mn;
        if (ans > tans)
        {
            ans =  tans;
            cnt = m;
        }
        if (ans == 0)
        {
            break;
        }
        m--;
    }
    cout << cnt << endl;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}