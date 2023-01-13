// author : Uday Sharma
// 2022-12-18 17:34:52
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
    int n, hh;
    cin >> n >> hh;
    vi a(n);
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    sortv(a);
    int ans = 0;
    REP(j, 0, 3)
    {
        vi v;
        if (j % 3 == 0)
        {
            v.pb(3);
            v.pb(2);
            v.pb(2);
        }
        else if (j % 3 == 1)
        {
            v.pb(2);
            v.pb(3);
            v.pb(2);
        }
        else
        {
            v.pb(2);
            v.pb(2);
            v.pb(3);
        }
        int h = hh;
        int cnt = 0;
        REP(i, 0, n)
        {
            if (a[i] < h)
            {
                cnt++;
                h += (a[i] / 2);
            }
            else
            {
                if (!v.empty())
                {
                    while (!v.empty() )
                    {
                        h *= v.back();
                        v.pop_back();
                        if (a[i] < h)
                        {
                            cnt++;
                            h += (a[i] / 2);
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
        }
        ans = max(ans, cnt);
    }
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