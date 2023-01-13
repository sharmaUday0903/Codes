// author : Uday Sharma
// 2022-12-14 20:05:54
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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    REP(i, 0, n)
    {
        cin >> b[i];
    }
    int N = 1e5 + 5;
    vector<int> m(N + 1, -1);
    REP(i, 0, n)
    {
        if (m[a[i]] == -1)
        {
            m[a[i]] = b[i];
        }
        else
        {
            m[a[i]] = min(m[a[i]], b[i]);
        }
    }
    vi aa;
    for (auto c : m)
    {
        if (c != -1)
        {
            /* code */
            aa.pb(c);
        }
    }
    sortv(aa);
    if (aa.size() < k)
    {
        // cout << aa.size() << endl;
        cout << -1 << endl;
        return;
        /* code */
    }

    int ans = 0;

    REP(i, 0, k)
    ans += aa[i];
    cout << ans << endl;
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