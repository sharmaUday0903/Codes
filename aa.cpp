// author : Uday Sharma
// 2022-11-09 22:21:57
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
    multiset<int> m1, m2;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
        m1.insert(a[i]);
        m2.insert(a[i]);
    }
    int ans1 = 0;
    REP(i, 0, n - 1)
    {
        int p = a[i];
        auto qq = *m1.begin();
        int q = qq;
        while (p > q)
        {
            p = sqrt(p);
            ans1++;
        }
        m1.erase(m1.find(a[i]));
    }
    int ans2 = 0;
    REPREV(i, 1, n)
    {
        int p = a[i];
        auto qq = *m2.rbegin();
        int q = qq;
        if (p == 1)
        {
            ans2 = INT64_MAX;
            break;
        }

        while (p < q)
        {
            p = (p) * (p);
            ans2++;
        }
        m2.erase(m2.find(a[i]));
    }
    int ans = min(ans1, ans2);
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