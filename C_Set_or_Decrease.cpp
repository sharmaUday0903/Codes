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
        int n, k;
        cin >> n >> k;
        vi a(n);
        REP(i, 0, n)
        {
            cin >> a[i];
        }
        sortv(a);
        vi pref(n + 1);
        REP(i, 0, n)
        {
            pref[i + 1] = pref[i] + a[i];
        }
        int ans = 9e18;
        REP(t, 0, n)
        {
            int sum = pref[n - t] + a[0] * t;
            int cur = t;
            if (sum > k)
            {
                int diff = sum - k;
                cur += (diff + t) / (t + 1);
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
}