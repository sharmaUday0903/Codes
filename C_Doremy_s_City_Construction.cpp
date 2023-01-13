// author : Uday Sharma
// 2022-11-26 20:50:38
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
    int n;
    cin >> n;
    map<int, int> m;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    if (m.size() == 1)
    {
        cout << n / 2 << endl;
    }
    else
    {
        int ans = 0;
        sort(a,a+n);
        map<int, bool> mm;
        REP(i, 0, n)
        {
            int cnt1 = 0;
            if (mm[a[i]] == 0)
            {
                int p = i;
                int q = n - i - m[a[i]];
                q *= p;
                p *= m[a[i]];

                cnt1 += p + q;

                ans = max(cnt1, ans);
                mm[a[i]] = -1;
            }
        }
        cout << ans << endl;
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