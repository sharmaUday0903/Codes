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

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        int a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int ans = 1e18;
        int p = *max_element(a, a + n);
        for (auto need : {p, p + 1})
        {
            int l = 0;
            int r = 1e18;
            int res = -1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                int cnt1 = (mid + 1) / 2;
                int cnt2 = mid - cnt1;
                int need1 = 0;
                REP(i, 0, n)
                {
                    int cur = (need - a[i]) / 2;
                    if ((need - a[i]) % 2 == 1)
                    {
                        need1++;
                        /* code */
                    }
                    if (cnt2 >= cur)
                    {
                        cnt2 -= cur;
                    }
                    else
                    {
                        cur -= cnt2;
                        cnt2 = 0;
                        need1 += cur * 2;
                    }
                }
                if (need1 <= cnt1)
                {
                    res = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            ans = min(ans, res);
        }
        cout << ans << endl;
    }
}