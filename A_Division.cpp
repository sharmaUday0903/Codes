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
        int a, b;
        cin >> a >> b;
        vi v;
        int x = b;
        int ans = 1;
        REP(i, 2, sqrt(x) + 1)
        {
            if (x % i == 0)
            {
                v.pb(i);
                while (x % i == 0)
                {
                    x /= i;
                }
            }
        }
        if (x > 1)
        {
            v.pb(x);
        }
        for (auto r : v)
        {
            int x = a;
            int vv = 1;
            while ((b / r) % vv == 0)
            {
                vv *= r;
            }
            vv /= r;
            while (a % vv != 0)
            {
                vv /= r;
            }
            while (x % r == 0)
            {
                x /= r;
            }
            ans = max(ans, x * vv);
        }
        cout<<ans<<endl;
    }
}