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
        int a[3];
        int ans = 0;
        int cnt = 0;
        int cnt2 = 0;
        REP(i, 0, 3)
        {
            cin >> a[i];
            if (a[i] > 0)
            {
                ans++;
            }
        }
        sort(a, a + 3);
        reverse(a, a + 3);
        REP(i, 0, 2)
        {
            if (a[i] >= 2 && a[i + 1] >= 2)
            {
                ans++;
                a[i]--;
                a[i + 1]--;
            }
        }
        if (a[0] >= 2 && a[2] >= 2)
        {

            ans++;
        }

        cout << ans << endl;
    }
}