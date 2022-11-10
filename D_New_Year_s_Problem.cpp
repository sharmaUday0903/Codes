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
        int m, n;
        cin >> m >> n;
        vector<vi> a(m, vi(n));
        vi cnt;
        REP(i, 0, m)
        {
            REP(j, 0, n)
            {
                cin >> a[i][j];
            }
        }
        REP(i, 0, n)
        {
            vi v;
            REP(j, 0, m)
            {
                v.pb(a[j][i]);
            }
            sortv(v);
            cnt.pb(v[v.size() - 1]);
        }
        int p = *min_element(cnt.begin(), cnt.end());
        int left = 1;
        int right = p;
        int ans = 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            bool u = false;
            REP(i, 0, m)
            {
                int cntmid = 0;
                REP(j, 0, n)
                {
                    if (a[i][j] >= mid)
                    {
                        cntmid++;
                    }
                }
                if (cntmid >= 2)
                {
                    u = true;
                    break;
                }
            }
            if (u)
            {
                left = mid + 1;
                ans = max(left - 1, ans);
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << ans << endl;
    }
}