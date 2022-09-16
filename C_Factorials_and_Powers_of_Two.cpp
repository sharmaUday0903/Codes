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
    int fac[15];
    fac[0] = 1;
    REP(i, 1, 15)
    {
        fac[i] = fac[i - 1] * i;
    }
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n;
        cin >> n;
        int ans = 102;
        REP(s, 0, (1 << 14))
        {
            int m = n;
            REP(i, 0, 14)
            {
                if ((s >> i) & 1)
                {
                    m -= fac[i + 1];
                }
            }
            if (m >= 0)

            {
                ans = min<int>(ans, __builtin_popcount(s) + __builtin_popcountll(m));
            }
        }
        cout<<ans<<endl;
    }
}