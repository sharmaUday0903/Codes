// author : Uday Sharma
// 2022-12-12 23:28:56
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
    int m;
    cin >> m;
    string a, b;
    cin >> a >> b;

    vector<bool> ok(2, true);
    int cnt = 0;
    REP(i, 0, m)
    {
        if (a[i] == 'B' && b[i] == 'B')
        {
            cnt++;
        }
        if (a[i] == 'W')
        {
            ok[cnt % 2] = false;
        }
        if (b[i] == 'W')
        {
            ok[1 - cnt % 2] = false;
        }
    }
    if (!ok[0] && !ok[1])
    {
        cout << "NO\n";
    }

    else
        cout << "YES\n";
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