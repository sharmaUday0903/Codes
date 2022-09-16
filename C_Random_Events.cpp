
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
        int n, m;
        cin >> n >> m;
        long double a[n];
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        int r = -1;
        REPREV(i, 0, n)
        {
            if (a[i] == i + 1)
            {
            }
            else
            {
                r = i;
                break;
            }
        }
        long double l = 1;
        long double ans = l;
        REP(i, 0, m)
        {
            int aa;
            cin >> aa;
            long double g;
            cin >> g;
            if (aa <= r)
            {
            }
            else
            {
                ans *= (l - g);
            }
        }
        ans = l - ans;
        if (r == -1)
        {
            ans = l;
        }
        cout.precision(6);
        cout << fixed << ans << endl;
    }
}