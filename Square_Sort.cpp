// author : Uday Sharma
// 2022-11-09 21:30:59
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

const int N = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    int m[n+5][17];
    REP(i, 0, n)
    {
        m[i][0] = a[i];
    }
    REP(k, 1, 17)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {
            m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }
    int q[n+5][17];
    REP(i, 0, n)
    {
        q[i][0] = a[i];
    }
    REP(k, 1, 17)
    {
        for (int i = 0; i + (1 << k) - 1 < n; i++)
        {
            q[i][k] = max(q[i][k - 1], q[i + (1 << (k - 1))][k - 1]);
        }
    }

    int ans1 = 0;
    REP(i, 0, n - 1)
    {
        int l = i + 1;
        int r = n - 1;
        int length = r - l + 1;
        int kk = 0;
        while ((l << (kk + 1)) <= length)
        {
            kk++;
        }
        int aa = min(m[l][kk], m[r - (1 << kk) + 1][kk]);
        int ee=a[i];
        while (ee>aa)
        {
            ee=sqrt(ee);
            ans1++;
        }

    }
    int ans2 = 0;
    REPREV(i, 1, n )
    {
        int l = 0;
        int r = i - 1;
        int length = r - l + 1;
        int kk = 0;
        while ((l << (kk + 1)) <= length)
        {
            kk++;
        }
        int aa = max(q[l][kk], q[r - (1 << kk) + 1][kk]);
        int ee=a[i];
        while (ee<aa)
        {
            ee*=ee;
            ans2++;
        }

    }
    int ans=min(ans1,ans2);
    cout<<ans<<endl;
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