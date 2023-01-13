// author : Uday Sharma
// 2022-12-19 20:53:33
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
    vi a(n);
    REP(i, 0, n)
    cin >> a[i];
    /* code */
    int p = *max_element(a.begin(), a.end());
    if (n >= 4)
    {
        int ans = n * p;
        cout << ans << endl;
    }
    else
    {
        if (n == 2)
        {
            int ans1 = a[0] + a[1];
            int ans2 = 2 * abs(a[0] - a[1]);
            int ans = max(ans1, ans2);
            cout << ans << endl;
        }
        else
        {
            if (p == a[0] ||p== a[2])
            {
                int ans = p * 3;
                cout << ans << endl;
            }
            else
            {
                int ans1 = a[0] + a[1] + a[2];
                int ans2 = max(a[0], a[2]);
                ans2 *= 3;
                int ans3 = p - min(a[0], a[2]);
                ans3*=3;
                int ans=max({ans1,ans2,ans3});
                cout<<ans<<endl;
            }
        }
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