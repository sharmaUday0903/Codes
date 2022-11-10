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

int power(int x, int y, int mod)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y)
    {
        if (y % 2)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

signed main()
{
    fast;
    int t;
    cin >> t;
    REP(i, 0, t)
    {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        set<int> s1, s2;
        vpi v;
        REP(i, 0, q)
        {
            int x, y;
            cin >> x >> y;
            v.pb(mp(x, y));
        }
        int p = 0;
        REPREV(i, 0, q)
        {
            
            if (s1.size() == n)
            {
                continue;
            }
            if (s2.size() == m)
            {
                continue;
            }
            if (s1.count(v[i].f) && s2.count(v[i].s)
            )
            {
                continue;
            }

            p++;
            s1.insert(v[i].first);
            s2.insert(v[i].second);
        }

        // int p = min(s1.size(), s2.size());
        int ans = power(k, p, 998244353);
        cout << ans << endl;
    }
}